/*
//  DriversitiUser.h
//  DriversitiSDK
//
//  Created by Jeff Behrbaum on 9/22/16.
//  Copyright © 2016 Apio. All rights reserved.
*/

#import <Foundation/Foundation.h>

@class DriversitiVehicle;
@class DriversitiEmergencyContact;

@interface DriversitiUser : NSObject
	@property (nullable, nonatomic, strong) NSString *city;
	@property (nullable, nonatomic, strong) NSString *companyId;
	@property (nullable, nonatomic, strong) NSString *country;
	@property (nullable, nonatomic, strong) NSString *emailAddress;
	@property (nullable, nonatomic, strong) NSString *firstName;
	@property (nullable, nonatomic, strong) NSString *lastName;
	@property (nullable, nonatomic, strong) NSString *middleName;
	@property (nullable, nonatomic, strong) NSString *password;
	@property (nullable, nonatomic, strong) NSString *phoneNumber;
	@property (nullable, nonatomic, strong) NSString *state;
	@property (nullable, nonatomic, strong) NSString *streetAddress;
	@property (nullable, nonatomic, strong) NSString *token;
	@property (nullable, nonatomic, strong) NSString *username;
	@property (nullable, nonatomic, strong) NSString *uuid;
	@property (nullable, nonatomic, strong) NSString *zip;
	@property (nullable, nonatomic, strong) NSArray *emergencyContacts;
	@property (nullable, nonatomic, strong) NSArray *vehicles;

	-(nullable NSDictionary *)jsonObject;
@end
