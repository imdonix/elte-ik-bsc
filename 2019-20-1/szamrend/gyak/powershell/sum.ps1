$sum = 0;
for ($i = 0; $i -le $args.Length; $i++)
{
    $sum += $args[$i]
}
Write-Host $sum