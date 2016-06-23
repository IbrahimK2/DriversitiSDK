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
	-(id)jsonObject;

	-(double)tripScore;
	-(double)averageSpeedMPH;
	-(double)averageSpeedMetersPerSecond;
	-(double)topSpeedInMetersPerSecond;
	-(double)totalDistanceInMiles;
	-(double)totalTimeInSeconds;

@end