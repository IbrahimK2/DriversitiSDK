//
//  APTrip.h
//  DriversitiSDK
//
//  Created by Anthony Spinelli on 8/30/14.
//  Copyright (c) 2014 Apio. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@interface APTrip : NSManagedObject
	-(id)jsonObject;

	-(double)averageSpeedMPH;
	-(double)averageSpeedMetersPerSecond;
	-(double)topSpeedInMetersPerSecond;
	-(double)totalDistanceInMiles;
	-(double)totalTimeInSeconds;

/*
@property (nonatomic, retain) NSNumber * distance;
@property (nonatomic, retain) NSDate * stopTime;
@property (nonatomic, retain) NSNumber * cloudState;
@property (nonatomic, retain) NSDate * startTime;
@property (nonatomic, retain) NSNumber * topSpeedMPH;
@property (nonatomic, retain) NSString * tripID;
@property (nonatomic, retain) NSString * vehicleUuid;
@property (nonatomic, retain) NSSet *events;
@end

@interface APTrip (CoreDataGeneratedAccessors)

- (void)addEventsObject:(APTripEvent *)value;
- (void)removeEventsObject:(APTripEvent *)value;
- (void)addEvents:(NSSet *)values;
- (void)removeEvents:(NSSet *)values;
 */

@end
