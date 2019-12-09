$ee=0
$eo=0
$oe=0
$oo=0
$i = 0;

foreach ($line in (Get-Content $args[0]))
{
    if (($i % 2) -eq 0)
    {
        foreach ($number in $line.Split(' '))
        {
            if (($number % 2) -eq 0)
            {
                $ee += $number
            }
            else
            {
                $eo += $number
            }
        }
    }
    else
    {
        foreach ($number in $line.Split(' '))
        {
            if (($number % 2) -eq 0)
            {
                $oe += $number
            }
            else
            {
                $oo += $number
            }
        }
    }
    $i++;
}
Write-Host Paros sorok paros szamainak osszege: $ee
Write-Host Paros sorok paratlan szamainak osszege: $eo
Write-Host Paratlan sorok paros szamainak osszege: $oe
Write-Host Paratlan sorok paratlan szamainak osszege: $oo
