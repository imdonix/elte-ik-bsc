$rand = New-Object System.Random
$number = $rand.Next(1,100)
$guess = Read-Host "Irj be egy szamot"
while ($number -ne $guess)
{
    if($number -le $guess)
    {
        Write-Host "kisebb"
    }
    else
    {
        Write-Host "nagyobb"
    }
    $guess = Read-Host "Irj be egy szamot"
}
Write-Host "Nyertel"