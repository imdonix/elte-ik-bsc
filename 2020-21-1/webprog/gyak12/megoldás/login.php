<?php
    session_start();
    include_once("storage.php");
    if (!isset($_SESSION["user"]) && count($_POST) > 0){
        $un = $_POST["user"];
        $pw = $_POST["pw"];
        
        $ustor = new Storage(new JsonIo("users.json"));
        $user = $ustor -> findOne(["username" => $un]);
        if ($user != null){
            if (password_verify($pw, $user["password"]))
                $_SESSION["user"] = $un;
            else $_SESSION["loginerror"] = 2;
        } else $_SESSION["loginerror"] = 1;
    }
    header("Location: index.php");
?>