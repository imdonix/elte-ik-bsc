<?php
    $n = 5;
    if (isset($_POST["n"]) && intval($_POST["n"]) > 0){
        $n = intval($_POST["n"]);
        $f = fopen("hello.txt", "w");
        for($i = 0; $i < $n; $i++)
            fputs($f, "Hello világ!\n");
        fclose($f);
    }
?>

<!DOCTYPE html>
<html lang="hu">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>1. feladat</title>
</head>
<body>
    <h1>Hello világ fájlba</h1>
    <form action="hello.php" method="post">
        Hányszor? <input type="number" name="n" min="1" max="200" value="<?= $n ?>">
        <button type="submit">Írd a fájlba!</button>
    </form>
</body>
</html>