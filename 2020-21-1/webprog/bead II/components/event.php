<div class="pricing-header px-3 py-3 pt-md-5 pb-md-4 mx-auto text-center">
    <h3 class="display-4">Új időpont meghirdetése</h3>

    <hr>

    <div class="row justify-content-md-center">
        <div class="col col-lg-6 px-3 py-3 pt-md-5 pb-md-4 text-center">
            <form action="/?p=addEvent" method="POST" novalidate>
                <h1 class="h3 mb-3 fw-normal">Töltsd ki a időpont adatait</h1>

                <?php if(chech_flash_data("msg")) :?>
                    <p class="lead mt-2" style="color: red"><?php echo get_flash_data("msg")?></p>
                <?php endif?>

                <label for="date" class="visually-hidden mt-2">Dátum</label>
                <input type="date" id="date" name="date" class="form-control" value="<?php echo get_flash_data("date")?>">

                <label for="time" class="visually-hidden">Idő</label>
                <input type="time" id="time" name="time" class="form-control mt-2" value="<?php echo get_flash_data("time")?>">

                <label for="count" class="visually-hidden">Helyek száma</label>
                <input type="number" id="count" name="count" class="form-control mt-2" value="<?php echo get_flash_data("count")?>">

                <button class="w-100 btn btn-lg btn-primary mt-2" type="submit">Bejelentés</button>
            </form>
        <div>
    </div>
</div>