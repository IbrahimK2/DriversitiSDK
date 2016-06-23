//
//  APVehicle.h
//  DriversitiSDK
//
//  Created by Anthony Spinelli on 4/7/15.
//  Copyright (c) 2015 Apio. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@interface APVehicle : NSManagedObject
	+(NSArray*)sortedVehicles;
	+(APVehicle*)vehicleForSalIndex:(NSUInteger)salVehicleIndex;
	-(NSInteger)salVehicleIndex;
@end