<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>2. feladat</title>
</head>
<body>
  <h1>2. feladat</h1>

  <h2>Üzenetek</h2>
  
  <?php
  
  function isvalidname($name)
  {
    $chars = str_split($name);
    foreach($chars as $char)
      if($char === ' ')
        return true;
    return false;
  }

  function findrealrank($name)
  {
    $max = -1;
    foreach(explode(' ', $name) as $rank)
      $max = max($max, findrank($rank));
    return $max;
  }

  function findrank($rank)
  {
    $ranks = ['goblinka', 'kisfőnök', 'nagyfőnök', 'főfőnök', 'törzsfő'];
    for($i = 0; $i < count($ranks); $i++)
      if($ranks[$i] == $rank)
        return $i;
    return -1;
  }

  ?>
  <?
    $errors = [];

    if(isset($_GET['goblins']) && ctype_digit($_GET['goblins']) && $_GET['goblins'] > 0)
    {}
    else
      array_push($errors, '<h2>Érvénytelen goblin mennyiség!</h2>');


    if(isset($_GET['chief']) && isvalidname($_GET['chief']))
    {}
    else
      array_push($errors, '<h2>Érvénytelen vezető!</h2>');

    $rank = isset($_GET['chief']) ? findrealrank($_GET['chief']) : -1;
    if($rank > 0)
    {
      if($rank > 1)
      {}
      else
        array_push($errors, '<h2>Túl alacsony rang!</h2>');
    }
    else
      array_push($errors, '<h2>Érvénytelen rang!</h2>');

      
    if(isset($_GET['shovels']) && ctype_digit($_GET['shovels']) && $_GET['shovels'] > 0)
    {
      if($_GET['shovels'] >= $_GET['goblins'])
      {}
      else
        array_push($errors, '<h2>Túl kevés ásó!</h2>');
    }
    else
      array_push($errors, '<h2>Érvénytelen ásó mennyiség!</h2>');

    if(count($errors) == 0)
    array_push($errors, '<h1>Gyorsan megszerezzük a kincset!</h1>');
  ?>

  <?php foreach($errors as $error):?>
    <?php echo $error ?>
  <?php endforeach;?>


  <h2>Próbalinkek</h2>
  <a href="index.php?goblins=5&chief=Snuch Nawdow nagyfőnök&shovels=7"><pre>index.php?goblins=5&chief=Snuch Nawdow nagyfőnök&shovels=7</pre></a>
  <a href="index.php?goblins=5&chief=Snuch Nawdow nagyfőnök&shovels=10"><pre>index.php?goblins=5&chief=Snuch Nawdow nagyfőnök&shovels=10</pre></a>
  <a href="index.php"><pre>index.php</pre></a>
  <a href="index.php?goblins=nemszám&chief=nincsszóköz&shovels=nemszám"><pre>index.php?goblins=nemszám&chief=nincsszóköz&shovels=nemszám</pre></a>
  <a href="index.php?goblins=-5&chief=Snuch Nawdow nagyfőnök&shovels=10"><pre>index.php?goblins=-5&chief=Snuch Nawdow nagyfőnök&shovels=10</pre></a>
  <a href="index.php?goblins=16.2&chief=Snuch Nawdow nagyfőnök&shovels=10"><pre>index.php?goblins=16.2&chief=Snuch Nawdow nagyfőnök&shovels=10</pre></a>
  <a href="index.php?goblins=16&chief=Snuch Nawdow nagyfőnök&shovels=10"><pre>index.php?goblins=16&chief=Snuch Nawdow nagyfőnök&shovels=10</pre></a>
  <a href="index.php?goblins=5&chief=Snuch Nawdow párttitkár&shovels=10"><pre>index.php?goblins=5&chief=Snuch Nawdow párttitkár&shovels=10</pre></a>
  <a href="index.php?goblins=5&chief=Snuch Nawdow kisfőnök&shovels=10"><pre>index.php?goblins=5&chief=Snuch Nawdow kisfőnök&shovels=10</pre></a>

</body>
</html>