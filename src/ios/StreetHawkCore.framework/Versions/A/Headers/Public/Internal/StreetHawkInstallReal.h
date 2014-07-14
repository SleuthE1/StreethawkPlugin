/*
 * Copyright 2012 StreetHawk
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Created by Christine XYS    Jan 08, 2014
 */

#import "../StreetHawkPublicFwds.h"
#import "StreetHawkObjectReal.h"  //for inherit from StreetHawkObjectReal

#define APNS_DISABLE_TIMESTAMP              @"APNS_DISABLE_TIMESTAMP"
#define APNS_SENT_DISABLE_TIMESTAMP         @"APNS_SENT_DISABLE_TIMESTAMP"
#define INSTALL_SUID_KEY                    @"INSTALL_SUID_KEY"
#define INSTALL_USER_SUID_KEY               @"INSTALL_USER_SUID_KEY"

/**
 An installed device in the StreetHawk system. Combined with the StreetHawkUser object, they are essentially the 'primary keys' for user activity in the system.
 @discuss Apple has made announcements in 2012 that device IDs (UDIDs) are a not to be used for privacy reasons. However what all StreetHawk powered applications/clients need a way to identify installations. So the client side will be responsible for “requesting” a new device GUID when it first starts and then will store it over time. This ID is recorded here. Unfortunately every app deletion and re-install will request/create a new install ID. So the install ID, together with user's suid, is the "primary key".
 */
@interface StreetHawkInstallReal : StreetHawkObjectReal<StreetHawkGeoObject>

/**
 The unique installation ID for this device. This is set during the /installs/register call by the StreetHawk Client Library and prevails until the application is deleted. If you are implementing your own installation ID, you need to contact support@streethawk.com to get the correct algorithms we support. suid is same as installid, but as installid is so special, add a property for it.
 @discuss Apple have indicated they will refuse to approve applications that use UDID, therefore we provide an non-UDID alternative. You should avoid UDID.
 */
//@property (nonatomic, readonly) NSString *suid;

/**
 The client application ID that this log message is associated with. It's same as StreetHawk.hostAppId, which should match server's database.
 */
@property (nonatomic, strong) NSString *appKey;

/**
 Descriptive text for the device model. You should get this from either the android or iphone libraries so a consistent description is logged. i.e if the client is an android the model string must start with android.
 */
@property (nonatomic, strong) NSString *model;

/**
 For iPhone: ‘prod’ or ‘dev’. For Android: ‘c2dm’ only. This is used for push notification services, and log lines.
 */
@property (nonatomic, strong) NSString *mode;

/**
 The version of the client application.
 */
@property (nonatomic, strong) NSString *clientVersion;

/**
 The version of StreetHawkCore framework SDK.
 */
@property (nonatomic, strong) NSString *shVersion;

/**
 The actual access data required to message the device eg device token in iOS etc...
 */
@property (nonatomic, strong) NSString *pushNotificationToken;

/**
 latitude of device.
 */
@property (nonatomic) double latitude;

/**
 longitude of device
 */
@property (nonatomic) double longitude;

/**
 The UTC time this install was created in %Y-%m-%d %H:%M:%S format
 */
@property (nonatomic, strong) NSDate *created;

/**
 The UTC time this install was created in %Y-%m-%d %H:%M:%S format
 */
@property (nonatomic, strong) NSDate *modified;

/**
 No matter the user login or not, there is a user id assigned. If user not login yet, server assign an anonymous user id.
 */
@property (nonatomic, strong) StreetHawkUser *user;

/**
 Ip address of current device. It's known by server, not sent from client.
 */
@property (nonatomic, strong) NSString *ipAddress;

/**
 Mac address sent to server by client. 
 */
@property (nonatomic, strong) NSString *macAddress;

/**
 Since iOS 7.0 mac address in unavailable, it always returns 02:00:00:00:00:00. Add identifierForVendor as another way to identifier vendor.
 */
@property (nonatomic, strong) NSString *identifierForVendor;

/**
 Negative feedback got from server.
 */
@property (nonatomic, strong) NSString *negativeFeedback;

/**
 Profile id got from server.
 */
@property (nonatomic) int profile;

/**
 The date when register push message but don't successfully got token. If got token this is set to empty.
 */
@property (nonatomic, strong) NSString *revoked;

/**
 Carrier of current device. It's sent from client to server.
 */
@property (nonatomic, strong) NSString *carrierName;

/**
 Screen resolution of current device. It's sent from client to server.
 */
@property (nonatomic, strong) NSString *resolution;

/**
 Operating system in lower case. Examples: “android”, “ios”, “windows”. Because this is iOS SDK, it's hard coded as "ios".
 */
@property (nonatomic, strong) NSString *operatingSystem;

/**
 The version of the operating system. Example: “7.0”.
 */
@property (nonatomic, strong) NSString *osVersion;

/**
 Sends normal logs for this installation.
 */
-(void)sendLogs:(NSArray *)logRecords withHandler:(StreetHawkCallbackHandler)handler;

/**
 Sends crash report content info to the server.
 */
-(void)sendCrashReportContent:(NSString *)crashReportContent onCrashDate:(NSDate *)crashDate withHandler:(StreetHawkCallbackHandler)handler;

@end
