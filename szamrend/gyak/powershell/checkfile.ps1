if( Test-Path -PathType Leaf -Path $args[0] )
{
    $file = (Get-Content $args[0])
    foreach ($line in $file)
    {
        Write-Output $line.Length
        Write-Host $line.Split(' ')[1]
        if($line -gt 10)
        {
        Write-Host $line.SubString(2,10)
        } 
    }
}  