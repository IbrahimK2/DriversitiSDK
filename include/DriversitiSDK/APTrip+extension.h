#ifndef APTRIP_EXTENSION_H
#define APTRIP_EXTENSION_H

//
//  APTrip+extension.h
//  DriversitiSDK
//
//  Created by Anthony Spinelli on 8/25/14.
//  Copyright (c) 2014 Apio. All rights reserved.
//

#import "APTrip.h"
#import "APVehicle.h"
#import "DriversitiSDK.h"


@interface APTrip (extension)

-(id)jsonObject;


-(double)averageSpeedMPH;
-(double)averageSpeedMetersPerSecond;
-(double)topSpeedInMetersPerSecond;
-(double)totalDistanceInMiles;
-(double)totalTimeInSeconds;

@end
#endif