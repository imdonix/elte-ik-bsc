<?php
    $shift = $_GET['s'] ?? 0;
    $shift = is_numeric($shift) ? $shift : 0;   
    $date = new DateTime('+' . $shift . ' month');
    $events = $this->getEventsAt($date);
    $app = $this->isLoggedIn() ? $this->getApp() : NULL;
?>
<div class="pricing-header px-3 py-3 pt-md-5 pb-md-4 mx-auto text-center">
    <h1 class="display-4">Koronavírus elleni oltás</h1>
    <p class="lead">A Nemzeti Koronavírus Depó (NemKoViD - Mondj nemet a koronavírusra!) központi épületében különböző időpontokban oltásokat szervez. Jelentkezz koronavírus elleni oltásra!</p>

    <hr>
    <?php if(chech_flash_data("msg")) :?>
        <p class="lead mt-2 red font-weight-bold"><?php echo get_flash_data("msg")?></p>
        <hr>
    <?php endif?>

    <?php if($app != NULL) :?>
        <h4 class="display-8">Már van foglalásod:</h4>
        <p class="lead mt-2"><?php echo $app['date']->format('Y-m-d h:i')?></p>
        <form action="?p=leave" method="POST">
            <button class="btn btn-outline-danger" type="submit">Lemondás</button>
        </form>
        <hr>
    <?php endif?>

    <h2 class="display-5 mb-3">Időpontok</h2>
    <h2 class="display-6 mb-3"><?php echo $date->format("Y-m")?></h3>

    <div class="row row-cols-1 row-cols-md-3 mb-3 text-center">
        
        <?php foreach($events as $event):?>
        <?php $avaible = $event['max'] - count($event['users']); ?>        
        <div class="col">
            <div class="card mb-4 shadow-sm">
                <div class="card-header">
                    <h4 class="my-0 fw-normal"><?php echo $event['date']->format('Y-m-d')?></h4>
                </div>
                <div class="card-body">
                    <h4 class="card-title pricing-card-title"><?php echo $event['date']->format('H:i')?></h4>

                    <?php if($avaible > 0) :?>  <p class="lead green"><?php echo $avaible?> hely maradt. (<?php echo $event['max']?>)</p>
                    <?php else:?> <p class="lead red">Az összes hely betelt (<?php echo $event['max']?>)</p>
                    <?php endif;?>

                    <?php if($this->isLoggedIn() && $this->isAdmin()) :?> <a class="btn btn-outline-primary" href="/?p=join&id=<?php echo $event['id']?>">Megtekintés</a>
                    <?php elseif($this->isLoggedIn() && $avaible > 0 && $app == NULL) :?> <a class="btn btn-outline-primary" href="/?p=join&id=<?php echo $event['id']?>">Jelentkezés</a>
                    <?php elseif($avaible > 0 && $app == NULL) :?> <a class="btn btn-outline-primary" href="/?p=login&ref=<?php echo $event['id']?>">Bejelentkezés</a>
                    <?php endif;?>

                </div>
            </div>
        </div>
        <?php endforeach;?>
        
    </div>
    
    <hr>

    <a class="btn btn-outline-primary" href="/?p=index&s=<?php echo $shift-1?>">Előző hónap</a>
    <a class="btn btn-outline-primary" href="/?p=index&s=<?php echo $shift+1?>">Következő hónap</a>
</div>