if($args.Length -ne 1)
{
    exit
}

if(Test-Path -PathType Leaf $args[0])
{
    Write-Host ($args[0][2])   
    $file = Get-Content $args[0]
    ($file | Measure-Object -Word).Words

}
else
{
    Write-Host nincs ilyen fajl
}