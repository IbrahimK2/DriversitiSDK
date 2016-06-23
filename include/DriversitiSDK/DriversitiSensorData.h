//
//  APSensorData.h
//  Apio
//
//  Created by Thomas Aylesworth on 8/28/13.
//  Copyright (c) 2013 Apio Systems LLC. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>
#import <CoreMotion/CoreMotion.h>
#import "APTripEvent+CoreDataProperties.h"

typedef NS_ENUM(NSInteger, ApioEventType)
{
    NONE=0,
    WALKING_START_EVENT,
    WALKING_STOP_EVENT,//Remember, walking is going to become, walking in bag, walking in hand, walking in pocket, etc...
    CAR_ENTRY_EVENT=100,
    CAR_EXIT_EVENT,
    CAR_MODE_START_EVENT=200,//This is going to become, Car Event because if car identified, or car mode event due to GPS (i.e.: You’ve move beyond some speed)
    CAR_MODE_STOP_EVENT,
    CAR_ID_ESTABLISHED,
    HARD_BREAK_EVENT=300,
    FAST_ACCELERATION_EVENT,//Currently these (brake, acceleration, speeding and braking) are done in the app - they’re moving to the SAL
    SPEEDING_EVENT,
    SAFE_SPEED_RESUMED
};


/**
 *  An APSensorData object encapsulates the collected sensor data.
 */
__attribute__ ((deprecated))
@interface DriversitiSensorData : NSObject

@property(nonatomic) NSInteger eGpsMonitoringState;//In high precision, georegion, off

@property (nonatomic, assign) double speedingThreshold;
@property (nonatomic, readonly, strong) NSDate * date;
@property (nonatomic, readonly) NSTimeInterval timestamp;
@property (nonatomic, readonly, strong) CLLocation * location;
@property (nonatomic, readonly) NSTimeInterval locationTimestamp;
@property (nonatomic, readonly, strong) CLHeading * heading;
@property (nonatomic, readonly, strong) CMDeviceMotion * deviceMotion;
@property (nonatomic, readonly, strong) CMMagnetometerData * magneticField;
@property (nonatomic, readonly) CMAccelerometerData *rawAccelerometer;
@property (nonatomic, readonly) CMMotionActivity *activityDetection;

@property (nonatomic, assign)   int phoneState;
@property (nonatomic, assign)   int phonePose;
@property (nonatomic, assign)   BOOL carModeActive;
@property (nonatomic, assign)   BOOL walkingDetected;
@property (nonatomic, assign)   BOOL crashDetected;
@property (nonatomic, assign)   int vehicleID;
@property (nonatomic, strong)   NSString *vehicleUUID;
@property (nonatomic, assign)   ApioEventType eventType;

-(NSString*)toString;

/**
 *  Returns a pointer to a SALSensorData struct for use by the Sensor Analysis
 *  Library. Note that this pointer is valid only for the lifetime of the
 *  APSensorData object.
 */
//- (void *)salSensorData;

/**
 Returns an initialized APSensorData object.
 
 @param date                <#date description#>
 @param timestamp           <#timestamp description#>
 @param location            <#location description#>
 @param locationTimestamp   <#locationTimestamp description#>
 @param eGpsMonitoringState <#eGpsMonitoringState description#>
 @param heading             <#heading description#>
 @param deviceMotion        <#deviceMotion description#>
 @param rawMagneticField    <#rawMagneticField description#>
 @param acceleration        <#acceleration description#>
 @param accelerometer       <#accelerometer description#>
 @param motionActivity      <#motionActivity description#>
 
 @return <#return value description#>
 */
- (id)initWithDate:(NSDate *)date
         timestamp:(NSTimeInterval)timestamp
          location:(CLLocation *)location
 locationTimestamp:(NSTimeInterval)locationTimestamp
locationMonitoringState:(NSInteger)eGpsMonitoringState
           heading:(CLHeading *)heading
      deviceMotion:(CMDeviceMotion *)deviceMotion
  rawMagneticField:(CMMagnetometerData *)rawMagneticField
  rawAccelerometer:(CMAccelerometerData *)accelerometer
	 motionActivity:(CMMotionActivity *)motionActivity;

@end
