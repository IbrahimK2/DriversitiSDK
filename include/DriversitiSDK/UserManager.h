//
//  UserManager.h
//  DriversitiSDK
//
//  Created by Anthony Spinelli on 8/16/15.
//  Copyright (c) 2015 Apio. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APUser.h"
#import "DriversitiUser.h"

@interface UserManager : NSObject
	@property(nonatomic, nullable, readonly) APUser *currentUser  __attribute__((unavailable("Will be removed in the next iteration. Use CurrentUser property instead")));

	-(nullable APUser *)userFromThread __attribute__((unavailable("Will be removed in the next iteration. Use CurrentUser property instead")));
	-(APUser * _Nullable )retreiveCurrentUser __attribute__((unavailable("Will be removed in the next iteration. Use CurrentUser property instead")));
	-(BOOL)removeEmergencyContact:(nullable APEmergencyContact*)contact __attribute__((unavailable("Will be removed in the next iteration. Emergency contacts are unsupported at this stage.")));

	-(BOOL)updateEmergencyContactWithFirstName:(nullable NSString*)firstName
												 lastName:(nullable NSString*)lastName
													 phone:(nullable NSString*)phone
													 email:(nullable NSString*)email __attribute__((unavailable("Will be removed in the next iteration. Emergency contacts are unsupported at this stage.")));

	-(BOOL)addEmergencyContactWithFirstName:(nullable NSString*)firstName
											 lastName:(nullable NSString*)lastName
												 phone:(nullable NSString*)phone
												 email:(nullable NSString*)email __attribute__((unavailable("Will be removed in the next iteration. Emergency contacts are unsupported at this stage.")));

	-(BOOL)removeDriversitiEmergencyContact:(nullable DriversitiEmergencyContact*)contact __attribute__((unavailable("Will be removed in the next iteration. Emergency contacts are unsupported at this stage.")));

	-(void)driverScoreBetweenTimes:(nullable NSDate*)startTime
							  andEndTime:(nullable NSDate*)endTime
						completionBlock:(nullable void (^)(NSObject * _Nullable responseObject, NSError * _Nullable error))block __attribute__((unavailable("Scores are no longer calculated based on time differences")));

	+(nonnull instancetype)sharedInstance;

	/**
	Set to TRUE to enable the SDK to run without a user
	*/
	@property (nonatomic, assign) BOOL allowAnonymousUser;
	@property (nonatomic, readonly) BOOL bUserNeedsToBeUploaded;
	@property (nonatomic, readonly, nullable) NSString *companyID;
	@property (nullable, nonatomic, readonly) DriversitiUser *CurrentUser;

	/**
	Log in a user

	@param username    The username for the user logging in
	@param password    The password for the user logging in
	@param companyId   The company ID for the user logging in
	@param block       Completion block; returns an error value or nil for no error
	*/
	-(void)loginUser:(nullable NSString*)username
			  password:(nullable NSString*)password
			 companyId:(nullable NSString*)companyId
	 completionBlock:(nullable void (^)(id _Nullable responseObj, NSError * _Nullable error))block;

	/**
	Logs out user that is logged in
	@param block       Completion block; returns an error value or nil for no error
	*/
	-(void)logoutActiveUserWithCompletionBlock:(nullable void (^)(NSError * _Nullable error))block;

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
	-(void)userRegisterWithEmailAddress:(nullable NSString*)email
										password:(nullable NSString*)password
									  firstName:(nullable NSString *)firstName
									 middleName:(nullable NSString*)middleName
										lastName:(nullable NSString*)lastName
								 streetAddress:(nullable NSString*)streetAddress
											 city:(nullable NSString*)city
											state:(nullable NSString*)state
										 country:(nullable NSString*)country
										 zipcode:(nullable NSString*)zipcode
									phoneNumber:(nullable NSString*)phoneNumber
										username:(nullable NSString*)username
									  companyId:(nullable NSString*)companyId
							  completionBlock:(nullable void (^)(NSError * _Nullable error))block;

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
	-(void)userUpdateWithUuid:(nullable NSString*)uuid
					 emailAddress:(nullable NSString*)email
						  password:(nullable NSString *)password
						 firstName:(nullable NSString *)firstName
						  lastName:(nullable NSString*)lastName
					streetAddress:(nullable NSString*)streetAddress
								city:(nullable NSString*)city
							  state:(nullable NSString*)state
							country:(nullable NSString*)country
							zipcode:(nullable NSString*)zipcode
					  phoneNumber:(nullable NSString *)phoneNumber
						 companyId:(nullable NSString*)companyId
				 completionBlock:(nullable void (^)(NSError * _Nullable error))block;

@end
