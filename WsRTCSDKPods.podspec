#
# Be sure to run `pod lib lint WsRTCSDKPods.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'WsRTCSDKPods'
  s.version          = '0.1.3'
  s.summary          = '接入WsRTC.framwork加入项目中'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/sander90/WsRTCSDKPods'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'sander' => 'sander.shan@yahoo.com' }
  s.source           = { :git => 'https://github.com/sander90/WsRTCSDKPods.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '9.0'
  s.vendored_frameworks = 'WsRTCSDKPods/Classes/*.framework'
#  s.source_files = 'WsRTCSDKPods/Classes/**/*'

  s.public_header_files = 'WsRTCSDKPods/Classes/**/*.h'
  s.frameworks = 'SystemConfiguration', 'CoreGraphics', 'UIKit', 'Foundation', 'AVKit', 'AVFoundation'

  s.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }
end
