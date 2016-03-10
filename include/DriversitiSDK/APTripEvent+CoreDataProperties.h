//
//  APTripEvent+CoreDataProperties.h
//  DriversitiSDK
//
//  Created by Jeff Behrbaum on 3/1/16.
//  Copyright © 2016 Apio. All rights reserved.
//
//  Choose "Create NSManagedObject Subclass…" from the Core Data editor menu
//  to delete and recreate this implementation file for your updated model.
//

#import "APTripEvent.h"

NS_ASSUME_NONNULL_BEGIN

@class APSensorData;
@class APTrip;

@interface APTripEvent (CoreDataProperties)

@property (nullable, nonatomic, retain) NSNumber *cloudState;
@property (nullable, nonatomic, retain) NSString *eventID;
@property (nullable, nonatomic, retain) NSNumber *eventType;
@property (nullable, nonatomic, retain) id location;
@property (nullable, nonatomic, retain) id optionalValues;
@property (nullable, nonatomic, retain) NSNumber *sendNotification;
@property (nullable, nonatomic, retain) NSDate *timestamp;
@property (nullable, nonatomic, retain) NSSet<APSensorData *> *sensorData;
@property (nullable, nonatomic, retain) APTrip *trip;

@end

@interface APTripEvent (CoreDataGeneratedAccessors)

- (void)addSensorDataObject:(APSensorData *)value;
- (void)removeSensorDataObject:(APSensorData *)value;
- (void)addSensorData:(NSSet<APSensorData *> *)values;
- (void)removeSensorData:(NSSet<APSensorData *> *)values;

@end

NS_ASSUME_NONNULL_END
