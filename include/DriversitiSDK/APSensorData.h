//
//  APSensorData.h
//  DriversitiSDK
//
//  Created by Anthony Spinelli on 7/12/15.
//  Copyright (c) 2015 Apio. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

#import "DriversitiEventDefs.h"

@interface APSensorData : NSManagedObject

-(BOOL)hasValidSensorDataToUpload;

-(NSDictionary*)jsonObject;
+(NSArray*)sensorDataToUploadToCloudInContext:(NSManagedObjectContext*)context;
+(NSArray*)sensorDataInContext:(NSManagedObjectContext*)context state:(CLOUD_STATE)eState;

@end