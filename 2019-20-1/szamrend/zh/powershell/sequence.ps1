Param
(
    [Parameter(Mandatory = $true)]
    [int] $begin,
    [Parameter(Mandatory = $true)]
    [int] $increment,
    [Parameter(Mandatory = $true)]
    [int] $n
)

for($i=0;$i -le $n-1; $i++)
{
    Write-Output ($increment * $i + $begin)
}