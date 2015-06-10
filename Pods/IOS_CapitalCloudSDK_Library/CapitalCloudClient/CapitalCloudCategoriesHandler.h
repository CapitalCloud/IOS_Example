//
//  CapitalCloudCategoriesHandler.h
//  CapitalCloudClient
//
//  Created by julien on 14-5-6.
//  Copyright (c) 2014年 capitalCloud. All rights reserved.
//

/*!
 @header CapitalCloudCategoriesHandler
 @abstract 视频分类管理类，由CapitalCloudAPIClient保有唯一实例，负责视频分类的增删改查；
 @author capitalCloud
 @version 1.3.2
 */

#import <Foundation/Foundation.h>
#import "CapitalCloudCategory.h"

@class CapitalCloudAPIClient;

/*!
 @class
 @abstract 视频分类管理类，由CapitalCloudAPIClient保有唯一实例，负责视频的增删改查；
 */
@interface CapitalCloudCategoriesHandler : NSObject

/*!
 @property
 @abstract APP和石山sdk的交互主要通过CapitalCloudAPIClient类,首先需要生成CapitalCloudAPIClient对象.
 */
@property(readwrite, weak) CapitalCloudAPIClient *apiClient;

/*!
 @method
 @abstract	通过apiClient生成CapitalCloudCategoriesHandler实例
 @discussion	通过apiClient生成CapitalCloudCategoriesHandler实例
 
 @param apiClient [IN|OUT] apiClient实例；
 
 @result CapitalCloudCategoriesHandler 实例；
 */
-(instancetype) initWithAPIClient:(CapitalCloudAPIClient *)apiClient;

/*!
 @method
 @abstract	获取所有分类；
 @discussion	获取所有分类
 
 @param filter [IN|OUT] 限制条件；
 @param error [IN|OUT] 错误信息；
 
 @result 分类信息列表；
 */
- (NSDictionary *) all: (NSDictionary *)filter error:(NSError **) error;

/*!
 @method
 @abstract	添加分类到某个分类；
 @discussion	添加分类到某个分类；
 
 @param name [IN|OUT] 名称；
 @param parent_id [IN|OUT] 父分类名称；
 @param error [IN|OUT] 错误信息；
 
 @result 添加的分类信息；
 */
- (CapitalCloudCategory *) add: (NSString *) name parent:(NSString *) parent_id error:(NSError **) error;

/*!
 @method
 @abstract	添加分类；
 @discussion	添加分类；
 
 @param name [IN|OUT] 分类名称；
 @param error [IN|OUT] 错误信息；
 
 @result 添加的分类信息；
 */
- (CapitalCloudCategory *) add: (NSString *) name error:(NSError **) error;

/*!
 @method
 @abstract	获取某个分类信息；
 @discussion	获取某个分类信息；
 
 @param idString [IN|OUT] 分类id；
 @param error [IN|OUT] 错误信息；
 
 @result 获取的分类信息；
 */
- (CapitalCloudCategory *) get: (NSString *) idString error:(NSError **) error;

/*!
 @method
 @abstract	更新分类信息；
 @discussion	更新分类信息；
 
 @param idString [IN|OUT] 视频分类id；
 @param name [IN|OUT] 重命名；
 @param error [IN|OUT] 错误信息；
 
 @result 返回的分类信息；
 */
- (CapitalCloudCategory *) update: (NSString *) idString name:(NSString *)name error:(NSError **) error;

/*!
 @method
 @abstract	删除分类；
 @discussion	删除分类；
 
 @param idString [IN|OUT] 分类id；
 @param error [IN|OUT] 错误信息；
 
 @result 返回分类列表；
 */
- (NSDictionary *) deleteCategory: (NSString *) idString error:(NSError **) error;

@end
