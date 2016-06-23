//
//  APEmergencyContact+CoreDataProperties.h
//  DriversitiSDK
//
//  Created by Anthony Spinelli on 12/2/15.
//  Copyright © 2015 Apio. All rights reserved.
//
//  Choose "Create NSManagedObject Subclass…" from the Core Data editor menu
//  to delete and recreate this implementation file for your updated model.
//

#import "APEmergencyContact.h"

NS_ASSUME_NONNULL_BEGIN

@interface APEmergencyContact (CoreDataProperties)

@property (nullable, nonatomic, retain) NSNumber *cloudState;
@property (nullable, nonatomic, retain) NSString *email;
@property (nullable, nonatomic, retain) NSString *firstName;
@property (nullable, nonatomic, retain) NSString *lastName;
@property (nullable, nonatomic, retain) NSString *phone;
@property (nullable, nonatomic, retain) NSString *uuid;
@property (nullable, nonatomic, retain) APUser *user;

@end

NS_ASSUME_NONNULL_END
