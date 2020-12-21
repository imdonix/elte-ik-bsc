<?php

include 'storage.php';

$stor = new Storage(new JsonIO("vault.json"));

if($_SERVER["REQUEST_METHOD"] == "POST")
{
  $find = $stor->findOne(['name' => $_POST['name']]);

  if($find != NULL)
  {
    $stor->update($find['id'], 
    [
      'id' => $find['id'],
      'name' => $_POST['name'],
      'price' => $_POST['price'],
      'color' => $_POST['color'],
      'keep' => $_POST['keep'],
    ]);
  }
  else
    $stor->add(
      [
        'name' => $_POST['name'],
        'price' => $_POST['price'],
        'color' => $_POST['color'],
        'keep' => $_POST['keep'],
      ]);
}
else
{
  if(isset($_GET['delete']))
  {
    $stor->delete($_GET['delete']);
  }  
}

?>


<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>3. feladat</title>
</head>
<body>
  <h1>3. feladat</h1>

  <h2>Űrlap</h2>
  <form method="POST">
    <label for="name">Kincs neve:</label>
    <input type="text" name="name" id="name"><br>

    <label for="price">Kincs értéke:</label>
    <input type="number" name="price" id="price"><br>
    
    <label for="color">Kincs színe:</label>
    <select id="color" name="color">
      <option value="piros">piros</option>
      <option value="narancs">narancs</option>
      <option value="sárga">sárga</option>
      <option value="zöld">zöld</option>
      <option value="kék">kék</option>
      <option value="lila">lila</option>
    </select><br>

    <p>Megtartjuk?</p>

    <input type="radio" id="keep1" name="keep" value="true">
    <label for="keep1">Igen</label><br>
    
    <input type="radio" id="keep2" name="keep" value="false">
    <label for="keep2">Nem</label><br>
    
    <button type="submit">Külés</button>
  </form>

  <h2>Kincslista</h2>
  <table>
    <tr>
      <th>Név</th>
      <th>Érték</th>
      <th>Szín</th>
      <th>Megtartjuk?</th>
    </tr>
    <?php foreach($stor->findAll() as $rec):?>
      <tr>
        <td><?php echo $rec['name']?></td>
        <td><?php echo $rec['price']?></td>
        <td><?php echo $rec['color']?></td>
        <td><?php echo $rec['keep'] ? 'igen' : 'nem'?></td>
        <td><a href="index.php?delete=<?php echo $rec['id']?>">Töröl</a></td>
      </tr>
    <?php endforeach;?>
  </table>

</body>
</html>