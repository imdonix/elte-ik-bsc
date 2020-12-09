<?php
    session_start();
    include_once("storage.php");
    if (isset($_SESSION["user"])){
        $dstor = new Storage(new JsonIo("data.json"));
        $data = $dstor -> findAll();
        $jegyek = ["", "elégtelen", "elégséges", "közepes", "jó", "jeles"];
        foreach($data as &$i)
            $i["jegy"] = $jegyek[$i["jegy"]];
        echo json_encode($data, JSON_PRETTY_PRINT);
    }
?>
