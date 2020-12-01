<?php
    include("storage.php");
    $stor = new Storage(new JsonIO("hallgatok.json"));

    $students = $stor -> findAll();

    usort($students,  function($a, $b){
        return strcmp($a["first_name"]." ".$a["last_name"], $b["first_name"]." ".$b["last_name"]);
    })
?>

<!DOCTYPE html>
<html lang="hu">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Neptun</title>
</head>
<body>
    <h1>Hallgatói nyilvántartás</h1>
    <ul>
        <?php foreach($students as $s): ?>
            <li><a href="student.php?id=<?= $s["id"] ?>"> <?= $s["first_name"]." ".$s["last_name"] ?></a></li>
        <?php endforeach; ?>
    </ul>
</body>
</html>