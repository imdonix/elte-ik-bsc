Param(
    [Parameter(Mandatory=$true)]
    [int]$n
)

$prod = 1
for ($i = 2; $i -le $n; $i++)
{
    $prod *= $i;
}

Write-Host $prod