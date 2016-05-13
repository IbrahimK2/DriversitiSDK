//
//  DriversitiEventDefs.h
//  DriversitiSDK
//
//  Created by Anthony Spinelli on 10/11/14.
//  Copyright (c) 2014 Apio. All rights reserved.
//

#ifndef apioSDK_ApEventDefs_h
#define apioSDK_ApEventDefs_h

/**
 *  Enumerated return status codes of the SensorAnalysisLibrary functions
 */
typedef NS_ENUM(NSInteger, CLOUD_STATE)
{
	CLOUD_STATE_NO_CHANGE = 0,
	CLOUD_STATE_ADDED,
	CLOUD_STATE_MODIFIED,  // Error in signal detection algorithm
	CLOUD_STATE_DELETED,
};

typedef NS_ENUM(NSInteger, DriversitiEventType)
{
	APEventNone = -1,
	APEventLocationUpdate=0,
	APEventWalkingStart=10,
	APEventWalkingStop,
	APEventCarModeStartByDetection=20,
	APEventCarModeStartByVehicleSpeed,
	APEventCarModeStopByDetection=30,
	APEventCarModeStopByDetectingWalking,
	APEventVehicleEntry,
	APEventIgnition=60,
	APEventSpeedThresholdExceeded=70,
	APEventSpeedThresholdRestored,
	APEventShake,
	APEventCarIdBySAL,
	APEventHardAcceleration=80,
	APEventHardDeceleration,
	ApEventCrashDetected,
	APEventDistractedStart=90,
	APEventDistractedStop,
	APEventGeneralHandlingDetected,
	APEventGeneralHandlingDetectedNoMotion,
	APEventPassengerHandlingDetected,
	APEventPassengerHandlingDetectedNoMotion,
	APEventDriverHandlingDetected,
	APEventDriverHandlingDetectedNoMotion,
	APEventTripStart=110,
	APEventTripEnd,
};

//These values are used here to ensure we have consistency
//with Android team and format documentation for the SAL team.
//Andoird can't use bitwised enums in JNI so they're using ints.
typedef NS_ENUM(NSInteger, DriversitiActivity)
{
    APNoActivity = 0,
	 APCycling = 1,
	 APWalking = 2,
	 APRunning = 3,
    APDriving = 4,
    APStationary = 5,
	 APInVehicleStationary = 6
};

typedef NS_ENUM(NSInteger, DriversitiHandlingAwareness)
{
	APStateHandlingUnknown = 0,
	APGeneralHandlingNoMotion,
	APGeneralHandlingInMotion,
	APDriverSideTextingNoMotion,
	APLeftSideTextingNoMotion __attribute__((deprecated)) = APDriverSideTextingNoMotion,
	APDriverSideTextingInMotion,
	APLeftSideTextingInMotion __attribute__((deprecated)) = APDriverSideTextingInMotion,
	APDriverSideNoMotion,
	APLeftSideHandlingNoMotion __attribute__((deprecated)) = APDriverSideNoMotion,
	APDriverSideInMotion,
	APLeftSideHandlingInMotion __attribute__((deprecated)) = APDriverSideInMotion,
	APDriverSidePhoneCallNoMotion,
	APLeftSidePhoneCallNoMotion __attribute__((deprecated)) = APDriverSidePhoneCallNoMotion,
	APDriverSidePhoneCallInMotion,
	APLeftSidePhoneCallInMotion __attribute__((deprecated)) = APDriverSidePhoneCallInMotion,

	APPassengerSideTextingNoMotion,
	APRightSideTextingNoMotion __attribute__((deprecated)) = APPassengerSideTextingNoMotion,
	APPassengerSideTextingInMotion,
	APRightSideTextingInMotion __attribute__((deprecated)) = APPassengerSideTextingInMotion,
	APPassengerSideHandlingNoMotion,
	APRightSideHandlingNoMotion __attribute__((deprecated)) = APPassengerSideHandlingNoMotion,
	APPassengerSideHandlingInMotion,
	APRightSideHandlingInMotion __attribute__((deprecated)) = APPassengerSideHandlingInMotion,
	APPassengerSidePhoneCallNoMotion,
	APRightSidePhoneCallNoMotion __attribute__((deprecated)) = APPassengerSidePhoneCallNoMotion,
	APPassengerSidePhoneCallInMotion,
	APRightSidePhoneCallInMotion __attribute__((deprecated)) = APPassengerSidePhoneCallInMotion
};

typedef NS_ENUM(NSInteger, DriversitiRequestedGpsState)
{
	GPS_STATE_UNKNOWN,
	GPS_STATE_LOWPRECISION,
	GPS_STATE_HIGHPRECISION,
	GPS_STATE_GEOREGIONING
};


//These values are used here to ensure we have consistency
//with Android team and format documentation for the SAL team.
//Andoird can't use bitwised enums in JNI so they're using ints.
typedef NS_ENUM(NSInteger, DriversitiNetworkState)
{
	APNoNetwork = 0,
	APWAN = 1,//Cellular
	APWIFI = 2,//WiFi
	APWAN_LOW = 4,//Cellular
	APWAN_MED = 8,//Cellular
	APWAN_GOOD = 16,//Cellular
	APWIFI_LOW = 32,//WiFi
	APWIFI_MED = 64,//WiFi
	APWIFI_GOOD = 128,//WiFi
	APNetworkUnknown = 256 // Unknown Network State (Initial State of Network before reachability is checked)
};

typedef NS_ENUM(NSInteger, DriversitiUploadState)
{
	APNoUploadState = 0,
	APHasHadCarModeSinceUpload = 1,
	APHasDataInNeedOfUpload = 2//Cellular
};

typedef NS_ENUM(NSInteger, DriversitiEntryAwareness)
{
	APStateEntryUnknown = 0,
	
	APLeftSideEntry,
	APLeftSideBackEntry,
	APLeftSideFrontEntry,
	
	APRightSideEntry,
	APRightSideBackEntry,
	APRightSideFrontEntry
};

#endif
