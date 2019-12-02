Param
(
    [Parameter(Mandatory=$true)]
    [string]$filename
)

if(Test-Path $filename -PathType Leaf)
{
    $name = Read-Host "Adja meg a keresett nevet"!
    (Get-Content $filename | ForEach-Object { $_.Split(':')[4] } | Select-String $name | Measure-Object).Count
}