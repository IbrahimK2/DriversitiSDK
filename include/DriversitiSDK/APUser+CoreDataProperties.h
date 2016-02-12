//
//  APUser+CoreDataProperties.h
//  DriversitiSDK
//
//  Created by Anthony Spinelli on 12/1/15.
//  Copyright © 2015 Apio. All rights reserved.
//
//  Choose "Create NSManagedObject Subclass…" from the Core Data editor menu
//  to delete and recreate this implementation file for your updated model.
//

#import "APUser.h"

NS_ASSUME_NONNULL_BEGIN

@interface APUser (CoreDataProperties)

@property (nullable, nonatomic, retain) NSString *city;
@property (nullable, nonatomic, retain) NSNumber *cloudState;
@property (nullable, nonatomic, retain) NSString *companyId;
@property (nullable, nonatomic, retain) NSString *country;
@property (nullable, nonatomic, retain) NSString *emailAddress;
@property (nullable, nonatomic, retain) NSString *firstName;
@property (nullable, nonatomic, retain) NSString *lastName;
@property (nullable, nonatomic, retain) NSString *middleName;
@property (nullable, nonatomic, retain) NSString *password;
@property (nullable, nonatomic, retain) NSString *phoneNumber;
@property (nullable, nonatomic, retain) NSString *state;
@property (nullable, nonatomic, retain) NSString *streetAddress;
@property (nullable, nonatomic, retain) NSString *token;
@property (nullable, nonatomic, retain) NSString *username;
@property (nullable, nonatomic, retain) NSString *uuid;
@property (nullable, nonatomic, retain) NSString *zip;
@property (nullable, nonatomic, retain) NSSet<APEmergencyContact *> *emergencyContacts;

@end

@interface APUser (CoreDataGeneratedAccessors)

- (void)addEmergencyContactsObject:(APEmergencyContact *)value;
- (void)removeEmergencyContactsObject:(APEmergencyContact *)value;
- (void)addEmergencyContacts:(NSSet<APEmergencyContact *> *)values;
- (void)removeEmergencyContacts:(NSSet<APEmergencyContact *> *)values;

@end

NS_ASSUME_NONNULL_END
