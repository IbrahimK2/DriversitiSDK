/*
//  DriversitiEmergencyContact.h
//  DriversitiSDK
//
//  Created by Jeff Behrbaum on 9/22/16.
//  Copyright © 2016 Apio. All rights reserved.
*/

#import <Foundation/Foundation.h>

@class DriversitiUser;

@interface DriversitiEmergencyContact : NSObject
	@property (nullable, nonatomic, strong) NSString *uuid;
	@property (nullable, nonatomic, strong) NSString *phone;
	@property (nullable, nonatomic, strong) NSString *email;
	@property (nullable, nonatomic, strong) NSString *firstName;
	@property (nullable, nonatomic, strong) NSString *lastName;
	@property (nullable, nonatomic, strong) DriversitiUser *user;
@end
