//
//  APVehicle+extension.h
//  DriversitiSDK
//
//  Created by Anthony Spinelli on 4/7/15.
//  Copyright (c) 2015 Apio. All rights reserved.
//

#import "APVehicle.h"

@interface APVehicle (extension)

+(NSArray*)sortedVehicles;
+(APVehicle*)vehicleForSalIndex:(NSUInteger)salVehicleIndex;
-(NSInteger)salVehicleIndex;

@end
