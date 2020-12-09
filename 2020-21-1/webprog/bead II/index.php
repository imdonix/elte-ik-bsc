<?php
include './core/router.php';
include './core/storage.php';
include './core/flash.php';
include './core/routes.php';

session_start();

$main = new Main();

$router = new Router($main);
$router->get("index","showMain");
$router->get("login","showLogin");
$router->get("register","showRegister");
$router->get("event", "showEvent");
$router->get("join", "showJoin");

$router->post("register","register");
$router->post("login", "login");
$router->post("logout", "logout");
$router->post("addEvent", "addEvent");
$router->post("join", "joinEvent");
$router->post("leave", "leaveEvent");

$router->preprocess();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Nemzeti Koronavírus Depó</title>
    <link 
    href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta1/dist/css/bootstrap.min.css" 
    rel="stylesheet" integrity="sha384-giJF6kkoqNQ00vy+HMDP7azOuL0xtbfIcaT9wjKHr8RbDVddVHyTfAAsrekwKmP1" 
    crossorigin="anonymous">
    <style>
        .red {color: red;}
        .green {color: green;}
    </style>
</head>
<body>
    <?php include './components/header.php' ?>
    <main class="container">
        <?php $router->start(); ?>
        <?php include './components/footer.php' ?>
    </main>
</body>
</html>