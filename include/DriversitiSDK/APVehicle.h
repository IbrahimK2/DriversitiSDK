//
//  APVehicle.h
//  DriversitiSDK
//
//  Created by Anthony Spinelli on 4/7/15.
//  Copyright (c) 2015 Apio. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class APBeacon, APMatchFilter;

@interface APVehicle : NSManagedObject

@property (nonatomic, retain) NSNumber * cloudState;
@property (nonatomic, retain) NSString * color;
@property (nonatomic, retain) NSString * licensePlate;
@property (nonatomic, retain) NSString * make;
@property (nonatomic, retain) NSString * model;
@property (nonatomic, retain) NSNumber * mpg;
@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSString * uuid;
@property (nonatomic, retain) NSString * vin;
@property (nonatomic, retain) NSNumber * year;
@property (nonatomic, retain) APBeacon *beacon;
@property (nonatomic, retain) NSSet *matchFilters;
@end

@interface APVehicle (CoreDataGeneratedAccessors)

- (void)addMatchFiltersObject:(APMatchFilter *)value;
- (void)removeMatchFiltersObject:(APMatchFilter *)value;
- (void)addMatchFilters:(NSSet *)values;
- (void)removeMatchFilters:(NSSet *)values;

@end
