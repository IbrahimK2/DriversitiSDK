//
//  UserManager.h
//  DriversitiSDK
//
//  Created by Anthony Spinelli on 8/16/15.
//  Copyright (c) 2015 Apio. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "APUser+CoreDataProperties.h"
#import "APEmergencyContact+CoreDataProperties.h"

@interface UserManager : NSObject

+ (instancetype _Nonnull)sharedInstance;

/**
 Set to TRUE to enable the SDK to run without a user
 */
@property (nonatomic, assign) BOOL allowAnonymousUser;
@property (nonatomic, readonly) APUser * _Nullable currentUser;

/**
 Log in a user
 @param username    The username for the user logging in
 @param password    The password for the user logging in
 @param companyId   The company ID for the user logging in
 @param block       Completion block; returns an error value or nil for no error
 */
-(void)loginUser:(NSString* _Nullable)username password:(NSString* _Nullable)password companyId:(NSString* _Nullable)companyId completionBlock:(void (^ _Nullable)(NSError * _Nullable error)) block;

/**
 Logs out user that is logged in
 @param block       Completion block; returns an error value or nil for no error
 */
-(void)logoutActiveUserWithCompletionBlock:(void (^ _Nullable)(NSError * _Nullable error))block;

/**
 Register a user with the Driversiti cloud
 
 @param email         User's email address
 @param password      User's password
 @param firstName     User's first name
 @param middleName    User's middle name
 @param lastName      User's last name
 @param streetAddress User's street address
 @param city          User's city
 @param state         User's state
 @param country       User's country
 @param zipcode       User's zipcode
 @param phoneNumber   User's phone number
 @param username      Username for user
 @param companyId     User's company identifier
 @param block         Completion block; returns an error value or nil for no error
 */
- (void)userRegisterWithEmailAddress:(NSString* _Nullable)email
                            password:(NSString* _Nullable)password
                           firstName:(NSString* _Nullable)firstName
                          middleName:(NSString* _Nullable)middleName
                            lastName:(NSString* _Nullable)lastName
                       streetAddress:(NSString* _Nullable)streetAddress
                                city:(NSString* _Nullable)city
                               state:(NSString* _Nullable)state
                             country:(NSString* _Nullable)country
                             zipcode:(NSString* _Nullable)zipcode
                         phoneNumber:(NSString* _Nullable)phoneNumber
                            username:(NSString* _Nullable)username
                           companyId:(NSString* _Nullable)companyId
                     completionBlock:(void (^ _Nullable)(NSError * _Nullable error))block;

/**
 Update a cloud user
 
 @param uuid          User UUID to update
 @param email         User's updated email address
 @param password      User's updated password
 @param firstName     User's updated first name
 @param lastName      User's updated last name
 @param streetAddress User's updated street address
 @param city          User's updated city
 @param state         User's updated state
 @param country       User's updated country
 @param zipcode       User's updated zipcode
 @param phoneNumber   User's updated phone number
 @param companyId     User's updated company identifier
 @param block         Completion block
 */
- (void)userUpdateWithUuid:(NSString* _Nullable)uuid
              emailAddress:(NSString* _Nullable)email
                  password:(NSString * _Nullable)password
                 firstName:(NSString * _Nullable)firstName
                  lastName:(NSString* _Nullable)lastName
             streetAddress:(NSString* _Nullable)streetAddress
                      city:(NSString* _Nullable)city
                     state:(NSString* _Nullable)state
                   country:(NSString* _Nullable)country
                   zipcode:(NSString* _Nullable)zipcode
               phoneNumber:(NSString * _Nullable)phoneNumber
                 companyId:(NSString* _Nullable)companyId
           completionBlock:(void (^ _Nullable)(NSError * _Nullable error))block;

-(void)driverScoreBetweenTimes:(NSDate* _Nullable)startTime andEndTime:(NSDate* _Nullable)endTime completionBlock:(void (^ _Nullable)(NSError * _Nullable error,NSDictionary * _Nullable scoringDict))block;

-(BOOL)updateEmergencyContactWithFirstName:(NSString* _Nullable)firstName lastName:(NSString* _Nullable)lastName
												 phone:(NSString* _Nullable)phone email:(NSString* _Nullable)email;

- (BOOL)addEmergencyContactWithFirstName:(NSString* _Nullable)firstName lastName:(NSString* _Nullable)lastName
                                   phone:(NSString* _Nullable)phone email:(NSString* _Nullable)email;
- (BOOL)removeEmergencyContact:(APEmergencyContact* _Nullable)contact;

@end
