<div class="row justify-content-md-center">
    <div class="col col-lg-6 px-3 py-3 pt-md-5 pb-md-4 text-center">
        <form action="/?p=register" method="POST" novalidate>
            <h1 class="h3 mb-3 fw-normal">Regisztráció</h1>

            <?php if(chech_flash_data("msg")) :?>
                <p class="lead mt-2 red font-weight-bold"><?php echo get_flash_data("msg")?></p>
            <?php endif?>

            <label for="name" class="visually-hidden">Teljes név</label>
            <input type="text" id="name" name="name" class="form-control mt-2" value="<?php echo get_flash_data('name');?>" placeholder="Teljes név">

            <label for="taj" class="visually-hidden">TAJ szám</label>
            <input type="text" id="taj" name="taj" class="form-control mt-2" value="<?php echo get_flash_data('taj');?>" placeholder="TAJ szám" >

            <label for="address" class="visually-hidden">Értesítési cím</label>
            <input type="text" id="address" name="address" class="form-control mt-2" value="<?php echo get_flash_data('address');?>" placeholder="Értesítési cím">

            <label for="email" class="visually-hidden">E-mail cím</label>
            <input type="email" id="email" name="email" class="form-control mt-3" value="<?php echo get_flash_data('email');?>" placeholder="E-mail cím">

            <label for="password" class="visually-hidden">Jelszó</label>
            <input type="password" id="password" name="password" class="form-control mt-4" placeholder="Jelszó">

            <label for="passwordagain" class="visually-hidden">Jelszó újra</label>
            <input type="password" id="passwordagain" name="passwordagain" class="form-control mt-2" placeholder="Jelszó újra">

            <button class="w-100 btn btn-lg btn-primary mt-2" type="submit">Regisztráció</button>

            <p class="mt-3 mb-3 text-muted"><a href="/?p=login">Bejelentkezés</a></p>
        </form>
    <div>
</div>