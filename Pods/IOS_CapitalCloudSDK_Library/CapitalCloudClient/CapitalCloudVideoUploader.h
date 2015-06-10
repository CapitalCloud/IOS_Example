//
//  CapitalCloudVideoUploader.h
//  CapitalCloudClient
//
//  Created by julien on 14-1-9.
//  Copyright (c) 2014年 capitalCloud. All rights reserved.
//

/*!
 @header CapitalCloudVideoUploader
 @abstract  视频上传类；
 @author capitalCloud
 @version 1.3.2
 */
#import <Foundation/Foundation.h>
#import "CapitalCloudAPIClient.h"
#import "CapitalCloudHttpConnection.h"

@protocol CapitalCloudVideoUploaderDelegate;

/*!
 @class
 @abstract 主要用于视频上传，并提供相关接口；
 */
@interface CapitalCloudVideoUploader : NSOperation<CapitalCloudHttpConnectionDelegate,NSMutableCopying>

/*!
 @property
 @abstract CapitalCloudVideoUploaderDelegate，上传状态改变时调用的回调
 被取消
 - (void)uploadCanceled:(CapitalCloudHttpConnection *)connection;
 完成
 - (void)uploadFinished:(NSHTTPURLResponse *)response;
 失败
 - (void)uploadFailed:(NSError *)error InResponse:(NSHTTPURLResponse *)response;
 上传进度
 - (void)uploadDidUpdate:(double) progress;
 */
@property(nonatomic, strong) id<CapitalCloudVideoUploaderDelegate> delegate;

/*!
 @property
 @abstract 上传的视频文件地址；
 */
@property(nonatomic, strong) NSURL *fileURL;

/*!
 @property
 @abstract 当前状态；
 */
@property(nonatomic, strong) NSString *status;

/*!
 @property
 @abstract APP和石山sdk的交互主要通过CapitalCloudAPIClient类,首先需要生成CapitalCloudAPIClient对象.
 */
@property(nonatomic, strong) CapitalCloudAPIClient *apiClient;

/*!
 @method
 @abstract	取消当前下载；
 @discussion	取消当前下载；
 */
-(void)cancelUploadVideo;

/*!
 @method
 @abstract	初始化；
 @discussion	初始化视频上传类的实例；
 
 @param file [IN|OUT] 包含视频地址的NSURL实例；
 @param client [IN|OUT] apiClient
 @param uploadDelegate [IN|OUT] 上传代理；
 
 @result 返回CapitalCloudVideoUploader实例；
 */
- (instancetype) initWithFile:(NSURL *) file apiClient:(CapitalCloudAPIClient *)client paramters:(NSDictionary *)parameters delegate:(id<CapitalCloudVideoUploaderDelegate>) uploadDelegate;

@end

@protocol CapitalCloudVideoUploaderDelegate <NSObject>
@optional
- (void)uploadCanceled:(CapitalCloudHttpConnection *)connection;
- (void)uploadFinished:(NSHTTPURLResponse *)response;
- (void)uploadFailed:(NSError *)error InResponse:(NSHTTPURLResponse *)response;
- (void)uploadDidUpdate:(double) progress;
@end