<?php
$logged = $main->isLoggedIn();
if($logged) 
{
  $name = $main->getName();
  $admin = $main->isAdmin();
}
?>

<header class="d-flex flex-column flex-md-row align-items-center p-3 px-md-4 mb-3 bg-white border-bottom shadow-sm">
  <p class="h5 my-0 me-md-auto fw-normal"><a href="/" >Nemzeti Koronavírus Depó</a></p>
  <nav class="my-2 my-md-0 me-md-3">
    <?php if($logged) : ?>
      <form action="/?p=logout" method="post">
          <span class="p-3 text-dark"> <?php echo $name?></span>
          <span class="p-3 text-muted"> (<?php echo $admin ? "Adminisztrátor" : "Felhasználó"?>) </span>
          <?php if($admin) : ?>
            <a class="btn btn-primary" href="/?p=event">Új időpont meghirdetése</a>
          <?php endif; ?>
          <button class="btn btn-light" type="submit">Kijelentkezés</button>  
        </form>        
    <?php else : ?>
        <a class="btn btn-outline-success" href="/?p=login">Bejentkezés</a>
        <a class="btn btn-outline-primary" href="/?p=register">Regisztráció</a>
    <?php endif; ?>
  </nav>
</header>