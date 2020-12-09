<?php
    $app = $this->apps->findById($_GET['id'] ?? '');
    if($app != NULL)
    {
        $app = $this->createAppWithValidDate($app);
        $disp = array();
        foreach($app['users'] as $i)
            array_push($disp, $this->users->findById($i));
    }
?>

<?php if($app == NULL):?>
    <?php include './components/404.php'; ?>
<?php elseif(!$this->isLoggedIn()) :?>
    <h4 class="display-6">Be kell jelentkezned mielőtt jelentkeznél.</h4>
    <a class="btn btn-outline-success" href="/?p=login">Bejentkezés</a>
<?php else :?>

    <div class="row row-cols-1 row-cols-md-8 mb-3 text-center ">
        <div class="col justify-content-center">
            <div class="card mb-4 shadow-sm">
                <div class="card-header">
                    <h4 class="display-6">Jelentkezés az időpontra</h4>
                </div>
                <div class="card-body">
                    <h4 class="display-6"><?php echo $app['date']->format("Y-m-d")?></h4>
                    <h4 class="display-4"><?php echo $app['date']->format("h:i")?></h4>
                    <hr>

                    <?php if($this->isAdmin()) :?>
                        <h4 class="display-6">Eddig jelentkezett (<?php echo count($app['users'])?>/<?php echo $app['max']?>)</h4>
                        <ul class="list-unstyled mt-3 mb-4">
                            <?php foreach($disp as $us):?>
                                <li>Név: <?php echo $us['name']?> TAJ: <?php echo $us['taj']?> Cím: <?php echo $us['address']?></li>
                            <?php endforeach;?>
                        </ul>
                    <?php else :?>

                        <ul class="list-unstyled mt-3 mb-4">
                            <li>Név: <?php echo $this->getName()?></li>
                            <li>TAJ: <?php echo $this->getTAJ()?></li>
                            <li>Cím: <?php echo $this->getAddress()?></li>
                        </ul>
                        <hr>

                        <form action="/?p=join" method="POST" novalidate>
                            <div class="form-row">
                                <input type="hidden" name="id" value="<?php echo $_GET['id'] ?? ""?>">
                                <div class="col">
                                    <div class="form-check">
                                        <input type="checkbox" class="form-check-input" id="accept" name="accept">
                                        <label class="form-check-label" for="accept">Elfogadom hogy kötelező megjelenni, és lehetnek az oltásnak mellékhatásai</label>
                                    </div>
                                </div>
                                <div class="col">
                                    <button class="w-50  btn btn-lg btn-primary mt-2" type="submit">Jelentkezés megerősítése</button>
                                </div>
                            </div>
                        </form>
                            <?php if(chech_flash_data("msg")) :?>
                                <p class="lead mt-2" style="color: red"><?php echo get_flash_data("msg")?></p>
                            <?php endif?>
                    <?php endif;?>
                </div>
            </div>
        </div>
        
    </div>


<?php endif;?>