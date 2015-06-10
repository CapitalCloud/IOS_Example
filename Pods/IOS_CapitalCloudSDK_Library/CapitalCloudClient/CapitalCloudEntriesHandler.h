//
//  CapitalCloudEntriesHandler.h
//  CapitalCloudClient
//
//  Created by julien on 14-3-28.
//  Copyright (c) 2014年 capitalCloud. All rights reserved.
//

/*!
 @header CapitalCloudEntriesHandler
 @abstract 视频管理类，由CapitalCloudAPIClient保有唯一实例，负责视频的增删改查；
 @author capitalCloud
 @version 1.3.2
 */

#import <Foundation/Foundation.h>
#import "CapitalCloudHttpConnection.h"
#import "CapitalCloudVideo.h"
#import "CapitalCloudVideoPlayInfor.h"
#import "CapitalCloudVideoPlayerConfigurations.h"

@class CapitalCloudAPIClient;
@class CapitalCloudVideoPlayInfor;

/*!
 @class
 @abstract 视频管理类，由CapitalCloudAPIClient保有唯一实例，负责视频的增删改查；
 */
@interface CapitalCloudEntriesHandler : NSObject

/*!
 @property
 @abstract APP和石山sdk的交互主要通过CapitalCloudAPIClient类,首先需要生成CapitalCloudAPIClient对象.
 */
@property(readwrite, weak) CapitalCloudAPIClient *apiClient;

/*!
 @method
 @abstract 通过apiClient生成CapitalCloudEntriesHandler实例；
 @discussion 通过apiClient生成CapitalCloudEntriesHandler实例；
 @param apiClient CapitalCloudAPIClient实例；
 @result CapitalCloudEntriesHandler实例；
 */
-(instancetype) initWithAPIClient:(CapitalCloudAPIClient *)apiClient;

/*!
 @method
 @abstract 视频上传；
 @discussion 视频上传接口；
 @param fileURL 上传视频的本地地址；
 @param parameters 参数；
 @result CapitalCloudHttpConnection；
 */
- (CapitalCloudHttpConnection *) upload:(NSURL *) fileURL withParamters:(NSDictionary *)parameters;

/*!
 @method
 @abstract 获取视频；
 @discussion 获取视频列表；
 @param filter [IN|OUT] 限制条件；
 @param category_id [IN|OUT] 分类id;
 @param order_by [IN|OUT] 排序方式
 @param start [IN|OUT] 开始位置；
 @param max_size [IN|OUT] 最大数量；
 @param error [IN|OUT] 错误信息
 @result NSDictionary；
 */
- (NSDictionary *) listWithFilter: (NSDictionary *)filter InCatetory:(NSString *) category_id OrderBy:(NSString *) order_by startFrom: (NSInteger) start InSize: (NSInteger) max_size error:(NSError **) error;

/*!
 @method
 @abstract 获取视频；
 @discussion 获取视频列表；
 @param filter [IN|OUT] 限制条件；
 @param category_id [IN|OUT] 分类id;
 @param order_by [IN|OUT] 排序方式；
 @param start [IN|OUT] 开始位置；
 @param error [IN|OUT] 错误信息；
 @result NSDictionary；
 */
- (NSDictionary *) listWithFilter: (NSDictionary *)filter InCatetory:(NSString *) category_id OrderBy:(NSString *) order_by startFrom: (NSInteger) start error:(NSError **) error;

/*!
 @method
 @abstract 获取视频；
 @discussion 获取视频列表；
 @param filter [IN|OUT] 限制条件
 @param category_id [IN|OUT] 分类id；
 @param order_by [IN|OUT] 排序方式；
 @param max_size [IN|OUT] 最大数量；
 @param error [IN|OUT] 错误信息；
 @result NSDictionary；
 */
- (NSDictionary *) listWithFilter: (NSDictionary *)filter InCatetory:(NSString *) category_id OrderBy:(NSString *) order_by InSize: (NSInteger) max_size error:(NSError **) error;

/*!
 @method
 @abstract 获取视频；
 @discussion 获取视频列表；
 @param filter [IN|OUT] 限制条件；
 @param category_id [IN|OUT] 分类id
 @param order_by [IN|OUT] 排序方式；
 @param error [IN|OUT] 错误信息；
 @result NSDictionary；
 */
- (NSDictionary *) listWithFilter: (NSDictionary *)filter InCatetory:(NSString *) category_id OrderBy:(NSString *) order_by error:(NSError **) error;

/*!
 @method
 @abstract 获取视频信息；
 @discussion 获取视频信息；
 @param idString [IN|OUT] 视频id
 @param error [IN|OUT] 错误信息；
 @result CapitalCloudVideo；
 */
- (CapitalCloudVideo *) get: (NSString *) idString error:(NSError **) error;

/*!
 @method
 @abstract 更新视频信息；
 @discussion 更新视频信息；
 @param entry [IN|OUT] 视频信息；
 @param error [IN|OUT] 错误信息；
 @result CapitalCloudVideo；
 */
- (CapitalCloudVideo *) update: (NSDictionary *) entry error:(NSError **) error;

/*!
 @method
 @abstract 删除视频；
 @discussion 删除视频；
 @param idString [IN|OUT] 视频id
 @param error [IN|OUT] 错误信息；
 @result 返回信息；
 */
- (id) deleteEntry: (NSString *) idString error:(NSError **) error;

/*!
 @method
 @abstract 删除多个视频；
 @discussion 删除多个视频；
 @param idArray [IN|OUT] 视频id列表；
 @param error [IN|OUT] 错误信息；
 @result 返回信息；
 */
- (id) deleteList: (NSArray *) idArray error:(NSError **) error;

/*!
 @method
 @abstract 上线视频；
 @discussion 上线视频；
 @param idString [IN|OUT] 视频ID；
 @param error [IN|OUT] 错误信息；
 @result 返回信息；
 */
- (id) activate: (NSString *) idString error:(NSError **) error;

/*!
 @method
 @abstract	上线多个视频
 @discussion	上线多个视频
 
 @param idArray [IN|OUT] 视频id列表；
 @param error [IN|OUT] 错误信息；
 
 @result 返回信息；
 */
- (id) activateList: (NSArray *) idArray error:(NSError **) error;

/*!
 @method
 @abstract	下线视频；
 @discussion	下线视频；
 
 @param idString [IN|OUT] 视频ID；
 @param error [IN|OUT] 错误信息；
 
 @result 返回信息；
 */
- (id) deactivate: (NSString *) idString error:(NSError **) error;

/*!
 @method
 @abstract	下线多个视频；
 @discussion	下线多个视频；
 
 @param idArray [IN|OUT] 视频ID列表；
 @param error [IN|OUT] 错误信息；
 
 @result 返回信息；
 */
- (id) deactivateList: (NSArray *) idArray error:(NSError **) error;

/*!
 @method
 @abstract	 设置分类；
 @discussion	设置分类；
 
 @param idArray [IN|OUT] 视频id列表；
 @param category_id [IN|OUT] 分类id;
 @param error [IN|OUT] 错误信息；
 
 @result 返回信息；
 */
- (id) setCategory: (NSArray *) idArray catetory: (NSString *) category_id error:(NSError **) error;

/*!
 @method
 @abstract	从某个分类删除；
 @discussion	从某个分类删除；
 
 @param idArray [IN|OUT] 视频ID列表；
 @param category_id [IN|OUT] 分类ID；
 @param error [IN|OUT] 错误信息；
 
 @result <#return value description#>
 */
- (id) removeCategory: (NSArray *) idArray catetory: (NSString *) category_id error:(NSError **) error;

/*!
 @method
 @abstract	获取m3u8地址；
 @discussion	获取m3u8地址；
 
 @param idString [IN|OUT] 视频id；
 
 @result URL地址；
 */
- (NSURL *) getM3U8URL:(NSString *) idString;

/*!
 @method
 @abstract	根据码率获取m3u8地址（可能是本地地址）；
 @discussion	根据码率获取m3u8地址；
 
 @param plInfo [IN|OUT] 视频信息；
 @param rendition [IN|OUT] rendition
 
 @result URL地址；
 */
- (NSURL *) getM3U8URL:(CapitalCloudVideoPlayInfor *) plInfo withRendition:(CapitalCloudRendition *)rendition;

/*!
 @method
 @abstract	获取远程m3u8地址；
 @discussion	获取远程m3u8地址；
 
 @param idString [IN|OUT] 视频id；
 
 @result url地址；
 */
- (NSURL *) getRemoteM3U8URL:(NSString *) idString;

/*!
 @method
 @abstract	获取视频信息并且封装成CapitalCloudVideoPlayInfor实例；
 @discussion	获取视频信息并且封装成CapitalCloudVideoPlayInfor实例；
 
 @param idString [IN|OUT] 视频id；
 @param error [IN|OUT] 错误信息；
 
 @result CapitalCloudVideoPlayInfor实例；
 */
- (CapitalCloudVideoPlayInfor *) getPlayInfor:(NSString *)idString error:(NSError **) error;

/*!
 @method
 @abstract	获取播放器配置信息并封装成CapitalCloudVideoPlayerConfigurations实例；
 @discussion	获取播放器配置信息并封装成CapitalCloudVideoPlayerConfigurations实例；
 
 @param idString [IN|OUT] 播放器id；
 @param error [IN|OUT] 错误信息；
 
 @result CapitalCloudVideoPlayerConfigurations 实例；
 */
- (CapitalCloudVideoPlayerConfigurations *) getPlayConfigurations:(NSString *) idString error:(NSError **) error;

/*!
 @method
 @abstract	获取推荐视频列表；
 @discussion	获取推荐视频列表
 
 @param idString [IN|OUT] 视频id；
 @param error [IN|OUT] 错误信息；
 
 @result 推荐视频列表；
 */
- (NSArray *) getRelated:(NSString *) idString error:(NSError **) error;

@end
