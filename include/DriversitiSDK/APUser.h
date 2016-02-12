//
//  APUser.h
//  DriversitiSDK
//
//  Created by Anthony Spinelli on 12/1/15.
//  Copyright © 2015 Apio. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class APEmergencyContact;

NS_ASSUME_NONNULL_BEGIN

@interface APUser : NSManagedObject

// Insert code here to declare functionality of your managed object subclass

- (id)jsonObject;

@end

NS_ASSUME_NONNULL_END

#import "APUser+CoreDataProperties.h"
