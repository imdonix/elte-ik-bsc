if($args.Length -eq 3)
{
    if ((Test-Path -Path $args[0] -PathType Leaf) -and (Test-Path -Path $args[1] -PathType Leaf))
    {
        if(Test-Path -Path $args[2] -PathType Leaf)
        {
            Remove-Item $args[2]
        }
        $f1 = Get-Content $args[0]
        $f2 = Get-Content $args[1]
        $max = $f1.Length
        if($max -le $f2.Length)
        {
            $max = $f2.Length
        }

        for($i = 0; $i -le $max; $i++)
        {
            Write-Output $f1[$i] >> $args[2]
            Write-Output $f2[$i] >> $args[2]
        }
    }
    else
    {
        Write-Host "nem letezik a fájl"
    }
}
else
{
    Write-Host "Nincs elég parameter";
}