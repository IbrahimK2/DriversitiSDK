/*
//  DriversitiTrip.h
//  DriversitiSDK
//
//  Created by Jeff Behrbaum on 9/22/16.
//  Copyright © 2016 Apio. All rights reserved.
*/

#import <CoreData/CoreData.h>
#import <Foundation/Foundation.h>

@class DriversitiEvent;

@interface DriversitiTrip : NSObject
	@property (nonatomic, readonly) BOOL isCurrentTrip;
	@property (nonatomic) double tripScore;
	@property (nonatomic) double distance;//In meters
	@property (nonatomic) double topSpeedMPH;
	@property (nonatomic) double averageSpeedMPH;

	@property (nullable, nonatomic, strong) NSString *tripID;
	@property (nullable, nonatomic, strong) NSDate *stopTime;
	@property (nullable, nonatomic, strong) NSDate *startTime;

	@property (nullable, nonatomic, strong) NSArray *events;

	@property (nullable, nonatomic, strong) NSManagedObjectID *objID;

	-(nullable NSDictionary *)jsonObject;
@end
