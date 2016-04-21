//
//  APTrip.h
//  DriversitiSDK
//
//  Created by Anthony Spinelli on 8/30/14.
//  Copyright (c) 2014 Apio. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@interface APTrip : NSManagedObject
	//-(id)jsonObject;
	-(id)jsonTripObject;

	/**
	 Driversiti Score for this trip. Scores are calculated at the end of a trip based on various elements, including
	 events, event types, event durations, and trip durations. Scores will not be available until after a trip has ended.

	 @return score for this trip on a scale of 0-100. Returns a negative value if the score cannot be computed
	 */
	-(double)tripScore;
	-(double)averageSpeedMPH;
	-(double)averageSpeedMetersPerSecond;
	-(double)topSpeedInMetersPerSecond;
	-(double)totalDistanceInMiles;
	-(double)totalTimeInSeconds;
@end
