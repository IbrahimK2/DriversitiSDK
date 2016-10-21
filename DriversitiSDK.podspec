Pod::Spec.new do |s|
  s.name         = "DriversitiSDK"
  s.version      = "1.0.11"
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
  s.platform     = :ios, "8.3"

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

  s.dependency 'Godzippa'
  s.dependency 'Firebase', '~> 2.5.1'
  s.default_subspec = 'Lite'

  s.subspec 'Lite' do |lite|

  end

end
