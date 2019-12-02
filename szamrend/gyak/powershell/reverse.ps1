$filename = Read-Host "Add meg afile nevet!"
if(Test-Path -Path $filename -PathType Leaf)
{
    $file = Get-Content $filename
    for($i = $file.Length-1; $i -gt 0; $i--)
    {
        Write-Host $file[$i]
    }
}