
if ($args.Length -ne 2)
{
    Write-Host nem jo
    exit
}

Write-Host Osszege ($args[0] + $args[1])
Write-Host Kulombsege ($args[0] - $args[1])
Write-Host Szorzata ($args[0] * $args[1])
Write-Host Hanyadosa ($args[0] / $args[1])
Write-Host Hanyadosa ([Math]::Pow($args[0], $args[1]))