//
//  APBeacon.h
//  DriversitiSDK
//
//  Created by Anthony Spinelli on 4/7/15.
//  Copyright (c) 2015 Apio. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class APVehicle;

@interface APBeacon : NSManagedObject

@property (nonatomic, retain) NSNumber * cloudState;
@property (nonatomic, retain) NSNumber * majorValue;
@property (nonatomic, retain) NSNumber * minorValue;
@property (nonatomic, retain) NSString * proximityUuid;
@property (nonatomic, retain) APVehicle *vehicle;

@end
