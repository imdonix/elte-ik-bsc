if($args.Length -eq 2)
{
    if((Test-Path -PathType Leaf -Path $args[0]) -and (Test-Path -PathType Leaf -Path $args[1]))
    {
        $database = Get-Content($args[0])
        $file = Get-Content($args[1])
        foreach ($line in $database)
        {
            $splitted = $line.Split(' ');
            Write-Output($file.Replace("<nev>",$splitted[0]).Replace("<cim>",$splitted[1]).Replace("<idopont>",$splitted[0]))
        }
    }
    else
    {
        Write-Host("Bad files")
    }
}
else
{
    Write-Host("Bad params")
}