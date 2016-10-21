/*
//  DriversitiVehicle.h
//  DriversitiSDK
//
//  Created by Jeff Behrbaum on 9/22/16.
//  Copyright © 2016 Apio. All rights reserved.
*/

#import <Foundation/Foundation.h>

@class DriversitiUser;

@interface DriversitiVehicle : NSObject
	//@property (nullable, nonatomic, retain) NSNumber *cloudState;
	@property (nonatomic) int mpg;
	@property (nonatomic) int year;

	@property (nullable, nonatomic, strong) NSString *color;
	@property (nullable, nonatomic, strong) NSString *make;
	@property (nullable, nonatomic, strong) NSString *model;
	@property (nullable, nonatomic, strong) NSString *name;
	@property (nullable, nonatomic, strong) NSString *uuid;
	@property (nullable, nonatomic, strong) NSString *vin;
	@property (nullable, nonatomic, strong) NSString *licensePlate;
	@property (nullable, nonatomic, strong) DriversitiUser *associatedUser;
@end
