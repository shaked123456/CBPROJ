@SET BDS=C:\Program Files (x86)\Embarcadero\Studio\22.0
@SET BDSINCLUDE=C:\Program Files (x86)\Embarcadero\Studio\22.0\include
@SET BDSCOMMONDIR=C:\Users\Public\Documents\Embarcadero\Studio\22.0
@SET FrameworkDir=C:\Windows\Microsoft.NET\Framework\v4.0.30319
@SET FrameworkVersion=v4.5
@SET FrameworkSDKDir=
@SET PATH=%FrameworkDir%;%FrameworkSDKDir%;C:\Program Files (x86)\Embarcadero\Studio\22.0\bin;C:\Program Files (x86)\Embarcadero\Studio\22.0\bin64;C:\Program Files (x86)\Embarcadero\Studio\22.0\cmake;%PATH%
@SET LANGDIR=EN
@SET PLATFORM=
@SET PlatformSDK=
cmd /k "msbuild "CPP\Modern CPP\CppStringView\CppStringView.cbproj"" 
