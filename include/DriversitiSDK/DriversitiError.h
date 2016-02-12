//
//  APError.h
//  Apio
//
//  Created by Thomas Aylesworth on 8/19/13.
//  Copyright (c) 2013 Apio Systems LLC. All rights reserved.
//

extern NSString * const APErrorDomain;
extern NSString * const APSalErrorDomain;

enum
{
    //
    // Sensor Analysis Library error codes
    //
    APErrorSalUninitialized = -1000,
};

enum
{
    APErrorCloudInvalidResponse = -1,
    APErrorInvalidParams = -2,
    APErrorNetworkNotAvailable = -3,
    APErrorVehicleIdCaptureBufferOverrun = -100,
    APErrorVehicleIdCaptureBufferUnderrun = -101,
    APErrorVehicleIdCaptureAlreadyStarted = -102,
    APErrorTripAlreadyStarted = -200,
    APErrorTripNoVehicle = -201,
    APErrorUserInvalidLogin = -300,
    
};

/**
 *  APError extends NSError to provide Apio-specific error reporting.
 */
@interface DriversitiError : NSError

+ (NSError *)errorWithSalInitializationErrorCode:(int)salErrorCode;

+ (NSError *)errorWithApioErrorCode:(int)errorCode description:(NSString *)localizedDescription;

@end
