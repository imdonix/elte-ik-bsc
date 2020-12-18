<?php
$activities = [
    1 => [
        "name" => "alvás",
        "difficulty" => 0.05
    ],
    2 => [
        "name" => "bányászás",
        "difficulty" => 0.6
    ],
    3 => [
        "name" => "család",
        "difficulty" => 0.4
    ],
    4 => [
        "name" => "programozás",
        "difficulty" => 0.95
    ],
    5 => [
        "name" => "zsákmányolás",
        "difficulty" => 0.7
    ],
    6 => [
        "name" => "vadászat",
        "difficulty" => 0.6
    ],
    7 => [
        "name" => "játék",
        "difficulty" => 0.0
    ],
    8 => [
        "name" => "főzés",
        "difficulty" => 0.6
    ]
];
$goblins = [
    "WEB'LIN" => [
        [
            "startHour" => 0,
            "activityKey" => 3
        ],
        [
            "startHour" => 1,
            "activityKey" => 3
        ],
        [
            "startHour" => 3,
            "activityKey" => 5
        ],
        [
            "startHour" => 4,
            "activityKey" => 4
        ],
        [
            "startHour" => 5,
            "activityKey" => 4
        ],
        [
            "startHour" => 7,
            "activityKey" => 1
        ]
    ],
    "HUN'TER" => [
        [
            "startHour" => 0,
            "activityKey" => 1
        ],
        [
            "startHour" => 1,
            "activityKey" => 6
        ],
        [
            "startHour" => 3,
            "activityKey" => 3
        ],
        [
            "startHour" => 4,
            "activityKey" => 3
        ],
        [
            "startHour" => 5,
            "activityKey" => 6
        ],
        [
            "startHour" => 7,
            "activityKey" => 6
        ]
    ],
    "MOT'HER" => [
        [
            "startHour" => 0,
            "activityKey" => 3
        ],
        [
            "startHour" => 1,
            "activityKey" => 3
        ],
        [
            "startHour" => 3,
            "activityKey" => 6
        ],
        [
            "startHour" => 4,
            "activityKey" => 8
        ],
        [
            "startHour" => 5,
            "activityKey" => 8
        ],
        [
            "startHour" => 7,
            "activityKey" => 3
        ]
    ],
    "GOB'KID" => [
        [
            "startHour" => 0,
            "activityKey" => 7
        ],
        [
            "startHour" => 1,
            "activityKey" => 7
        ],
        [
            "startHour" => 3,
            "activityKey" => 7
        ],
        [
            "startHour" => 4,
            "activityKey" => 7
        ],
        [
            "startHour" => 5,
            "activityKey" => 7
        ],
        [
            "startHour" => 7,
            "activityKey" => 7
        ]
    ]
];


function find($hour, $goblin)
{
    foreach($goblin as $act)
        if($act['startHour'] == $hour)
            return $act['activityKey'];
    return NULL;
}

function findAct($id, $activities)
{
    foreach($activities as $key => $value)
        if($key == $id)
            return $value;
    return NULL;
}

?>

<!DOCTYPE html>
<html lang="hu">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>1. feladat</title>
    <style>
        table, td, th {
            border: 1px black solid;
            border-collapse: collapse;
        }
        td { text-align: center; }

    </style>
</head>

<body>
    <h1>1. feladat</h1>
    <h2>Időbeosztás</h2>
    <table>
        <tr>
            <th>Óra</th>
            <?php foreach($goblins as $key => $value):?>
            <th>
                <?php echo $key?>
            </th>
            <?php endforeach;?>
        </tr>
        <?php for($i = 0; $i<8 ; $i++):?>
        <tr>
            <td> <?php echo $i?> </td>
            <?php foreach($goblins as $key => $value):?>
                <?php 
                    $activityID = find($i,  $value);
                    $activity = findAct($activityID, $activities);
                    
                    if($activity != NULL)
                    {
                        $text = $activity['name'];
                        $color = $activity['difficulty'] >= 0.5 ? ($activity['difficulty'] >= 0.8 ? 'red' : 'orange')  : 'lightgreen';
                    }
                    else
                    {
                        $text = '';
                        $color = 'white';
                    }
                ?>
                <td style="background-color: <?php echo $color ?>"> <?php echo $text?> </td>
            <?php endforeach;?>
        </tr>
        <?php endfor;?>
    </table>
</body>

</html>