//
//  APTripEvent.h
//  DriversitiSDK
//
//  Created by Anthony Spinelli on 9/16/14.
//  Copyright (c) 2014 Apio. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

#import "DriversitiEventDefs.h"

@class APTrip;
@class CLLocation;

@interface APTripEvent : NSManagedObject
	// Class secondary initializer
	+(APTripEvent*)eventWithType:(DriversitiEventType)eventType
							 timestamp:(NSDate*)timestamp
							  location:(CLLocation*)location
							 inContext:(NSManagedObjectContext*)context;

	+(void)endTripWithoutAStopTime:(APTrip *)theTrip
								timestamp:(NSDate*)timestamp
									location:(CLLocation*)location
								inContext:(NSManagedObjectContext*)context;

	-(id)jsonObject;
	-(NSString *)jsonEventType;
	-(void)addFreeformParameter:(id)object forKey:(NSString*)key;

	+(NSArray*)eventsForTrip:(APTrip*)trip inContext:(NSManagedObjectContext*)context;
	+(BOOL)crashesForCurrentTrip;
	+(APTripEvent*)eventForID:(NSString*)ID inContext:(NSManagedObjectContext*)context;
	+(NSArray*)eventsToUploadToCloud:(BOOL)bIncludeNoOps inContext:(NSManagedObjectContext*)context;
	+(NSArray*)eventsBetweenStartTime:(NSDate*)startDate andEndTime:(NSDate*)endTime inContext:(NSManagedObjectContext*)context;
@end
