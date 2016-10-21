//
//  TripManager.h
//  DriversitiSDK
//
//  Created by Anthony Spinelli on 8/16/15.
//  Copyright (c) 2015 Apio. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "APTrip+CoreDataProperties.h"
#import "APVehicle+CoreDataProperties.h"
#import "DriversitiTrip.h"

@interface TripManager : NSObject

	-(nullable APTrip*)currentTrip  __attribute__((deprecated("Will be removed in the next iteration. Use CurrentTrip instead")));
	-(nullable NSArray*)tripsSortedByDate __attribute__((deprecated("Will be removed. Call allTripsSortedByDate:withEvents instead")));
	-(BOOL)validateTrip:(nullable APTrip *)trip __attribute__((deprecated("Will be removed. Call validateDriversitiTrip:trip instead.")));
	-(void)deleteTrip:(nullable APTrip*)trip __attribute__((deprecated("Will be removed in the next iteration. Trip deletion will be handled internally based on trip properties.")));
	-(nullable NSError *)startTripForVehicle:(nullable APVehicle*)vehicle startTime:(nullable NSDate*)startTime  __attribute__((deprecated("Will be removed in the next iteration. Use startANewTrip instead. Vehicles are not incorporated any more.")));

	@property(nullable, nonatomic, readonly) NSURL *activeTripID;

	+(nonnull instancetype)sharedInstance;

	/**
	 Obtain the current trip
	 @return The current trip object
	 */
	@property(nullable, nonatomic, readonly) DriversitiTrip *CurrentTrip;
	//-(nullable DriversitiTrip *)CurrentTrip;

	/**
	 Start a trip for a vehicle, as events occur they will be associated with this trip

	 @param vehicle   Vehicle for which the trip is being create
	 @param startTime Time to start the trip
	 @note Once the function without error, the current trip can be fetched by [TripManager currentTrip]
	 */
	-(nullable NSError *)startANewTrip:(nonnull NSDate *)atStartTime;

	/**
	 Stop the current trip and queue it for upload to the cloud

	 @param stopTime Time to stop the trip
	 */
	-(void)stopTripAtTime:(nullable NSDate*)stopTime;

	-(int)totalTripCount;

	-(BOOL)validateDriversitiTrip:(nullable DriversitiTrip *)trip;

	/**
	 All Trips the current trip and queue it for upload to the cloud

	 @param withEvents:
	 TRUE: All events in all the trips will be populated.
		NOTE: Setting this to true can slow down this call significantly

	 FALSE: Returns all the trips but without their associated events.
		NOTE: you can query for the events of an individual trip later on
				with the "retreiveEventsForTrip" call.
	*/
	-(nullable NSArray<DriversitiTrip *> *)allTripsSortedByDate:(BOOL)withEvents;


	//Pass in nil for the current trip since it may not have an ID to query on.
	-(nullable NSArray<DriversitiEvent*>*)retreiveEventsForTrip:(nullable DriversitiTrip *)theTrip;
@end
