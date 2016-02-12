//
//  APSensorData.h
//  DriversitiSDK
//
//  Created by Anthony Spinelli on 7/12/15.
//  Copyright (c) 2015 Apio. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class APTripEvent;

@interface APSensorData : NSManagedObject

@property (nonatomic, retain) NSNumber * cloudState;
@property (nonatomic, retain) id eventIdArray;
@property (nonatomic, retain) id sensorStringArray;
@property (nonatomic, retain) NSDate * startTime;
@property (nonatomic, retain) NSDate * endTime;
@property (nonatomic, retain) NSSet *events;
@end

@interface APSensorData (CoreDataGeneratedAccessors)

- (void)addEventsObject:(APTripEvent *)value;
- (void)removeEventsObject:(APTripEvent *)value;
- (void)addEvents:(NSSet *)values;
- (void)removeEvents:(NSSet *)values;

@end
