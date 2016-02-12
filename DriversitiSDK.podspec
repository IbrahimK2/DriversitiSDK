
Pod::Spec.new do |s|
  s.name         = "DriversitiSDK"
  s.version      = "0.9.13.2"
  s.summary      = "Driving safety for the mobile generation. Real-time notifications of unsafe driving behaviors."
  s.description  = <<-DESC
                    Transform smartphones from driver's worst enemy to their best friend
                    - SDK leverages algorithms that use smartphones sensor data to understand driving behavior, like phone handling. aggressive braking, and vehicle crashes
                    - autonomously starts detecting at trip start
                    - uploads data to servers for reporting and analytics
                    DESC

  s.homepage     = "http://driversiti.com/"
  s.license      = { type: 'Custom', file: 'LICENSE.md'}
  s.author       = { "Driversiti" => "support@driversiti.com" }
  s.social_media_url = "https://twitter.com/driversiti"
  s.platform     = :ios, "7.1"

  s.source       = {
    :git => "https://github.com/apiosys/DriversitiSDK.git",
    :tag => s.version.to_s
  }

  s.source_files          = "include/DriversitiSDK/*.h"
  s.resource              = "DriversitiSDK.bundle"
  s.vendored_libraries    = "libDriversitiSDK.a"

  s.requires_arc          = true
  s.frameworks            = 'UIKit','Foundation','SystemConfiguration','MobileCoreServices','CoreLocation'

  s.dependency 'MagicalRecord','~>2.2'
  s.dependency 'AFNetworking', '~> 2.5'
  s.dependency 'AFNetworkActivityLogger'
  s.dependency 'AFgzipRequestSerializer'
  s.dependency 'GoogleAnalytics'
  s.dependency 'Firebase'
  s.default_subspec = 'Lite'

  s.subspec 'Lite' do |lite|

  end

  s.subspec 'Beacons' do |beacons|
    beacons.dependency 'KontaktSDK-OLD', '~>6.2'
    beacons.xcconfig = { 'OTHER_CFLAGS' => '$(inherited) -DBEACONS_ENABLED' }
  end
end
