<?php
    session_start();
    include_once("storage.php");
    $ustor = new Storage(new JsonIo("users.json"));
    $user = $ustor -> findOne(["username" => $_SESSION["user"]]);
    if ($user != null && $user["isAdmin"] && isset($_POST["targyid"]) && isset($_POST["jegy"])){
        $dstor = new Storage(new JsonIo("data.json"));
        $t = $dstor -> findById($_POST["targyid"]);
        if ($t != null && $t["jegy"] == 0){
            $t["jegy"] = intval($_POST["jegy"]);
            $dstor -> update($_POST["targyid"], $t);
        }
    }
    header("Location: index.php");
?>
