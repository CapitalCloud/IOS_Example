//
//  CapitalCloudAPIClient.h
//  CapitalCloudClient
//
//  Created by julien on 13-12-10.
//  Copyright (c) 2013年 capitalCloud. All rights reserved.
//
/*!
 @header CapitalCloudAPIClient api交互
 @abstract APP和首云sdk的交互主要通过CapitalCloudAPIClient类,首先需要生成CapitalCloudAPIClient对象.
 @author capitalCloud
 @version 1.0.4
 */
#import <Foundation/Foundation.h>
#import "CapitalCloudBasicMethod.h"
#import "CapitalCloudPostMethod.h"
#import "CapitalCloudMultipartMethod.h"
#import "CapitalCloudVideo.h"
#import "CapitalCloudEntriesHandler.h"
#import "CapitalCloudCategoriesHandler.h"
@class HTTPServer;
@class CapitalCloudEntriesHandler;

/*!
 @class
 @abstract APP和首云sdk的交互主要通过CapitalCloudAPIClient类,首先需要生成CapitalCloudAPIClient对象.
 */

@interface CapitalCloudAPIClient : NSObject

/*!
 @property
 @abstract token信息
 */
@property(readwrite, strong) NSString *token;

@property(readwrite, strong) HTTPServer *httpServer;

/*!
 @property
 @abstract api交互地址，默认为：http://api.video.capitalcloud.net
 */
@property(readwrite, strong) NSString *apiUrl;

@property(readwrite, strong) NSString *scope;

@property(readwrite, strong) NSString *rootPath;

@property(readwrite) UInt16 port;

/*!
 @property
 @abstract 视频管理,用于管理视频的增删改查；
 */
@property(readonly, strong) CapitalCloudEntriesHandler *entriesHandler;

/*!
 @property
 @abstract 分类管理，用于分类信息的增删改查；
 */
@property(readonly, strong) CapitalCloudCategoriesHandler *categoriesHandler;

/*!
 @method
 @abstract 通过token生成CapitalCloudAPIClient实例；
 @discussion 通过token生成CapitalCloudAPIClient实例，务必保证token的有效性；
 @param token token信息；
 @result CapitalCloudAPIClient实例；
 */
- (instancetype) initWithToken:(NSString *)token;

/*!
 @method
 @abstract 接口调用；
 @discussion 接口调用；
 @param methodUrl 基本路径如：http://api.video.capitalcloud.net/
 @param parameters 参数；
 @param error 错误信息；
 @param get get 或者是 post；
 @result 接口调用结果；
 */
- (id) call:(NSURL *) methodUrl with:(NSDictionary *) parameters error:(NSError **)error get:(BOOL) get;

/*!
 @method
 @abstract api接口调用；
 @discussion api接口调用(http://api.video.capitalcloud.net/)；
 @param methodName 调用api名称，如:players_getConfigurations；
 @param parameters 参数；
 @param error 错误信息；
 @result 接口调用结果；
 */
- (id) callAPI:(NSString *) methodName with:(NSDictionary *) parameters error:(NSError **) error;

/*!
 @method
 @abstract 视频上传；
 @discussion 视频上传接口；
 @param fileURL 上传视频的本地地址；
 @param parameters 参数；
 @result CapitalCloudHttpConnection；
 */
- (CapitalCloudHttpConnection *) uploadVideo:(NSURL *) fileURL withParamters:(NSDictionary *)parameters;

@end
