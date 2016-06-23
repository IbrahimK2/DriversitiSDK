/*
//  DeviceManager.h
//  DriversitiSDK
//
//  Created by Jeff Behrbaum on 3/23/16.
//  Copyright © 2016 Apio. All rights reserved.
*/

#import <Foundation/Foundation.h>

@protocol DeviceSupportDelegate <NSObject>
@required
	-(void)deviceSupportInfoIsReadyForEvaluation;
@end

typedef enum
{
	DEVICE_SUPPORT_UNKNOWN,
	DEVICE_SUPPORTED,
	DEVICE_UNSUPPORTED
}DRIVERSITI_SDK_DEVICE_SUPPORT_LEVEL;

@interface MobileDeviceManager : NSObject
	@property(nullable, nonatomic, strong) id<DeviceSupportDelegate> deviceSupportDelegate;

	@property(nonatomic, readonly) BOOL bSupportedDevicesInfoAvailable;
	@property(nonatomic, readonly) DRIVERSITI_SDK_DEVICE_SUPPORT_LEVEL isCurrentDeviceSupported;
	@property(nonatomic, readonly) DRIVERSITI_SDK_DEVICE_SUPPORT_LEVEL isCurrentOSVersionSupported;

	@property(nullable, nonatomic, strong, readonly) NSArray *allSupportedDevices;
	@property(nullable, nonatomic, strong, readonly) NSArray *allSupportedOSVersions;

	+(nonnull instancetype)sharedInstance;

	-(void)retreiveSupportedDevices;
@end
