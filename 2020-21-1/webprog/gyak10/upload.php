<?php
    // amit már tudunk: $_GET, $_POST
    // most: $_FILES
    // amit jövő héten tanulunk: $_SESSION, $_COOKIE
    $content = "Még nem volt szöveges fájlt feltöltve. :C";
    if (isset($_FILES["upFile"])){
        if (pathinfo ($_FILES["upFile"]["name"]) ["extension"] === "txt")
            move_uploaded_file($_FILES["upFile"]["tmp_name"], "upload.txt");
    }
    if (file_exists("upload.txt")) $content = file_get_contents("upload.txt");
?>

<!DOCTYPE html>
<html lang="hu">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>2. feladat</title>
</head>
<body>
    <h1>Fájlfeltöltő</h1>
    <form action="upload.php" method="post" enctype="multipart/form-data">
        <input type="file" name="upFile">
        <button type="submit">Feltöltés</button>
    </form>
    <?= $content ?>
</body>
</html>