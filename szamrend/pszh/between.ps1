if($args.Length -eq 3)
{
    $n=$args[0] * 2
    $min=[Math]::Min($args[1], $args[2])
    $max=[Math]::Max($args[1], $args[2])
    if(($n -le $max) -and ($n -le $max))
    {
        Write-Output 'igen'
    }
    else
    {
        Write-Output 'nem'
    }
}
else
{
    Write-Host 'Nem megfelelő a paraméterek száma'
}