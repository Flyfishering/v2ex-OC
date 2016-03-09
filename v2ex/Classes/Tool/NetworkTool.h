//
//  NetworkTool.h
//  v2ex
//
//  Created by 无头骑士 GJ on 16/3/3.
//  Copyright © 2016年 无头骑士 GJ. All rights reserved.
//  网络工具类

#import <AFNetworking/AFNetworking.h>


typedef NS_ENUM(NSInteger, HTTPMethodType)
{
    HTTPMethodTypeGET,      // GET请求
    HTTPMethodTypePOST,     // POST请求
};

@interface NetworkTool : AFHTTPSessionManager

/**
 *  单例
 *
 */
+ (instancetype)shareInstance;

/**
 *  发起请求
 *
 *  @param method  请求方法
 *  @param url     url地址
 *  @param param   参数
 *  @param success 请求成功的回调
 *  @param failure 请求失败的回调
 */
- (void)requestWithMethod:(HTTPMethodType)method url:(NSString *)url param:(NSDictionary *)param success:(void (^)(id responseObject))success failure:(void (^)(NSError *error))failure;

/**
 *  上传单张图片
 *
 *  @param urlString url地址
 *  @param image     图片对象
 *  @param progress  进度条的回调
 *  @param success   请求成功的回调
 *  @param failure   请求失败的回调
 */
- (void)uploadImageWithUrlString:(NSString *)urlString image:(UIImage *)image progress:(void (^)(NSProgress *uploadProgress))progress success:(void (^)(id responseObject))success failure:(void (^)(NSError *error))failure;

/**
 *  回复别人的帖子
 *
 *  @param urlString url地址
 *  @param once      回复帖子必须属性
 *  @param content   回复的正文内容
 *  @param success   请求成功的回调
 *  @param failure   请求失败的回调
 */
- (void)replyTopicWithUrlString:(NSString *)urlString once:(NSString *)once content:(NSString *)content success:(void (^)(id responseObject))success failure:(void (^)(NSError *error))failure;

/**
 *  注册
 *
 *  @param username 用户名
 *  @param password 密码
 *  @param email    邮箱
 *  @param c        验证码
 *  @param success  请求成功的回调
 *  @param failure  请求失败的回调
 */
- (void)registerWithUsername:(NSString *)username password:(NSString *)password email:(NSString *)email c:(NSString *)c success:(void (^)(BOOL isSuccess))success failure:(void(^)(NSError *error))failure;

/**
 *  获取验证码的URL
 *
 *  @param success 请求成功的回调
 *  @param failure 请求失败的回调
 */
- (void)getVerificationCodeUrlWithSuccess:(void (^)(NSString *codeUrl))success failure:(void (^)(NSError *error))failure;

/**
 *  根据url获取二进制数据
 *
 *  @param urlString url
 *  @param success   请求成功的回调
 *  @param failure   请求失败的回调
 */
- (void)getDataWithUrl:(NSString *)urlString success:(void(^)(NSData *data))success failure:(void(^)(NSError *error))failure;
@end
