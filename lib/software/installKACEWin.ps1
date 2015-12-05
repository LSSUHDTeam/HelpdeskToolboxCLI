$kaceExeName = "ampagent-5.4.5315-x86.msi"
$workingDir = $(Resolve-Path .\).Path
$kaceExePath = $workingDir + "\" + $kaceExeName

$installCommand = "msiexec /i " + $kaceExePath + " HOST+k1000.lssu.edu /passive"

&cmd /c $installCommand
