/*
 //  DeviceManager.h
 //  DriversitiSDK
 //
 //  Created by Jeff Behrbaum on 3/23/16.
 //  Copyright © 2016 Apio. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 The `DeviceSupportDelegate` protocol is adopted by an object wishing to receive notification
 that device support information is ready for querying.
 */
@protocol DeviceSupportDelegate <NSObject>
@required

/**
 Called once device support information is available to be queried from the `MobileDeviceManager`.

 @see MobileDeviceManager -retreiveSupportedDevices
 */
-(void)deviceSupportInfoIsReadyForEvaluation;
@end

/**
 Support Statuses
 */
typedef enum
{
	/** Support for this device is Unknown. */
	DEVICE_SUPPORT_UNKNOWN,
	/** Device is supported */
	DEVICE_SUPPORTED,
	/** Device is not currently supported */
	DEVICE_UNSUPPORTED
}DRIVERSITI_SDK_DEVICE_SUPPORT_LEVEL;

/**
 The `MobileDeviceManager` provides information regarding if `DriversitiSDK` supports the current device.
 
 Users request device support information through `-retreiveSupportedDevices` and are notified that the information
 is ready for querying through their supplied `DeviceSupportDelegate`.
 */
@interface MobileDeviceManager : NSObject

/**
 `DeviceSupportDelegate` that will be notified once -retreiveSupportedDevices has received device support information.
 */
@property(nonatomic, weak, nullable) id<DeviceSupportDelegate> deviceSupportDelegate;

/**
 Whether device support information is available yet.
 */
@property(nonatomic, readonly) BOOL bSupportedDevicesInfoAvailable;

/**
 Whether the DriversitiSDK officially supports the current device.
 
 Will return `DEVICE_UNSUPPORTED` until -retreiveSupportedDevices has finished.
 */
@property(nonatomic, readonly) DRIVERSITI_SDK_DEVICE_SUPPORT_LEVEL isCurrentDeviceSupported;

/**
 Whether the DriversitiSDK officially suppors the current iOS version
 
 Will return `DEVICE_UNSUPPORTED` until -retreiveSupportedDevices has finished.
 */
@property(nonatomic, readonly) DRIVERSITI_SDK_DEVICE_SUPPORT_LEVEL isCurrentOSVersionSupported;

/**
 Singleton instance of `MobileDeviceManager`.
 */
+(nonnull instancetype)sharedInstance;

/**
 Queries Driversiti's Device Support API for information on supported iOS devices.
 */
-(void)retrieveSupportedDevices;
@end