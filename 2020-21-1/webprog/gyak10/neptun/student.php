<?php

    include("storage.php");
    $stor = new Storage(new JsonIO("hallgatok.json"));
    $stud = $stor -> findById($_GET["id"]);

    $neptun = $_POST["neptun"] ?? $stud["neptun"];
    $first_name = $_POST["first_name"] ?? $stud["first_name"];
    $last_name = $_POST["last_name"] ?? $stud["last_name"];
    $birth_y = $_POST["birth_y"] ?? $stud["birth_date"]["year"];
    $birth_m = $_POST["birth_m"] ?? $stud["birth_date"]["month"];
    $birth_d = $_POST["birth_d"] ?? $stud["birth_date"]["day"];

    $err = [];
    if (count($_POST) > 0){
        if (validate_entry($_POST, $err)){
            $stud["neptun"] = $neptun;
            $stud["first_name"] = $first_name;
            $stud["last_name"] = $last_name;
            $stud["birth_date"]["year"] = $birth_y;
            $stud["birth_date"]["month"] = $birth_m;
            $stud["birth_date"]["day"] = $birth_d;

            $stor -> update($stud["id"], $stud);
            header("Location: index.php");
        }
    }

    function validate_entry($post, &$err){
        if (!isset($post["neptun"]) || strlen($post["neptun"]) != 6)
            $err["neptun"] = true;
        if (!isset($post["first_name"]) || strlen(trim($post["first_name"])) < 1)
            $err["first_name"] = true;
        return (count($err) == 0);
    }

?>

<!DOCTYPE html>
<html lang="hu">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Neptun</title>
</head>
<body>
    <h1> <?= $stud["first_name"]." ".$stud["last_name"] ?> adatai</h1>
    <form action="student.php?id=<?= $_GET["id"] ?>" method="post">
        ID: <?= $stud["id"] ?> <br>
        Neptun: <input type="text" name="neptun" value="<?= $neptun ?>"> <br>
        Vezetéknév: <input type="text" name="first_name" value="<?= $first_name ?>"> 
        <?php if (isset($err["first_name"])) echo "HIBA!"; ?>
         <br>
        Keresztnév: <input type="text" name="last_name" value="<?= $last_name ?>"> <br>
        Születési dátum:
            <input type="number" name="birth_y" min="1900" max="2020" value="<?= $birth_y ?>"> 
            <input type="number" name="birth_m" min="1" max="12" value="<?= $birth_m ?>"> 
            <input type="number" name="birth_d" min="1" max="31" value="<?= $birth_d ?>"> <br>
        <button type="submit">Mentés</button>
    </form>
</body>
</html>