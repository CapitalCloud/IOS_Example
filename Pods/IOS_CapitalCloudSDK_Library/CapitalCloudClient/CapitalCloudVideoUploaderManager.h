//
//  CapitalCloudVideoUploaderManager.h
//  CapitalCloudClient
//
//  Created by yangfei on 3/12/15.
//  Copyright (c) 2015 capitalCloud. All rights reserved.
//

/*!
 @header  CapitalCloudVideoUploaderManager
 @abstract 视频上传管理类；
 @author capitalCloud
 @version 1.3.2
 */
#import <Foundation/Foundation.h>
#import "CapitalCloudVideoUploader.h"

/*!
 @class
 @abstract 视频上传管理，提供视频上传的相关接口；
 */
@interface CapitalCloudVideoUploaderManager : NSObject<CapitalCloudVideoUploaderDelegate>


/*!
 @method
 @abstract	通过url下载视频；
 @discussion	通过url下载视频
 
 @param file 上传文件地址信息；
 @param client apiClient;
 @param parameters 参数;
 @param error [IN|OUT] 错误信息；
 
 @result CapitalCloudVideoDownloader实例，可用于查看当前下载状态，状态改变回调等；
 */
- (CapitalCloudVideoUploader *) upload:(NSURL *)file paramters:(NSDictionary *)parameters error:(NSError **)error;

/*!
 @method
 @abstract	初始化；
 @discussion	初始化CapitalCloudVideoUploaderManager实例；
 
 @param client [IN|OUT] apiClient;
 
 @result CapitalCloudVideoUploaderManager实例；
 */
-(id)initWithClient:(CapitalCloudAPIClient *)client;

/*!
 @method
 @abstract	暂停所有任务；
 @discussion	暂停所有任务；
 */
-(void)pause;

/*!
 @method
 @abstract	恢复所有任务；
 @discussion	恢复所有任务；
 */
-(void)resume;

/*!
 @method
 @abstract	取消某个上传任务；
 @discussion	取消某个上传任务；
 
 @param uploader [IN|OUT] CapitalCloudVideoUploader实例；
 */
-(void)cancel:(CapitalCloudVideoUploader *)uploader;

/*!
 @method
 @abstract	获得当前所有的上传任务；
 @discussion	获得当前所有的上传任务；
 
 @result 当前所有的上传任务列表；
 */
-(NSMutableArray *)getUploaderList;

@end
