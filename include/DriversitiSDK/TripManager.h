//
//  TripManager.h
//  DriversitiSDK
//
//  Created by Anthony Spinelli on 8/16/15.
//  Copyright (c) 2015 Apio. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APTrip+extension.h"

@interface TripManager : NSObject

+ (instancetype)sharedInstance;

#pragma mark - Trip Handling
/** @name Trip Handling */

/**
 Obtain the current trip
 @return The current trip object
 */
-(APTrip*)currentTrip;

/**
 Start a trip for a vehicle, as events occur they will be associated with this trip
 
 @param vehicle   Vehicle for which the trip is being create
 @param startTime Time to start the trip
 @note Once the function without error, the current trip can be fetched by [TripManager currentTrip]
 */
-(NSError *) startTripForVehicle:(APVehicle*)vehicle startTime:(NSDate*)startTime;

/**
 Stop the current trip and queue it for upload to the cloud
 
 @param stopTime Time to stop the trip
 */
-(void)stopTripAtTime:(NSDate*)stopTime;

-(NSArray*)tripsSortedByDate;

/**
 Remove a trip from local data store
 
 @param trip APTrip object to remove
 */
-(void)deleteTrip:(APTrip*)trip;

@end
