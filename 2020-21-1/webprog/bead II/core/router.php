<?php
class Router 
{
    private $routes = [];
    private $main;

    public function __construct($main)
    {
        $this->main = $main;
    }

    public function start() 
    {
        $path = $_GET["p"] ?? "index";
        $http_method = $_SERVER["REQUEST_METHOD"];

        foreach ($this->routes as $route) 
            if ($route["path"] === $path && $route["http-method"] === $http_method) 
            {
                $function = $route["function"];
                $this->main->$function();
                return;
            }
        include './components/404.php';
    }

    public function preprocess()
    {
        if($_SERVER["REQUEST_METHOD"] == "POST")
            $this->start();
    }

    private function request($path, $function, $method)
    {
        $this->routes[] = [
            "path" => $path,
            "http-method" => $method,
            "function" => $function
            ];
    } 

    public function get($path, $function) 
    {
        $this->request($path, $function, "GET");
    }

    public function post($path, $function) 
    { 
        $this->request($path, $function, "POST");
    }
}
?>