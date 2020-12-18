<?php

session_start();

if(!isset($_SESSION["bal"]))
    $_SESSION["bal"] = 10*12;

if ($_SERVER['REQUEST_METHOD'] === 'POST') 
{
    if(isset($_GET['add']))
        $_SESSION["bal"] += $_GET['add'];

    echo '{ "balance" : ' . $_SESSION["bal"] . '}';
    exit;
}

?>

<!DOCTYPE html>
<html lang="hu">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>4. feladat</title>
</head>
<body>
    <h1>4. feladat</h1>

    <h1 id=bal></h1>

    <h2>Új tranzakció</h2>
    Arany: <input type="number" id="gold" min="0" max="99" step="1" value="0"><br>
    Ezüst: <input type="number" id="silver" min="0" max="11" step="1" value="0"><br>
    <button id="income">Bevétel</button>
    <button id="spend">Kiadás</button>
    
    <h2>Tranzakciós napló</h2>
    <table id="res">
        <tr>
            <th>Időpont</th>
            <th>Egyenleg</th>
        </tr>
        <tr>
        </tr>
    </table>

    <script src="script.js"></script>

</body>
</html>

