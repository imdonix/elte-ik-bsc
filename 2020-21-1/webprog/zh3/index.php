<?php

include("storage.php");
$data = new Storage(new JsonIO("data.json"));
$grades = ["elégtelen","elégséges","közepes","jó","jeles"];

if(isset($_POST['course']) && isset($_POST['grade']))
{   
    $new = $data -> findById($_POST['course']);
    $new['jegy'] = $_POST['grade'];
    $data -> update($_POST['course'], $new);
    update($data);
}

function getCreditIndex($data)
{
    $s = 0;
    foreach($data -> findAll() as $d)
        if($d['jegy'] > 1)
            $s += $d['jegy'] * $d['kredit'];
    return number_format(floatval($s) / 30, 2, '.', ',');
}

function update($data)
{
    $f = fopen("krindex.txt", "w");
    fwrite($f, getCreditIndex($data) . "\r\n");
    fclose($f);    
}

?>

<!DOCTYPE html>
<html lang="hu">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>PHP csop.ZH</title>
</head>
<body>
    <h1>Leckekönyv</h1>
    <h2>Felvett tárgyak</h2>
    <table>
        <tr>
            <th>Tárgykód</th>
            <th>Tárgynév</th>
            <th>Oktató</th>
            <th>Kredit</th>
            <th>Érdemjegy</th>
        </tr>
        <?php foreach($data -> findAll() as $d): ?>
        <tr>
            <th><?php echo $d['targykod']; ?></th>
            <th><?php echo $d['targynev']; ?></th>
            <th><?php echo $d['oktato']; ?></th>
            <th><?php echo $d['kredit']; ?></th>
            <th><?php echo ($d['jegy'] == 0) ? "" : $grades[$d['jegy']-1]; ?></th>
        </tr> 
        <?php endforeach; ?>
    </table>
    <h2>Információk</h2>
    Felvett tárgyak száma: <?php echo count($data -> findAll()) ?> <br>
    Elégtelen érdemjegy: <?php echo $data -> findOne(['jegy' => 0]) == NULL ? "nincs" : "van"; ?> 
    <br>
    Kreditindex: <?php echo getCreditIndex($data) ?>
    <h2>Jegybeírás</h2>
    <form action="/" method="POST">
    <label for="course">Tárgy</label>
    <select name="course" id="course">
        <?php foreach($data -> findAll(['jegy' => 0]) as $d): ?>
            <option value="<?php echo $d['id'] ?>"><?php echo $d['targynev'] ?></option>
        <?php endforeach; ?>
    </select>
    <br>
    <input type="number" min="1" max="5" name="grade" id="grade">
    <br>
    <button type="submit">Beírás</button>
    </form>
</body>
</html>