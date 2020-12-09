<?php
    session_start(); // $_SESSION["user"]
    $err = "";
    if (isset($_SESSION["loginerror"])){
        if ($_SESSION["loginerror"] == 1) $err = "Nem létező felhasználó!";
        if ($_SESSION["loginerror"] == 2) $err = "Helytelen jelszó!";
        unset($_SESSION["loginerror"]);
    }
    if (isset($_SESSION["user"])){
        include_once("storage.php");
        $ustor = new Storage(new JsonIo("users.json"));
        $user = $ustor -> findOne(["username" => $_SESSION["user"]]);
        $dstor = new Storage(new JsonIo("data.json"));
        $data = $dstor -> findAll();
        $jegyek = ["", "elégtelen", "elégséges", "közepes", "jó", "jeles"];
    }
?>
<!DOCTYPE html>
<html lang="hu">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php if (!isset($_SESSION["user"])): ?>
        <form action="login.php" method="post">
            Felhasználó: <input type="text" name="user"><br>
            Jelszó: <input type="password" name="pw"><br>
            <button type="submit">Bejelentkezés</button>
        </form>
        <span style="color: red"> <?= $err ?> </span>
    <?php else: ?>
        <h1>Hello <?= $_SESSION["user"] ?>!</h1>
        <a href="logout.php">Kijelentkezés</a>
        <button id="refresh">Frissítés</button>
        <table>
            <tr>
                <th>Tárgykód</th>
                <th>Tárgynév</th>
                <th>Oktató</th>
                <th>Kredit</th>
                <th>Érdemjegy</th>
            </tr>
            <?php foreach($data as $i): ?>
                <tr>
                <td><?= $i["targykod"] ?></td>
                <td><?= $i["targynev"] ?></td>
                <td><?= $i["oktato"] ?></td>
                <td><?= $i["kredit"] ?></td>
                <td><?= $jegyek[$i["jegy"]] ?></td>
                </tr>
            <?php endforeach; ?>
        </table>
        <?php if ($user["isAdmin"]): ?>
            <h2>Jegybeírás</h2>
            <form action="update.php" method="post">
                Tárgy: <select name="targyid">
                    <?php foreach($data as $i): ?>
                        <?php if($i["jegy"] == 0): ?>
                            <option value="<?= $i["id"] ?>"><?= $i["targynev"] ?></option>
                        <?php endif; ?>
                    <?php endforeach; ?>
                </select><br>
                Érdemjegy: <input type="number" name="jegy" min="1" max="5" step="1" value="5">
                <button type="submit">Beírás</button>
            </form>
        <?php endif; ?>
    <?php endif; ?>
    <script src="ajax.js"></script>
</body>
</html>
