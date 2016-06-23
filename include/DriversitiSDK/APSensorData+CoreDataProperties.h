//
//  APSensorData+CoreDataProperties.h
//  
//
//  Created by Jeff Behrbaum on 1/26/16.
//
//
//  Choose "Create NSManagedObject Subclass…" from the Core Data editor menu
//  to delete and recreate this implementation file for your updated model.
//

#import "APSensorData.h"

NS_ASSUME_NONNULL_BEGIN

@class APTripEvent;

@interface APSensorData (CoreDataProperties)

@property (nullable, nonatomic, retain) NSNumber *cloudState;
@property (nullable, nonatomic, retain) NSDate *endTime;
@property (nullable, nonatomic, retain) id eventIdArray;
@property (nullable, nonatomic, retain) NSData *sensorBuffer;
@property (nullable, nonatomic, retain) NSNumber *sensorBufferSize;
@property (nullable, nonatomic, retain) id sensorStringArray;
@property (nullable, nonatomic, retain) NSDate *startTime;
@property (nullable, nonatomic, retain) NSSet<APTripEvent *> *events;

@end

@interface APSensorData (CoreDataGeneratedAccessors)

- (void)addEventsObject:(APTripEvent *)value;
- (void)removeEventsObject:(APTripEvent *)value;
- (void)addEvents:(NSSet<APTripEvent *> *)values;
- (void)removeEvents:(NSSet<APTripEvent *> *)values;

@end

NS_ASSUME_NONNULL_END
