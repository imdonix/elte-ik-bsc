function IsPrime($a)
{
    $oszto = 0;
    for($i = 1; $i -le $a; $i++)
    {
        if($a % $i -eq 0)
        {
            $oszto++;
        }
    }
    return ($oszto -eq 2)
}

if($args.Length -eq 2)
{
    if($args[0] -lt $args[1])
    {
        for($i = $args[0]; $i -le $args[1]; $i++)
        {
            if(IsPrime($i))
            {
                Write-Output $i
            }
        }    
    }
}