/*
//  DriversitiEvent.h
//  DriversitiSDK
//
//  Created by Jeff Behrbaum on 9/22/16.
//  Copyright © 2016 Apio. All rights reserved.
*/

#import <CoreData/CoreData.h>
#import <Foundation/Foundation.h>

#import "DriversitiEventDefs.h"

@class CLLocation;
@class DriversitiTrip;

@interface DriversitiEvent : NSObject
	@property (nonatomic) DriversitiEventType eventType;
	@property (nullable, nonatomic, strong) NSString *eventID;
	@property (nullable, nonatomic, strong) NSDate *timestamp;
	@property (nullable, nonatomic, strong) DriversitiTrip *trip;
	@property (nullable, nonatomic, strong) CLLocation *location;
	@property (nullable, nonatomic, strong) NSString *associatedTripID;
	@property (nullable, nonatomic, readonly) NSDictionary *optionalValues;

	//The object ID for the event.
	@property (nullable, nonatomic, strong) NSManagedObjectID *objID;

	-(nullable NSDictionary *)jsonObject;
	-(BOOL)addFreeFormParameter:(nullable NSObject *)parameterObject forKey:(nullable NSString *)key;
@end
