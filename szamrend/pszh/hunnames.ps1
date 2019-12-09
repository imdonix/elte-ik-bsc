if($args.Length -eq 1)
{
    if(Test-Path -Path $args[0] -PathType Leaf)
    {
        foreach($name in Get-Content $args[0])
        {
            $splitted = $name.Split(' ')
            $a = $splitted[2]
            $b = $splitted[1]
            if($splitted[0] -eq "Mr")
            {
                $c = 'ur'
            }
            else
            {
                $c = 'holgy'
            }     
            Write-Output "$a $b $c"
        }
    }
    else
    {
        Write-Host 'Nem létezik a fájl'
    }
}
else
{
    Write-Host 'Nem adott meg paramétert'
}
