<?php
function set_flash_data($key, $value) 
{
  $_SESSION[$key] = $value;
}

function chech_flash_data($key)
{
  return isset($_SESSION[$key]);
}

function get_flash_data($key) 
{
  $value = $_SESSION[$key] ?? null;
  unset($_SESSION[$key]);
  return $value;
}
?>