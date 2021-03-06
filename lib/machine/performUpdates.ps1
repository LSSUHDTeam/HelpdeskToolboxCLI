
Write-Host "It may take some time for this to run, but it should exit when done"

$Criteria = "IsInstalled=0 and Type='Software'"

$Searcher = New-Object -ComObject Microsoft.Update.Searcher

$SearchResult = $Searcher.Search($Criteria).Updates

$Session = New-Object -ComObject Microsoft.Update.Session

$Downloader = $Session.CreateUpdateDownloader()

$Downloader.Updates = $SearchResult

$Downloader.Download()

$Installer = New-Object -ComObject Microsoft.Update.Installer

$Installer.Updates = $SearchResult

$Result = $Installer.Install()


If ($Result.rebootRequired) { 

Write-Host "A reboot is required, you will have to do that yourself"


 }