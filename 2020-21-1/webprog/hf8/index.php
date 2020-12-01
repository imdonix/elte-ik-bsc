<?php

    include("storage.php");
    $stor = new Storage(new JsonIO("szinek.json"));

    function update($stor)
    {
        $f = fopen("hosszu.txt", "w");
        foreach($stor -> findAll() as $color)
            fwrite($f, $color['neve'] . "\r\n");
        fclose($f);
    }

    if(isset($_POST['color']) && isset($_POST['name']))
    {
        $stor -> add(['neve' => $_POST['name'], 'kodja' => $_POST['color']]);
        update($stor);
    }

    if(isset($_POST['id']))
    {
        $stor -> delete($_POST['id']);
        update($stor);
    }

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>HF8</title>
</head>
<body>
    
    <ul>
        <?php foreach($stor -> findAll() as $color): ?>
        <li style="color: <?php echo $color['kodja'] ?>">
            <span>
                <?php echo $color['neve']?>
                <form action="/" method="POST">
                    <input type="hidden" name="id" value="<?php echo$color['id']?>">
                    <button type="submit"> Delete </button>
                </form>
            </span>
        </li>
        <?php endforeach; ?>
    </ul>

    <hr>

    <form action="/" method="POST">
        <label for="color">Color:</label>
        <input type="color" name="color" id="color">
        <label for="name">Name</label>
        <input type="text" name="name" id="name">
        <button type="submit">Send</button>
    </form>

</body>
</html>