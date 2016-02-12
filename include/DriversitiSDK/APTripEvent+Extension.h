#ifndef APTRIPEVENT_EXTENSION_H
#define APTRIPEVENT_EXTENSION_H
//
//  APTripEvent+Extension.h
//  DriversitiSDK
//
//  Created by Anthony Spinelli on 8/23/14.
//  Copyright (c) 2014 Apio. All rights reserved.
//

#import "APTripEvent.h"
#import <CoreLocation/CoreLocation.h>
#import "APVehicle.h"
#import "DriversitiEventDefs.h"

@interface APTripEvent (Extension)
// Class secondary initializer
+ (APTripEvent*)eventWithType:(DriversitiEventType)eventType
                    timestamp:(NSDate*)timestamp
                     location:(CLLocation*)location
                    inContext:(NSManagedObjectContext*)context;
- (id)jsonObject;
- (NSString *)jsonEventType;
-(void)addFreeformParameter:(id)object forKey:(NSString*)key;
+(NSArray*)eventsForTrip:(APTrip*)trip inContext:(NSManagedObjectContext*)context;
+(BOOL)crashesForCurrentTrip;
+(APTripEvent*)eventForID:(NSString*)ID inContext:(NSManagedObjectContext*)context;
+(NSArray*)eventsToUploadToCloudInContext:(NSManagedObjectContext*)context;
+(NSArray*)eventsBetweenStartTime:(NSDate*)startDate andEndTime:(NSDate*)endTime inContext:(NSManagedObjectContext*)context;

@end
#endif
