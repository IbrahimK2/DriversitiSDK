//
//  APTripEvent.h
//  DriversitiSDK
//
//  Created by Anthony Spinelli on 9/16/14.
//  Copyright (c) 2014 Apio. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class APTrip;

@interface APTripEvent : NSManagedObject

@property (nonatomic, retain) NSNumber * cloudState;
@property (nonatomic, retain) NSString * eventID;
@property (nonatomic, retain) NSNumber * eventType;
@property (nonatomic, retain) id location;
@property (nonatomic, retain) id optionalValues;
@property (nonatomic, retain) NSNumber * sendNotification;
@property (nonatomic, retain) NSDate * timestamp;
@property (nonatomic, retain) APTrip *trip;

@end
