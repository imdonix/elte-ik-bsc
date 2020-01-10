if(Test-Path $args[0] -PathType Leaf)
{
    Get-Content $args[0] | ForEach-Object { $_.Replace("@", " kukac ").Replace(".", " pont ") }
}