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
@property (nonatomic, readonly) APVehicle *  _Nullable currentVehicle;

+ (instancetype _Nonnull)sharedInstance;

/**
 Retrieve a vehicle for a given UUID
 
 @param uuid UUID of the vehicle you are retrieving
 
 @return vehicle for the corresponding UUID, nil if vehicle is not found
 */
- (APVehicle* _Nullable)vehicleWithUuid:(NSString* _Nullable)uuid;

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
- (void)vehicleRegisterWithName:(NSString* _Nullable)name
                   vehicleModel:(NSString* _Nullable)vehicleModel
                    vehicleMake:(NSString* _Nullable)vehicleMake
                    vehicleYear:(NSUInteger)vehicleYear
            vehicleLicensePlate:(NSString* _Nullable)vehicleLicensePlate
                   vehicleColor:(NSString* _Nullable)vehicleColor
                     vehicleMPG:(float)vehicleMPG
                            vin:(NSString* _Nullable)vin
                completionBlock:(void (^ _Nullable)(APVehicle * _Nullable newVehicle,NSError * _Nullable error))block;
- (void)vehicleUpdate:(APVehicle* _Nullable)vehicle
              newName:(NSString* _Nullable)name
             newModel:(NSString* _Nullable)model
              newMake:(NSString* _Nullable)make
              newYear:(NSUInteger)year
      newLicensePlate:(NSString* _Nullable)licensePlate
             newColor:(NSString* _Nullable)color
               newMPG:(float)mpg
               newVin:(NSString* _Nullable)vin
      completionBlock:(void (^ _Nullable)(NSError * _Nullable))block;

/**
 Retrieve all vehicles from the SDK
 @return Array of vehicles
 */
- (NSArray* _Nullable)vehicles;

/**
 Adds new match filters to an existing vehicle. Match filters are returned from vehicleTrainingStop
 @param matchFilter <#matchFilter description#>
 @param vehicle     <#vehicle description#>
 @return YES if successful, NO if error
 */
- (BOOL)addMatchFilter:(APMatchFilter * _Nullable)matchFilter forVehicle:(APVehicle * _Nullable)vehicle;

/**
 Returns the number of match filters saved for the given vehicle.
 @param vehicle <#vehicle description#>
 @return <#return value description#>
 */
- (NSUInteger)matchFilterCountForVehicle:(APVehicle * _Nullable)vehicle;


/**
 Deletes the given vehicle and its match filters
 
 @param vehicle Vehicle to delete
 @param block   Block to call upload completion. If Error != nil, then the vehicle was not able to be deleted
 */
- (void)vehicleDelete:(APVehicle * _Nullable)vehicle completionBlock:(void (^ _Nullable)(NSError * _Nullable error))block;

-(void)setCurrentVehicle:(APVehicle * _Nullable)currentVehicle;

@end
