<div class="row justify-content-md-center">
    <div class="col col-lg-6 px-3 py-3 pt-md-5 pb-md-4 text-center">
        <form action="/?p=login" method="POST" novalidate>
            <h1 class="h3 mb-3 fw-normal">Jelentkezz be</h1>

            <?php if(chech_flash_data("msg")) :?>
                <p class="lead mt-2 red font-weight-bold"><?php echo get_flash_data("msg")?></p>
            <?php endif?>

            <label for="email" class="visually-hidden mt-2">E-mail cím</label>
            <input type="email" id="email" name="email" class="form-control" placeholder="E-mail cím" value="<?php echo get_flash_data('email');?>">

            <label for="password" class="visually-hidden">Jelszó</label>
            <input type="password" id="password" name="password" class="form-control mt-2" placeholder="Jelszó" required="">
            
            <input type="hidden" name="ref" value="<?php echo $_GET['ref'] ?? get_flash_data('ref');?>">
            
            <button class="w-100 btn btn-lg btn-primary mt-2" type="submit">Bejelentkezés</button>
            
            <p class="mt-3 mb-3 text-muted"><a href="/?p=register">Regisztráció</a></p>
        </form>
    <div>
</div>