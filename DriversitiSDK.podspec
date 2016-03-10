
Pod::Spec.new do |s|
  s.name         = "DriversitiSDK"
  s.version      = "0.9.13.8"
  s.summary      = "Driving safety for the mobile generation. Real-time notifications of unsafe driving behaviors."
  s.description  = <<-DESC
                    Transform smartphones from driver's worst enemy to their best friend
                    - SDK leverages algorithms that use smartphones sensor data to understand driving behavior, like phone handling. aggressive braking, and vehicle crashes
                    - autonomously starts detecting at trip start
                    - uploads data to servers for reporting and analytics
                    DESC

  s.homepage     = "https://github.com/apiosys/DriversitiSDK"
  s.license      = { type: 'Commericial', file: 'LICENSE.md'}
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

  s.preserve_paths         = "README.md", "LICENSE.md"

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

end
