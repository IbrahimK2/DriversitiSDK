//
//  APBeacon+extension.h
//  DriversitiSDK
//
//  Created by Anthony Spinelli on 4/7/15.
//  Copyright (c) 2015 Apio. All rights reserved.
//

#import "APBeacon.h"
#import <CoreLocation/CoreLocation.h>

@interface APBeacon (extension)

- (CLBeaconRegion *)beaconRegionForBeacon;
- (BOOL)isEqualToCLBeacon:(CLBeacon *)beacon;
- (BOOL)isEqualToBeacon:(APBeacon*)beacon;
+ (APBeacon*) beaconWithUuid:(NSString*)proximityUuid majorValue:(NSNumber*)majorValue minorValue:(NSNumber*)minorValue;
+ (NSString *)nameForProximity:(CLProximity)proximity;

@end
