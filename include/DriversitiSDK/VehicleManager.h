//
//  VehicleManager.h
//  DriversitiSDK
//
//  Created by Anthony Spinelli on 8/16/15.
//  Copyright (c) 2015 Apio. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APVehicle+CoreDataProperties.h"

__attribute__ ((deprecated("This class no longer servers a purpose and will be made unavailable in the next iteration")))
@interface VehicleManager : NSObject
/** The vehicle Apio has identified, or nil if not in a vehicle or vehicle not yet identified */
@property (nonatomic, readonly, nullable) APVehicle *currentVehicle __attribute__((deprecated));

+ (nonnull instancetype)sharedInstance;

/**
 Retrieve a vehicle for a given UUID
 
 @param uuid UUID of the vehicle you are retrieving
 
 @return vehicle for the corresponding UUID, nil if vehicle is not found
 */
- (nullable APVehicle*)vehicleWithUuid:(nullable NSString*)uuid;

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
- (void)vehicleRegisterWithName:(nullable NSString*)name
                   vehicleModel:(nullable NSString*)vehicleModel
                    vehicleMake:(nullable NSString*)vehicleMake
                    vehicleYear:(NSUInteger)vehicleYear
            vehicleLicensePlate:(nullable NSString*)vehicleLicensePlate
                   vehicleColor:(nullable NSString*)vehicleColor
                     vehicleMPG:(float)vehicleMPG
                            vin:(nullable NSString*)vin
                completionBlock:(nullable  void (^)(APVehicle * _Nullable newVehicle, NSError * _Nullable error))block __attribute__((deprecated));

- (void)vehicleUpdate:(nullable APVehicle*)vehicle
              newName:(nullable NSString*)name
             newModel:(nullable NSString*)model
              newMake:(nullable NSString*)make
              newYear:(NSUInteger)year
      newLicensePlate:(nullable NSString*)licensePlate
             newColor:(nullable NSString*)color
               newMPG:(float)mpg
               newVin:(nullable NSString*)vin
      completionBlock:(nullable void (^)(NSError * _Nullable error))block  __attribute__((deprecated));

/**
 Retrieve all vehicles from the SDK
 @return Array of vehicles
 */
-(nullable NSArray*)vehicles;

/**
 Returns the number of match filters saved for the given vehicle.
 @param vehicle <#vehicle description#>
 @return <#return value description#>
 */
-(NSUInteger)matchFilterCountForVehicle:(nullable APVehicle *)vehicle __attribute__ ((deprecated));

/**
 Deletes the given vehicle and its match filters
 
 @param vehicle Vehicle to delete
 @param block   Block to call upload completion. If Error != nil, then the vehicle was not able to be deleted
 */
-(void)vehicleDelete:(nullable APVehicle *)vehicle completionBlock:(nullable void (^)(NSError * _Nullable error))block  __attribute__((deprecated));

-(void)setCurrentVehicle:(nullable APVehicle *)currentVehicle  __attribute__((deprecated));

@end
