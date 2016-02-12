//
//  APLocationSensor.h
//  Apio
//
//  Created by Thomas Aylesworth on 8/19/13.
//  Copyright (c) 2013 Apio Systems LLC. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>

#import "APBeacon+extension.h"

/**
 *  The APLocationDelegate protocol defines the methods used to report a
 *  new location.
 */
@protocol APLocationDelegate <NSObject>

/**
 *  Tells the delegate that the user's location has been updated.
 *  Only called when the location is reasonably accurate (within 100 meters)
 *  and only when last location was >= 1 minute ago and distance >= 10 meters.
 */
- (void)locationSensorDidUpdateLocation:(CLLocation *)location;
- (void)locationSensorThrowAwayLocation:(CLLocation *)location forReason:(NSString*)reason;


/**
 *  Tells the delegate that the user's speed exceeded the speeding threshold.
 */
- (void)locationSensorDidDetectSpeeding:(CLLocationSpeed)speed;

/**
 *  Tells the delegate that the user's speed has returned below the speeding threshold.
 */
- (void)locationSensorDidDetectStoppedSpeeding:(CLLocationSpeed)speed;

///**
// *  Tells the delegate that the user's acceleration has exceeded the safe threshold.
// *  
// *  @param acceleration Acceleration in meters / second^2
// */
//- (void)locationSensorDidDetectUnsafeAcceleration:(CGFloat)acceleration;
//
///**
// *  Tells the delegate that the user's deceleration has exceeded the safe threshold.
// *
// *  @param acceleration Deceleration in meters / second^2
// */
//- (void)locationSensorDidDetectUnsafeDeceleration:(CGFloat)deceleration;


#ifdef BEACONS_ENABLED

/**
  Used during beacon discovery
 
 @param beacons Array of CLBeacons
 */
-(void)locationSensorDiscoveryBeaconsProximityChanged:(NSArray*)beacons;

-(void)locationSensorBeaconProximityChanged:(APBeacon*)beacon;
-(void)locationSensorDidExitRegion:(CLRegion*)region;
-(void)locationSensorDidEnterRegion:(CLRegion*)region;
-(void)locationSensorTriggerIdForBeacon:(APBeacon*)beacon;

#endif

/**
 *  Tells the delegate that the the location sensor has an unrecoverable error.
 *  This is primarily used to indicate that the user has disabled location services.
 */
- (void)locationSensorDidFailWithError:(NSError *)error;

@end

/**
 *  An APLocationSensor object is used to monitor and provide the user's
 *  latest location data.
 */
@interface ApioLocationSensor : NSObject <CLLocationManagerDelegate>

@property (nonatomic, weak) id <APLocationDelegate> delegate;
@property (nonatomic) BOOL useGps;
@property (nonatomic) BOOL beaconDiscovery;
@property (nonatomic) CLLocationAccuracy locationAccuracy;
@property (nonatomic) CGFloat speedingThreshold;

@property (nonatomic, readonly) BOOL isRunning;
@property (nonatomic, readonly) BOOL hasValidLocation;
@property (nonatomic, readonly) CLLocation * location;
@property (nonatomic, readonly) CLHeading * heading;
@property (nonatomic, readonly) NSInteger currentGpsMonitoringState;

/**
 *  Returns an initialized APLocationSensor object.
 */
- (id)init;

/**
 *  This call is made after SALAnalyze is called if the SAL
 *  has indicated that high accuracy GPS is not currently needed.
 */
-(void)setGpsIntoLowPrecisionMode;

/**
 *  This call is made after SALAnalyze is called if the SAL
 *  has indicated that high accuracy GPS is currently needed.
 */
-(void)setGpsIntoHighPrecisionMode;

/**
 *  This call is made from the SDK Singleton which selects
 *  which version of low-power GPS to use. Either region monitoring
 *  or changing "desiredAccuracy" - which is refered to as significant change.
 *  NOTE: This is nothing more than setting a flag - it is NOT changing the
 *  GPS state at this point.
 */
//-(void)setGpsLowPowerMonitoringState:(GPSMONITORING_STATE)lowPowerState;

/**
 *  Starts monitoring user location and heading.
 */
- (BOOL)start;

/**
 *  Stops monitoring user location and heading.
 */
- (void)stop;

#ifdef BEACONS_ENABLED
///**
// *  Obtain the currently loaded beacons.
// */
//- (NSArray*)beacons;
//
///**
// *  Add an iBeacon
// *  @return TRUE on success, FALSE on invalid UUID
// */
//- (BOOL)addBeaconWithName:(NSString *)beaconName
//                     uuid:(NSString *)uuid
//                    major:(CLBeaconMajorValue)major
//                    minor:(CLBeaconMinorValue)minor;
//
///**
// *  Remove an iBeacon
// */
//-(void)removeBeaconWithUUID:(NSString *)uuid;
//-(void)removeBeaconWithName:(NSString *)name;

/**
 *  Indicates whether the app is recording an audio file.
 *
 *  @note This is intended only for capturing audio data for analysis and test purposes, specifically recording
 *        audio during airbag crash tests. A commercial audio recording capability should be use audio queues.
 */
-(void)startBeaconMonitoring;

/**
 *  Indicates whether the app is recording an audio file.
 *
 *  @note This is intended only for capturing audio data for analysis and test purposes, specifically recording
 *        audio during airbag crash tests. A commercial audio recording capability should be use audio queues.
 */
-(void)stopBeaconMonitoring;

/**
 *  Indicates whether the app is recording an audio file.
 *
 *  @note This is intended only for capturing audio data for analysis and test purposes, specifically recording
 *        audio during airbag crash tests. A commercial audio recording capability should be use audio queues.
 */
-(void)startBeaconRanging;

/**
 *  Indicates whether the app is recording an audio file.
 *
 *  @note This is intended only for capturing audio data for analysis and test purposes, specifically recording
 *        audio during airbag crash tests. A commercial audio recording capability should be use audio queues.
 */
-(void)stopBeaconRanging;

-(void)startRangingBeaconInRegion:(CLBeaconRegion*)region;
-(void)startRangingBeacon:(APBeacon*)beacon;
-(void)stopRangingBeaconInRegion:(CLBeaconRegion*)region;
-(void)stopRangingBeacon:(APBeacon*)beacon;
#endif
@end
