# DriversitiSDK for iOS

The DriversitiSDK for iOS enables Driversiti customers track driver behavior and receive real-time event notifications for enrolled drivers and vehicles. In addition to real-time notifications, these behaviors and events are uploaded to Driversiti's hosted cloud, allowing Driversiti's customers later access to the behaviors and overall driving scores of their company's drivers.

DriversitiSDK employs Driversiti's patented real-time crash detection to notify the host application if DriversitiSDK detects a vehicle crash using the phone's sensors.

## Requirements and Supported Devices for iOS Version
- iOS 7.1 and higher
- iPhone 5S, SE, 6, 6 Plus, 6S, and 6S Plus
- Host application must enable the `location` UIBackgroundMode and location always usage
- If prompted, the user must allow access to GPS in background and access to the Activity Monitor.

## Getting Started

- Receive a DriversitiSDK Developer Key
- Install the DriversitiSDK (CocoaPods is recommended)
- Change project settings to enable SDK
- Using the SDK in App.
- Check out the full SDK documentation on [cocoadocs](http://cocoadocs.org/docsets/DriversitiSDK/).
- Check out the [wiki](https://github.com/apiosys/DriversitiSDK/wiki) for details on specific topics.

### 1. Receive a DriversitiSDK Developer Key

Before DriversitiSDK will operate, your organization will need to acquire an DriversitiSDK Developer Key, which may be requested using the [Driversiti SDK Key Request form](http://goo.gl/forms/YSSuYZ16Rk). Your organization only needs one shared SDK key, which can be used by multiple developers within your organization and for both the iOS and Android platforms.

### 2a. Installing the DriversitiSDK (CocoaPods)

Driversiti recommends and supports the use of CocoaPods to manage downloading and linking the DriversitiSDK into your app project. To integrate, simply specify it in your Podfile. For example

```ruby

target "{NAME_OF_XCODE_TARGET}" do
  pod 'DriversitiSDK'
end
```

Make sure to replace ``{NAME_OF_XCODE_TARGET}`` with the name of your target in your Xcode project, typically the name of your app.

### 2b. Installing the DriversitiSDK manually

While CocoaPods is recommended, developers using other project dependency managers can incorporate the DriversitiSDK manually. Developers can find the following required files within this repository.
- A static library, `libDriversitiSDK.a`, located in the repository root.  
- Public header files located in ``include/DriversitiSDK/``.
- A required resource bundle named `Driversiti.bundle` located in the repository root. This bundle must be include as-is into the host applications main bundle.

Additionally, a developer incorporating manually, must also incorporate DriversitiSDK's required dependencies. These dependencies are listed in the ``DriversitiSDK.podspec`` file located in the repository root.

### 3. Required App Project Settings

- ``Enable BitCode`` needs to be set to ``NO`` at the application project level.
- ``Background Modes`` under Capabilities must be turned on, and ``Location Updates`` must be enabled.
- ``NSLocationAlwaysUsageDescription`` in your Info.plist must be specified. The string specified will be prompted to the user once the DriversitiSDK starts up, if the app had not already received prior user permission to always run in the background.

### 4. Using the SDK in App.

#### a. Initialize the SDK

When using the SDK, a developer should first set the organization's key on the shared DriversitiSDK object. Additionally, the host application should ensure that locationOptions passed into the UIApplicationDelegate are also passed into DriversitiSDK using the ``startWithLaunchOptions:`` method.  An example ``application:didFinishLaunchingWithOptions:`` for the host application is provided below.

```objective-c
#import <DriversitiSDK/DriversitiSDK.h>
...

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

  ...
	[[DriversitiSDK sharedInstance] setAPIKey:@"{DriversitiSDK-Developer-Key}"]
	[[DriversitiSDK sharedInstance] startWithLaunchOptions:launchOptions];
  ...

}
```

replacing ``{DriversitiSDK-Developer-Key}`` with your key.

Additionally, to provide DriversitiSDK the opportunity to continue to operate when the host application enters the background, please include the following in the host application's ``applicationDidEnterBackground:`` method

```objective-c
__block UIBackgroundTaskIdentifier taskID = [application beginBackgroundTaskWithExpirationHandler:^{
		[[NSOperationQueue mainQueue] addOperationWithBlock:^{
			[[[DriversitiSDK sharedInstance] operationQueue] waitUntilAllOperationsAreFinished];
			[application endBackgroundTask:taskID];
			taskID = UIBackgroundTaskInvalid;
		}];
	}];
```



#### b. Register User and Vehicle

Before the SDK can begin reporting detections, a User and Vehicle needs to be registered using the appropriate methods on ``UserManager`` and ``VehicleManager``. An example is provided below.

```objective-c
[[UserManager sharedInstance]
		 userRegisterWithEmailAddress:@"{EMAIL}"
		 password:@"{PASSWORD}"
		 firstName:@"{FIRST-NAME}"
		 middleName:@""
		 lastName:@"{LAST-NAME}"
		 streetAddress:@""
		 city:@""
		 state:@""
		 country:@""
		 zipcode:@""
		 phoneNumber:@"{PHONE-NUMBER}"
		 username:@"{USERNAME}"
		 companyId:@"{COMPANY}"
		 completionBlock:^(NSError *error)
		 {
           if (error != nil) {
             // Handle error case
           } else {
             // Handle success case
           }
		 }];
```

Importantly, ``{COMPANY}`` will need to be set to the Company name specified to you by <support@driversiti.com>. For trial customers, please use ``Soteria`` as the company name.

```objective-c

[[VehicleManager sharedInstance]
  vehicleRegisterWithName:@"{VEHICLE_NAME}"
  vehicleModel:@"{MODEL}"
  vehicleMake:@"{MAKE}"
  vehicleYear:{YEAR}
  vehicleLicensePlate:@""
  vehicleColor:@""
  vehicleMPG:0.0
  vin:@""
  completionBlock:^(APVehicle *newVehicle, NSError *error)
		 {
			 if (error != nil)
			 {
				 // Handle error case
			 }
			 else
			 {
				 // Handle success case
			 }
		 }];
```

#### c. Set ``DriversitiSensorDelegate`` Delegate and start Data Collection

To receive real-time event notifications, the host application will need to register an instance conforming to the ``DriversitiSensorDelegate`` protocol using the ``sensorDelegate`` property on ``DriversitiSDK``.

Once everything is setup, the host application should call the ``-startDataCollection`` method on ``DriversitiSDK``.  Notice of events will flow into the host application through the ``DriversitiSensorDelegate``.
