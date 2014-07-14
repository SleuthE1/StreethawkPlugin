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

/**
 Object for hosting friendly name, vc, xib for iphone and ipad. Refer to `-(BOOL)shCustomActivityList:(NSArray *)arrayFriendlyNameObj;`.
 */
@interface StreetHawkFriendlyNameObject : NSObject

/**
 The friendly name register and show on StreetHawk server when sending push notification. All platform should use same friendly name. Example: @"My favourite page". This is mandatory, case sensitive, cannot be nil or empty, and length should be less than 150. It cannot contain ":" because ":" is used as separator for <vc>:<xib_iphone>:<xib_ipad>.
 */
@property (nonatomic, strong) NSString *friendlyName;

/**
 The view controller class name, it must inherit from UIViewController. Example: @"MyViewController". This is mandatory, case sensitive, cannot be nil or empty, otherwise fail to register.
 */
@property (nonatomic, strong) NSString *vc;

/**
 The xib name for iPhone. Example: @"MyViewController_iPhone". This is optional, case sensitive, used for create view controller for iPhone. If not run on iPhone, or xib name is same as class name, set nil.
 */
@property (nonatomic, strong) NSString *xib_iphone;

/**
 The xib name for iPad. Example: @"MyViewController_iPad". This is optional, case sensitive, used for create view controller for iPad. If not run on iPad, or xib name is same as class name, set nil.
 */
@property (nonatomic, strong) NSString *xib_ipad;

@end
