//
//  ApioSDK.h
//  apioSDK
//
//  Created by Anthony Spinelli on 5/16/14.
//  Copyright (c) 2014 Apio. All rights reserved.
//

#import "DriversitiEventDefs.h"
#import "DriversitiSensorData.h"
#import <CoreGraphics/CGBase.h>
#import "TripManager.h"
#import "UserManager.h"
#import "VehicleManager.h"
#import "MobileDeviceManager.h"
#import "DriversitiEvent.h"

@class FDataSnapshot;

void DriversitiLog(NSString* _Nullable format, ...);

#pragma mark -

/**
 The ApioPhoneBatteryDelegate protocol defines methods used to report battery charging status, this
 is intended to be used to manage power hungry settings
 */
__attribute__ ((unavailable))
@protocol DriversitiPhoneBatteryDelegate<NSObject>
@optional
	-(void)batteryCharging:(BOOL)isCharging __attribute__ ((unavailable));
	-(void)batteryLevel:(float)batteryLevel __attribute__ ((unavailable));
@end

#pragma mark -

__attribute__ ((unavailable))
@protocol DriversitiVehicleIdCaptureDelegate <NSObject>
	-(void)vehicleIdCaptureDidStartGettingData __attribute__ ((unavailable));
	-(void)vehicleIdCaptureDidFailWithError:(nullable NSError *)error __attribute__ ((unavailable));
@end

/**
 The ApioSensorDelegate is used to notify the delegate (sensorDelegate) when a sensor based event occurs
 */
@protocol DriversitiSensorDelegate <NSObject>
@optional

	-(void)sensorDidExitRegion:(nullable CLRegion*)region __attribute__((deprecated("Will become unavailable in the next interation.")));
	-(void)sensorDidEnterRegion:(nullable CLRegion*)region __attribute__((deprecated("Will become unavailable in the next interation.")));
	-(void)sensorDidFailWithError:(nullable NSError *)error __attribute__((deprecated("Will become unavailable in the next interation.")));
	-(void)sensorLocationUpdate:(nullable CLLocation *)location __attribute__((deprecated("Will become unavailable in the next interation.")));
	-(void)sensorVehicleIgnitionDetectedAtLocation:(nullable CLLocation *)location __attribute__((deprecated("Will become unavailable in the next interation.")));
	-(void)sensorIdentifiedNewCar:(nullable APVehicle*)vehicle location:(nullable CLLocation *)location __attribute__((deprecated("Will become unavailable in the next interation.")));
	-(void)sensorVehicleEntryDetected:(DriversitiEntryAwareness)eEntryPosition atLocation:(nullable CLLocation *)location __attribute__((deprecated("Will become unavailable in the next interation.")));
	-(void)sensorIdentifiedCar:(nullable APVehicle*)vehicle location:(nullable CLLocation *)location detectedByBeacon:(BOOL)detectedByBeacon __attribute__((deprecated("Will become unavailable in the next interation.")));

	/**
	 Used to capture ALL raw location data in the app
 
	 @param currentLocation The GPS reading used to determine the user's current location and speed
	 @param timestamp  The time of the GPS reading
	 
	 NOTE: If you have called the method "sensorEventFiltering:(BOOL)" with true, you will not get this call.
	 If you've called "sensorEventFiltering:(BOOL)" you will get this call at the frequency contained in the
	 "currentSamplingRate" property.
	 */
	-(void)sensorSALRawData:(nullable CLLocation *)currentLocation
					  timeStamp:(NSTimeInterval)timestamp;

	/**
	 Tells the delegate that the user's walking state has changed
 
	 @param isWalking TRUE if the user is walking
	 @param location  Location of event
	 */
	-(void)sensorWalkingDidChange:(BOOL)isWalking location:(nullable CLLocation *)location;

	/**
	 Tells the delegate that the car mode has changed

	 @param carMode             TRUE if Apio has detected the device is in a car.
	 @param wasBasedOnDetection TRUE, If the Car mode change was based on sensor detection; FALSE if detected was based on physical movement
	 @param location            Location of where the event took place
	 */
	-(void)sensorCarModeDidChange:(BOOL)carMode wasBasedOnDetection:(BOOL)wasBasedOnDetection atLocation:(nullable CLLocation *)location;

	/**
	 Tells the delegate that the vehicle's speed has gone above or fallen below the speeding threshold

	 @param isSpeeding TRUE if the user is exceeding the speeding threshold
	 @param location   Location of where the event took place, including the speed in m/s
	*/
	-(void)sensorSpeedThresholdExceeded:(BOOL)isSpeeding location:(nullable CLLocation *)location;

	/**
	 Tells the delegate that the vehicle's acceleration has exceeded the safe threshold.
	 @param location   Location of where the event took place, including the speed in m/s
	*/
	-(void)sensorAccelerationThresholdExceededAtLocation:(nullable CLLocation *)location;

	/**
	 Tells the delegate that the vehicle's deceleration has exceeded the safe threshold.
	 @param location   Location of where the event took place, including the speed in m/s
	*/
	-(void)sensorDecelerationThresholdExceededAtLocation:(nullable CLLocation *)location;

	/**
	 Tells the delegate that the vehicle's driver has been rapidly changing lanes in an safe manner.
	 @param location: Location of where the event took place, including the speed in m/s
	*/
	-(void)sensorDangerouseLaneChangingAtLocation:(nullable CLLocation *)location;

	/**
	 Tells the delegate that phone handling was detected.
	 @param handlingType	The type of handling, whether by the driver(Handling, texting, phone call) or passenger(Handling, texting, phone call)
	 @param location   Location of where the event took place, including the speed in m/s
	*/
	-(void)sensorHandlingDetected:(DriversitiHandlingAwareness)handlingType atLocation:(nullable CLLocation *)location;

	/**
	 Tells the delegate that phone handling status has changed. ie: The user has handling the phone while driving, and though
	 they're still handling the phone, the handling has changed to handling while not in motion.

	 @param handlingType	The type of handling, whether by the driver(Handling, texting, phone call) or passenger(Handling, texting, phone call)
	 @param location Location of where the event took place, including the speed in m/s
	*/
	-(void)sensorHandlineDetectionStateUpdate:(DriversitiHandlingAwareness)eUpdatedHandlingState atLocation:(nullable CLLocation *)location;

	/**
	 Tells the delegate that a crash was detected.

	 @param location   Location of where the event took place, including the speed in m/s
	*/
	-(void)sensorCrashDetectedAtLocation:(nullable CLLocation *)location;

	/**
	 Tells the delegate that the driver appears distracted

	 @param location   Location of where the event took place, including the speed in m/s
	*/
	-(void)sensorDistractionDetectedAtLocation:(nullable CLLocation *)location;

	/**
	 Tells the delegate that the driver no longer appears distracted.

	 @param location   Location of where the event took place, including the speed in m/s
	*/
	-(void)sensorDistractionStoppedAtLocation:(nullable CLLocation *)location;


@end

#pragma mark -
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
	@property (nonatomic, readonly) BOOL batteryCharging __attribute__((deprecated("Will become unavailable in the next interation.")));
	@property (nonatomic, assign) float lastReportedBatteryLevel __attribute__((deprecated("Will become unavailable in the next interation.")));
	@property (nonatomic, readonly) float batteryLevel __attribute__((deprecated("Will become unavailable in the next interation.")));
	@property (nonatomic, readonly) BOOL isWalking __attribute__((deprecated("Will become unavailable in the next interation.")));
	@property (nullable, nonatomic, weak) id <DriversitiPhoneBatteryDelegate> batteryChargingDelegate __attribute__((unavailable));
	@property (nonatomic, assign) BOOL powerSavingMode __attribute__((deprecated("Will become unavailable in the next interation.")));
	@property (nonatomic, readonly) BOOL isInVehicle __attribute__((deprecated("Will become unavailable in the next interation.")));

	+(nullable NSString*)salVersion __attribute__((deprecated("Call the salVersion property instead")));
	-(void)enableSensorLogging __attribute__((deprecated("Will become unavailable in the next interation.")));
	-(void)disableSensorLogging __attribute__((deprecated("Will become unavailable in the next interation.")));
	-(void)logMessage:(nullable NSString *)logMsg __attribute__((deprecated("Will become unavailable in the next interation.")));
	-(nullable NSString *)currentLogFileAbsolutePath __attribute__((deprecated("Will become unavailable in the next interation.")));
	-(nullable NSArray*)eventsForTrip:(nullable APTrip*)trip __attribute__((deprecated("Will become unavailable in the next interation. Use the TripsManager to get events associated with a trip.")));
	-(nullable APTripEvent*)eventForID:(nullable NSString*)ID __attribute__((deprecated("Will become unavailable in the next interation. Use the TripsManager to get events associated with a trip.")));

	@property (nullable, nonatomic, strong) NSOperationQueue* operationQueue;

	/**
	 Set to TRUE to enable the SDK to automatically start and stop trips with no integrator's interaction.
	 This will cause trips to corresponds 1 for 1 with carMode ON/OFF events.
	*/
	@property(nonatomic, assign) BOOL autoHandleTripStartStop;

	/**
	 Used for distracted driver events. The user can set if the
	 driver sits on the left or right side of the vehicle.

	 FALSE if the driver sits on the right side of the vehicle.
	*/
	@property(nonatomic, assign) BOOL driverSitsOnVehiclesLeftSide;

	/**
	 Provides the caller with the SDK Version.
	*/
	@property(nonnull, nonatomic, readonly) NSString *sdkVersion;

	/**
	 Provides the SAL Version used by the SDK.
	*/
	@property(nullable, nonatomic, readonly) NSString *salVersion;

	@property(nonatomic, readonly) double currentSamplingRate;

#pragma mark Sensor Delegate
	/** The delegate used to capture all reported APIO events */
	@property (nullable, nonatomic, weak) id <DriversitiSensorDelegate> sensorDelegate;

#pragma mark Device Modes
	/** @name Device Modes */

	/** Indicates whether Apio client has been started */
	@property (nonatomic, readonly) BOOL isRunning;


	/** Delete data that is older than this AND has been uploaded to the cloud */
	@property (nonatomic, readonly) NSUInteger numberDaysKeepData;

#pragma mark - Initialization
	/** @name Initialization */
	/**
	 Returns the singleton instance of the ApioSDK
 
	 @return ApioSDK singleton instance
	 */
	+(nonnull instancetype)sharedInstance;

	/**
	 Provide API key for using the Apio SDK
 
	 @param apiKey
	*/
	-(void)setAPIKey:(nullable NSString*)apiKey;

	/**
	 Start the SDK with the launch options from the app delegate
 
	 @param launchOptions Launch options from app delegate
	*/
	-(void)startWithLaunchOptions:(nullable NSDictionary *)launchOptions;

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
	-(void)startDataCollection;

	/**
	 Stops sensor data collection.
	*/
	-(void)stopDataCollection;

/**
 The APsensorDelegate protocol defines the methods used to receive
 sensor event notifications from an APsensor object.
 */
#pragma mark - Sensor Information
/** @name Sensor Information */

	/**
	The user's current speed in miles per hour, or -1 if unknown.
	*/
	-(NSInteger)speedMph;

	/** Enable/Disable the filtering of events. This is enabled by default. With this DISabled,
	duplicate events may be sent, events that may not make sense could be sent, etc. For example,
	it's possible to receive a crash event and then an erroneous 'exit vehicle' event or upon
	vehicle entry there may be multiple 'vehicle entry' events sent.

	@param enabled NO to disable filtering
	@note This is 'enabled' by default
	*/
	-(void)sensorEventFiltering:(BOOL)enabled;

#pragma mark - Vehicle Handling
/** @name Vehicle Handling */

	/**
	Is Car Mode Active?
 
	@return TRUE if car mode is active, false otherwise
	*/
	-(BOOL)carModeActive;

@end
