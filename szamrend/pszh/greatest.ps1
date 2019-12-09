if($args.Length -ge 0)
{
    $max=$args[0]
    foreach($i in $args)
    {
        $max = [Math]::Max($i, $max)
    }
    Write-Output $max
}
else
{
    Write-Host 'Nem adott meg paramétert'
}