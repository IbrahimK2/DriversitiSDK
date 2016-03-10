//
//  VehicleManager.h
//  DriversitiSDK
//
//  Created by Anthony Spinelli on 8/16/15.
//  Copyright (c) 2015 Apio. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APVehicle+CoreDataProperties.h"
#import "APMatchFilter.h"

@interface VehicleManager : NSObject
/** The vehicle Apio has identified, or nil if not in a vehicle or vehicle not yet identified */
@property (nonatomic, readonly) APVehicle *currentVehicle;

+ (instancetype)sharedInstance;

/**
 Retrieve a vehicle for a given UUID
 
 @param uuid UUID of the vehicle you are retrieving
 
 @return vehicle for the corresponding UUID, nil if vehicle is not found
 */
- (APVehicle*)vehicleWithUuid:(NSString*)uuid;

/**
 Register vehicle to the Apio cloud
 
 @param name                Name for the vehicle
 @param vehicleModel        Model of the vehicle
 @param vehicleMake         Make of the vehicle
 @param vehicleYear         Year of the vehicle
 @param vehicleLicensePlate Vehicle license plate
 @param vehicleColor        Color of the vehicle
 @param vehicleMPG          Vehicle MPG
 @param vin                 VIN of the vehicle
 @param block               Completion block returning both the newly added vehicle and any errors
 */
- (void)vehicleRegisterWithName:(NSString*)name
                   vehicleModel:(NSString*)vehicleModel
                    vehicleMake:(NSString*)vehicleMake
                    vehicleYear:(NSUInteger)vehicleYear
            vehicleLicensePlate:(NSString*)vehicleLicensePlate
                   vehicleColor:(NSString*)vehicleColor
                     vehicleMPG:(float)vehicleMPG
                            vin:(NSString*)vin
                completionBlock:(void (^)(APVehicle *newVehicle,NSError *error))block;
- (void)vehicleUpdate:(APVehicle*)vehicle
              newName:(NSString*)name
             newModel:(NSString*)model
              newMake:(NSString*)make
              newYear:(NSUInteger)year
      newLicensePlate:(NSString*)licensePlate
             newColor:(NSString*)color
               newMPG:(float)mpg
               newVin:(NSString*)vin
      completionBlock:(void (^)(NSError *))block;

/**
 Retrieve all vehicles from the SDK
 @return Array of vehicles
 */
- (NSArray*)vehicles;

/**
 Adds new match filters to an existing vehicle. Match filters are returned from vehicleTrainingStop
 @param matchFilter <#matchFilter description#>
 @param vehicle     <#vehicle description#>
 @return YES if successful, NO if error
 */
- (BOOL)addMatchFilter:(APMatchFilter *)matchFilter forVehicle:(APVehicle *)vehicle;

/**
 Returns the number of match filters saved for the given vehicle.
 @param vehicle <#vehicle description#>
 @return <#return value description#>
 */
- (NSUInteger)matchFilterCountForVehicle:(APVehicle *)vehicle;


/**
 Deletes the given vehicle and its match filters
 
 @param vehicle Vehicle to delete
 @param block   Block to call upload completion. If Error != nil, then the vehicle was not able to be deleted
 */
- (void)vehicleDelete:(APVehicle *)vehicle completionBlock:(void (^)(NSError *error))block;

-(void)setCurrentVehicle:(APVehicle *)currentVehicle;

@end
