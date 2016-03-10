//
//  APSensorData.h
//  DriversitiSDK
//
//  Created by Anthony Spinelli on 7/12/15.
//  Copyright (c) 2015 Apio. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@interface APSensorData : NSManagedObject
	-(BOOL)readyToUpload;
	-(void)linkToEventsInContext:(NSManagedObjectContext*)context;

	-(NSDictionary*)jsonObject;
	+(NSArray*)sensorDataToUploadToCloudInContext:(NSManagedObjectContext*)context;

@end
