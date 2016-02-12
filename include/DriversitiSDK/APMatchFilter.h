//
//  APMatchFilter.h
//  DriversitiSDK
//
//  Created by Anthony Spinelli on 4/8/15.
//  Copyright (c) 2015 Apio. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class APVehicle;

@interface APMatchFilter : NSManagedObject

@property (nonatomic, retain) NSDate * captureTime;
@property (nonatomic, retain) NSNumber * endOfEntryIndex;
@property (nonatomic, retain) NSData * filterData;
@property (nonatomic, retain) NSNumber * filterIndex;
@property (nonatomic, retain) NSNumber * startOfExitIndex;
@property (nonatomic, retain) APVehicle *vehicle;

@end
