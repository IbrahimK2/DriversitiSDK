//
//  APVehicle+CoreDataProperties.h
//  DriversitiSDK
//
//  Created by Jeff Behrbaum on 3/1/16.
//  Copyright © 2016 Apio. All rights reserved.
//
//  Choose "Create NSManagedObject Subclass…" from the Core Data editor menu
//  to delete and recreate this implementation file for your updated model.
//

#import "APVehicle.h"

NS_ASSUME_NONNULL_BEGIN

@class APUser;

@interface APVehicle (CoreDataProperties)

@property (nullable, nonatomic, retain) NSNumber *cloudState;
@property (nullable, nonatomic, retain) NSString *color;
@property (nullable, nonatomic, retain) NSString *licensePlate;
@property (nullable, nonatomic, retain) NSString *make;
@property (nullable, nonatomic, retain) NSString *model;
@property (nullable, nonatomic, retain) NSNumber *mpg;
@property (nullable, nonatomic, retain) NSString *name;
@property (nullable, nonatomic, retain) NSString *uuid;
@property (nullable, nonatomic, retain) NSString *vin;
@property (nullable, nonatomic, retain) NSNumber *year;
@property (nullable, nonatomic, retain) NSSet<APUser *> *usersRelationship;

@end

@interface APVehicle (CoreDataGeneratedAccessors)

- (void)addUsersRelationshipObject:(APUser *)value;
- (void)removeUsersRelationshipObject:(APUser *)value;
- (void)addUsersRelationship:(NSSet<APUser *> *)values;
- (void)removeUsersRelationship:(NSSet<APUser *> *)values;

@end

NS_ASSUME_NONNULL_END
