//
//  UserManager.h
//  DriversitiSDK
//
//  Created by Anthony Spinelli on 8/16/15.
//  Copyright (c) 2015 Apio. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APUser.h"

@interface UserManager : NSObject

+ (instancetype)sharedInstance;

/**
 Set to TRUE to enable the SDK to run without a user
 */
@property (nonatomic, assign) BOOL allowAnonymousUser;
@property (nonatomic, readonly) APUser *currentUser;

/**
 Log in a user
 @param username    The username for the user logging in
 @param password    The password for the user logging in
 @param companyId   The company ID for the user logging in
 @param block       Completion block; returns an error value or nil for no error
 */
-(void)loginUser:(NSString*)username password:(NSString*)password companyId:(NSString*)companyId completionBlock:(void (^)(NSError *error))block;

/**
 Logs out user that is logged in
 @param block       Completion block; returns an error value or nil for no error
 */
-(void)logoutActiveUserWithCompletionBlock:(void (^)(NSError *error))block;

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
- (void)userRegisterWithEmailAddress:(NSString*)email
                            password:(NSString*)password
                           firstName:(NSString *)firstName
                          middleName:(NSString*)middleName
                            lastName:(NSString*)lastName
                       streetAddress:(NSString*)streetAddress
                                city:(NSString*)city
                               state:(NSString*)state
                             country:(NSString*)country
                             zipcode:(NSString*)zipcode
                         phoneNumber:(NSString*)phoneNumber
                            username:(NSString*)username
                           companyId:(NSString*)companyId
                     completionBlock:(void (^)(NSError *error))block;

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
- (void)userUpdateWithUuid:(NSString*)uuid
              emailAddress:(NSString*)email
                  password:(NSString *)password
                 firstName:(NSString *)firstName
                  lastName:(NSString*)lastName
             streetAddress:(NSString*)streetAddress
                      city:(NSString*)city
                     state:(NSString*)state
                   country:(NSString*)country
                   zipcode:(NSString*)zipcode
               phoneNumber:(NSString *)phoneNumber
                 companyId:(NSString*)companyId
           completionBlock:(void (^)(NSError *error))block;

-(void)driverScoreBetweenTimes:(NSDate*)startTime andEndTime:(NSDate*)endTime completionBlock:(void (^)(NSError *error,NSDictionary *scoringDict))block;

-(BOOL)updateEmergencyContactWithFirstName:(NSString*)firstName lastName:(NSString*)lastName
												 phone:(NSString*)phone email:(NSString*)email;

- (BOOL)addEmergencyContactWithFirstName:(NSString*)firstName lastName:(NSString*)lastName
                                   phone:(NSString*)phone email:(NSString*)email;
- (BOOL)removeEmergencyContact:(APEmergencyContact*)contact;

@end
