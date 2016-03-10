//
//  APTrip+CoreDataProperties.h
//  DriversitiSDK
//
//  Created by Jeff Behrbaum on 3/1/16.
//  Copyright © 2016 Apio. All rights reserved.
//
//  Choose "Create NSManagedObject Subclass…" from the Core Data editor menu
//  to delete and recreate this implementation file for your updated model.
//

#import "APTrip.h"

NS_ASSUME_NONNULL_BEGIN

@class APTripEvent;

@interface APTrip (CoreDataProperties)

@property (nullable, nonatomic, retain) NSNumber *cloudState;
@property (nullable, nonatomic, retain) NSNumber *distance;
@property (nullable, nonatomic, retain) NSDate *startTime;
@property (nullable, nonatomic, retain) NSDate *stopTime;
@property (nullable, nonatomic, retain) NSNumber *topSpeedMPH;
@property (nullable, nonatomic, retain) NSString *tripID;
@property (nullable, nonatomic, retain) NSString *vehicleUuid;
@property (nullable, nonatomic, retain) NSSet<APTripEvent *> *events;

@end

@interface APTrip (CoreDataGeneratedAccessors)

- (void)addEventsObject:(APTripEvent *)value;
- (void)removeEventsObject:(APTripEvent *)value;
- (void)addEvents:(NSSet<APTripEvent *> *)values;
- (void)removeEvents:(NSSet<APTripEvent *> *)values;

@end

NS_ASSUME_NONNULL_END
