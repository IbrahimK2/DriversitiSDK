#ifndef DRIVERSITISDK_H
#define DRIVERSITISDK_H

//
//  ApioSDK.h
//  apioSDK
//
//  Created by Anthony Spinelli on 5/16/14.
//  Copyright (c) 2014 Apio. All rights reserved.
//

#import "APMatchFilter+extension.h"
#import "DriversitiEventDefs.h"
#import "DriversitiSensorData.h"
#import "TripManager.h"
#import "UserManager.h"
#import "VehicleManager.h"

@class FDataSnapshot;

void DriversitiLog(NSString* _Nonnull format, ...);


#define DRIVERSITI_SDK_VERSION    @"0.9.15"
#define DRIVERSITI_SDK_DATE       @"2016.5.2"

#define METERS_PER_SECOND_TO_MPH 2.23694

@class FDataSnapshot;

typedef NS_ENUM(NSInteger, CMMotionManagerMotionType)
{
    MotionTypeUnitialized = -1,
    MotionTypeUnknown=      0,
    MotionTypeNotMoving=    0x000001,
    MotionTypeWalking=      0x000010,
    MotionTypeRunning=      0x000100,
    MotionTypeCycling=      0x001000,
    MotionTypeAutomotive=   0x010000,
};

typedef struct {
    int numInitialSamples;
    int minEntrySamples;
    int maxEntrySamples;
    int minExitSamples;
    int maxExitSamples;
} SampleRequirements;

#pragma mark -

/**
 The ApioPhoneBatteryDelegate protocol defines methods used to report battery charging status, this
 is intended to be used to manage power hungry settings
 */
__attribute__ ((deprecated))
@protocol DriversitiPhoneBatteryDelegate<NSObject>
@optional
/**
 Tells the delegate that the phone has been plugged in to or unplugged from power
 @param isCharging TRUE if battery is charging
 */

- (void)batteryCharging:(BOOL)isCharging __attribute__ ((deprecated));
- (void)batteryLevel:(float)batteryLevel __attribute__ ((deprecated));

@end

/**
 The ApioSensorDelegate is used to notify the delegate (sensorDelegate) when a sensor based event occurs
 */
@protocol DriversitiSensorDelegate <NSObject>
@optional
/**
 Used to capture ALL raw sensor data in the app

 @param detections <#detections description#>
 @param sensorData Sensor raw data structure
 @param timestamp  <#timestamp description#>
 @note This function can be used in lieu of ALL of the other delegate functions

 @deprecated v0.9.13.9
 @unavailable v0.9.15

 @warning Deprecated in favor of specific delegate methods and `sensorSALRawData:timeStamp:`

 */
-(void)sensorRawData:(void * const _Nullable)detections sensorData:(DriversitiSensorData* _Nullable )sensorData timeStamp:(NSTimeInterval)timestamp UNAVAILABLE_ATTRIBUTE;

/**
 Tells the delegate that sensor data has been analyzed.

 @param currentLocation location when SAL last updated analysis
 @param timestamp time SAL last updated analysis
 */
-(void)sensorSALRawData:(CLLocation * _Nullable)currentLocation timeStamp:(NSTimeInterval)timestamp;

/**
 Tells the delegate that the user's location has been updated

 @param location Updated device location
 
 @deprecated v0.9.15
 @warning Deprecated in favor of CoreLocation manager

 */
- (void)sensorLocationUpdate:(CLLocation * _Nullable)location DEPRECATED_MSG_ATTRIBUTE("use CoreLocation manager instead");

/**
 Tells the delegate that the user's walking state has changed

 @param isWalking TRUE if the user is walking
 @param location  Location of event
 */
- (void)sensorWalkingDidChange:(BOOL)isWalking location:(CLLocation * _Nullable)location;

/**
 Tells the delegate that the car mode has changed

 @param carMode             TRUE if Apio has detected the device is in a car.
 @param wasBasedOnDetection TRUE, If the Car mode change was based on sensor detection; FALSE if detected was based on physical movement
 @param wasBasedOnBeacon    *DEPRECATED* Will always return FALSE
 @param location            Location of where the event took place

 @deprecated v0.9.13.5
 @unavailable v0.9.15

 @warning Deprecated in favor of `sensorCarModeDidChange:wasBasedOnDetection:atLocation:`

 */
- (void)sensorCarModeDidChange:(BOOL)carMode wasBasedOnDetection:(BOOL)wasBasedOnDetection wasBasedOnBeacon:(BOOL)wasBasedOnBeacon atLocation:(CLLocation * _Nullable)location UNAVAILABLE_ATTRIBUTE;

/**
 Tells the delegate that the car mode has changed

 @param carMode             TRUE if Apio has detected the device is in a car.
 @param wasBasedOnDetection TRUE, If the Car mode change was based on sensor detection; FALSE if detected was based on physical movement
 @param location            Location of where the event took place
 */
- (void)sensorCarModeDidChange:(BOOL)carMode wasBasedOnDetection:(BOOL)wasBasedOnDetection atLocation:(CLLocation * _Nullable)location;

/**
 Tells the delegate that the car has been identified

 @param vehicle          the vehicle that has been identified
 @param location         Location of where the event took place
 @param detectedByBeacon *DEPRECTED* Will always return FALSE

 @deprecated v0.9.13.5
 @unavailable v0.9.15

 @warning Deprecated in favor of `sensorIdentifiedCar:location:`
 */
- (void)sensorIdentifiedCar:(APVehicle* _Nullable)vehicle location:(CLLocation * _Nullable)location detectedByBeacon:(BOOL)detectedByBeacon UNAVAILABLE_ATTRIBUTE;

/**
 Tells the delegate that the car has been identified

 @param vehicle          the vehicle that has been identified
 @param location         Location of where the event took place
 */
- (void)sensorIdentifiedCar:(APVehicle* _Nullable)vehicle location:(CLLocation * _Nullable)location;


/**
 Tells the delegate that a new car has been identified

 @param vehicle          the vehicle that has been identified
 @param location         Location of where the event took place
 */
- (void)sensorIdentifiedNewCar:(APVehicle* _Nullable)vehicle location:(CLLocation * _Nullable)location;

/**
 Tells the delegate that vehicle ignition was detected

 @param location Location of where the event took place
 */
- (void)sensorVehicleIgnitionDetectedAtLocation:(CLLocation * _Nullable)location;

/**
 Tells the delegate that the vehicle's speed has gone above or fallen below the speeding threshold

 @param isSpeeding TRUE if the user is exceeding the speeding threshold
 @param location   Location of where the event took place, including the speed in m/s
 */
- (void)sensorSpeedThresholdExceeded:(BOOL)isSpeeding location:(CLLocation * _Nullable)location;

/**
  Tells the delegate that the vehicle's acceleration has exceeded the safe threshold.
 @param location   Location of where the event took place, including the speed in m/s
 */
- (void)sensorAccelerationThresholdExceededAtLocation:(CLLocation * _Nullable)location;

/**
 Tells the delegate that the vehicle's deceleration has exceeded the safe threshold.
 @param location   Location of where the event took place, including the speed in m/s
 */
- (void)sensorDecelerationThresholdExceededAtLocation:(CLLocation * _Nullable)location;

/**
 Tells the delegate that phone handling was detected.
 @param handlingType	The type of handling, whether by the driver(Handling, texting, phone call) or passenger(Handling, texting, phone call)
 @param location   Location of where the event took place, including the speed in m/s
 */
- (void)sensorHandlingDetected:(DriversitiHandlingAwareness)handlingType atLocation:(CLLocation * _Nullable)location;

/**
 Tells the delegate that vehicle entry was detected.
 @param eEntryPosition	This is the point the user entered from.  left(Front,back), right(Front,back)
 @param location   Location of where the event took place, including the speed in m/s
 */
- (void)sensorVehicleEntryDetected:(DriversitiEntryAwareness)eEntryPosition atLocation:(CLLocation * _Nullable)location  __attribute__ ((deprecated));;

/**
 Tells the delegate that a crash was detected.
 @param location   Location of where the event took place, including the speed in m/s
 */
- (void)sensorCrashDetectedAtLocation:(CLLocation * _Nullable)location;

/**
 Tells the delegate that the driver appears distracted
 @param location   Location of where the event took place, including the speed in m/s
 */
- (void)sensorDistractionDetectedAtLocation:(CLLocation * _Nullable)location;

/**
 Tells the delegate that the driver no longer appears distracted.
 @param location   Location of where the event took place, including the speed in m/s
 */
- (void)sensorDistractionStoppedAtLocation:(CLLocation * _Nullable)location;

-(void)remoteSensorConfigurationReceived:(FDataSnapshot * _Nullable)configureSnapShot;

-(void)sensorDidExitRegion:(CLRegion* _Nullable)region;
-(void)sensorDidEnterRegion:(CLRegion* _Nullable)region;

/**
 Tells the delegate that the sensor suite was unable to run
 @param error Error indicating why the sensor suite stopped running
 */
- (void)sensorDidFailWithError:(NSError * _Nullable)error;

@end

@protocol DriversitiVehicleIdCaptureDelegate <NSObject>

- (void)vehicleIdCaptureDidStartGettingData;

/**
 *  Tells the delegate that the capture session had an unrecoverable error
 *
 *  @param error Error value indicating while vehicle ID capture failed
 */
- (void)vehicleIdCaptureDidFailWithError:(NSError * _Nullable)error;

@end

#pragma mark -
/** The DriversitiSDK class is the main class used in accessing the Apio SDK. This class maintains a singleton instance
 that can be retrieved through the sharedInstance class method.

 Generally, the SDK usage steps are:

 - Register a user using [UserManager userRegisterWithEmailAddress:password:firstName:middleName:lastName:streetAddress:city:state:country:zipcode:phoneNumber:username:companyId:completionBlock:]
 - Registering a vehicle using [VehicleManager vehicleRegisterWithName:vehicleModel:vehicleMake:vehicleYear:vehicleLicensePlate:vehicleColor:vehicleMPG:vin:completionBlock:]
 - To start and stop the collection of events see startDataCollection and stopDataCollection
 - For handling of detected events set the sensorDelegate and see the ApioSensorDelegate documentation
 - Displaying trip/event information

 */

@interface DriversitiSDK : NSObject

+(NSString* _Nullable)salVersion;

+(NSString* _Nullable)sdkVersion;

/**
 Provides a mechanism for the application to log into the same file
 as the SAL. Useful for allowing Apio to see the information the app
 is seeing/logging.

 @param logMsg Message to log
 */
-(void)logMessage:(NSString * _Nullable)logMsg;

/**
 Enable the SDK to automatically start and stop trips with no integrator's interaction.
 This will cause trips to corresponds 1 for 1 with carMode ON/OFF events.

 Defaults to true. Set to false to manually control trip start/stop
 */
@property(nonatomic, assign) BOOL autoHandleTripStartStop;

/**
 Set to TRUE to enable power saving mode. Will only activave power saving mode if the
 motion coprocessor is available and accessible
 */
@property (nonatomic, assign) BOOL powerSavingMode;

/**
 Used for distracted driver events. The user can set if the
 driver sits on the left or right side of the vehicle.
 FALSE if the driver sits on the right side of the vehicle. Defaults to true(left side).
 */
@property(nonatomic, assign) BOOL driverSitsOnVehiclesLeftSide;

/**
 Provides the SAL Version so the SDK caller can retrieve that information.
*/
@property (nonatomic, readonly) NSString * _Nullable salVersion;

@property (nonatomic, strong) NSOperationQueue* _Nullable operationQueue;

#pragma mark Sensor Delegate
/** The delegate used to capture all reported APIO events */
@property (nonatomic, weak) id <DriversitiSensorDelegate>  _Nullable           sensorDelegate;

/** The delegate used to capture vehicle ID capture start and/or error events */
@property (nonatomic, weak) id <DriversitiVehicleIdCaptureDelegate> _Nullable  vehicleCaptureDelegate;

/** The delegate used to detect the phone has been plugged in to a power source */
@property (nonatomic, weak) id <DriversitiPhoneBatteryDelegate>  _Nullable     batteryChargingDelegate DEPRECATED_ATTRIBUTE;

#pragma mark Device Modes
/** @name Device Modes */

/** Indicates whether Apio client has been started */
@property (nonatomic, readonly) BOOL isRunning;

/** Indicates whether Apio has deteremined the user is walking  */
@property (nonatomic, readonly) BOOL isWalking;

/** Indicates whether Apio has determined the user is in a vehicle */
@property (nonatomic, readonly) BOOL isInVehicle;

/** Current battery level as a float from 0-100 */
@property (nonatomic, readonly) float batteryLevel;

/** Last reported battery level as a float from 0-100 */
@property (nonatomic, assign) float lastReportedBatteryLevel;

/** Boolean to indicate whether the device battery is charging or not */
@property (nonatomic, readonly) BOOL batteryCharging;

/** Delete data that is older than this AND has been uploaded to the cloud */
@property (nonatomic, readonly) NSUInteger numberDaysKeepData;

#pragma mark - Initialization
/** @name Initialization */
/**
 Returns the singleton instance of the ApioSDK

 @return ApioSDK singleton instance
 */
+ (instancetype _Nonnull)sharedInstance;

/**
 Provide API key for using the Apio SDK

 @param apiKey <#apiKey description#>
 */
- (void)setAPIKey:(NSString* _Nullable)apiKey;

/**
 Start the SDK with the launch options from the app delegate

 @param launchOptions Launch options from app delegate
 */
- (void)startWithLaunchOptions:(NSDictionary * _Nullable)launchOptions;

/**
 Enables logging of sensor data for debug purposes

 @return TRUE is logging was enabled
 */
- (BOOL)enableSensorLogging;

/**
 Disables logging of sensor data for debug purposes

 */
- (void)disableSensorLogging;

/**
 This represents the absolute file path (File Name inclusive) which is created to
 allow the internal Apio logging. You need to call this before turning logging off,
 since turning off the logging functionality will close the file.

 @return The absolute path of the logging file. nil if either the file is closed or has not been created.
 */
-(NSString * _Nullable)currentLogFileAbsolutePath;

/** @name Settings */
#pragma mark - Settings

/**
 Set the speeding event threshold value

 @param speed value to set the speeding threshold to
 */
-(void)setSpeedingThresholdInMPH:(CGFloat)speed;
-(void)setSpeedingThresholdInMPS:(CGFloat)speed;//Meters per Second

/**
 Retrieve the speeding threshold

 @return Value of the speeding threshold in MPH
 */
-(CGFloat)speedingThresholdInMPH;

#pragma mark - Cloud handling
/** @name Cloud handling */

/**
 Enable/Disable cloud features. By default, these features are ENABLED

 @param enabled NO to disable cloud
 */
-(void)setCloudEnabled:(BOOL)enabled;

#pragma mark - APApioClient Interface (DEPRECATED)
/** @name APApioClient Interface */

#pragma mark - Apio Client
/** @name Apio Client */

/**
 Start sensor data collection.
 */
- (void) startDataCollection;


/**
 Stops sensor data collection.
 */
- (void) stopDataCollection;

/**
 The APsensorDelegate protocol defines the methods used to receive
 sensor event notifications from an APsensor object.
 */
#pragma mark - Sensor Information
/** @name Sensor Information */

/**
 The user's current speed in miles per hour, or -1 if unknown.
 */
- (NSInteger) speedMph;


/** En/Dis-able the filtering of events. This is enabled by default. With this DISabled,
 duplicate events may be sent, events that may not make sense could be sent, etc. For example,
 it's possible to receive a crash event and then an erroneous 'exit vehicle' event or upon
 vehicle entry there may be multiple 'vehicle entry' events sent.


 @param enabled NO to disable filtering
 @note This is 'enabled' by default
 */
- (void)sensorEventFiltering:(BOOL)enabled;

/**
 Enables generic templates. The state of this is persisted across runs of the framework

 @param enabled YES to enable generic templates, NO otherwise
 @note This will cause a re-start of the sensor management framework which can take a few seconds
 */
- (void)setGenericTemplatesEnabled:(BOOL)enabled;

/**
 Returns whether generic templates are enabled or not

 @return YES if generic templates are currently enabled, no otherwise
 */
- (BOOL)genericTemplatesEnabled;

#pragma mark - Vehicle Handling
/** @name Vehicle Handling */

/**
 Is Car Mode Active?

 @return TRUE if car mode is active, false otherwise
 */
- (BOOL)carModeActive;


#pragma mark - Event Handling
/** @name Event Handling */
/**
 Retrieve all of the events for a given trip

 @param trip Trip to retrieve events for

 @return NSArray of APTripEvent objects
 */
-(NSArray* _Nullable)eventsForTrip:(APTrip* _Nullable)trip;

/**
 Retrieve an event given an event ID

 @param ID eventID for the event to retrieve

 @return APTripEvent for the given ID, nil if the event can't be found
 */
-(APTripEvent* _Nullable)eventForID:(NSString* _Nullable)ID;

@end

#endif
