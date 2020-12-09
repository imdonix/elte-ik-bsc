<?php
class Main
{
    public $apps;
    public $users;
    private $current;

    public function __construct()
    {
        $this->apps = new Storage(new JsonIO("db\appointments.json"));
        $this->users = new Storage(new JsonIO("db\users.json"));
        if(isset($_SESSION['id'])) $this->current = $this->users->findOne(['id' => $_SESSION['id']]);
    }

    public function isLoggedIn()
    {
        return isset($_SESSION['id']);
    }

    public function getName()
    {
        return $this->current['name'];
    }

    public function getTAJ()
    {
        return $this->current['taj'];
    }

    public function getAddress()
    {
        return $this->current['address'];
    }

    public function isAdmin()
    {
        return $this->current['admin'];
    }

    public function getApp()
    {
        foreach ($this->getAllEvent() as $event)
            foreach ($event['users'] as $id)
                if($id === $_SESSION['id'])
                    return $event;
        return false;
    }

    public function getEventsAt($now)
    {
        return array_filter($this->getAllEvent(), function ($app) use(&$now)
        {
            return $app['date']->format('y-m') == $now->format('y-m');
        });
    }

    private function getAllEvent()
    {
        return array_map(function ($app)
        {
            $app['date'] = new DateTime($app['date']['date']);
            return $app;
        }, $this->apps->findAll());
    }

    private function createAppWithValidDate($app)
    {

        $app['date'] = new DateTime($app['date']['date']);
        return $app;
    }

    private function addNewAccount()
    {
        $this->users->add(
            [
                'name' => $_POST["name"],
                'taj' => $_POST["taj"],
                'address' => $_POST["address"],
                'password' => password_hash($_POST["password"], PASSWORD_DEFAULT),
                'email' => $_POST["email"],
                'admin' => "admin@nemkovid.hu" == $_POST["email"]
            ]);
    }

    private function addNewEvent($date, $count)
    {
        $this->apps->add(
            [
                'date' => $date,
                'max' => $count,
                'users' => []
            ]);
    }

    private function isValidTAJ($taj)
    {
        return is_numeric($taj) && strlen($taj) == 9;
    }

    private function isEmptyEmail($email)
    {
        return $this->users->findOne(['email' => $email]) == NULL;
    }

    private function join($id)
    {
        $event = $this->apps->findById($id);
        array_push($event['users'], $_SESSION['id']); 
        $this->apps->update($event['id'], $event);
    }

    private function leave($app)
    {
        $event = $this->apps->findById($app);
        $event['users'] = array_filter($event['users'], function($user) {
            return $user != $_SESSION['id'];
        });
        $this->apps->update($app, $event);
    }

    //ROUTES

    //GETS

    public function showMain()
    {
        include './components/main.php';
    }

    public function showLogin()
    {
        include './components/login.php';
    }

    public function showRegister()
    {
        include './components/register.php';
    }

    public function showEvent()
    {
        include './components/event.php';
    }

    public function showJoin()
    {
        include './components/join.php';
    }

    //POSTS

    public function logout()
    {
        unset($_SESSION['id']);
        header("Location: index.php?p=index");
        exit();
    }

    public function register()
    {
        $succes = false;
        if(isset($_POST['name']) && !empty($_POST['name']))
        {   
            if(isset($_POST['taj']) && $this->isValidTAJ($_POST['taj']))
            {
                if(isset($_POST['address']) && !empty($_POST['address']))
                {
                    if(isset($_POST['password']) && !empty($_POST['password']) && isset($_POST['passwordagain']) && $_POST['passwordagain'] == $_POST['password'])
                    {
                        if(isset($_POST['email'])  && !empty($_POST['email']) && $this->isEmptyEmail($_POST['email']))
                        {
                            $this->addNewAccount();
                            set_flash_data("msg", "Sikeresen regisztráltál az oldalra! Most jelentkezz be.");
                            $succes = true;
                        }
                        else
                            set_flash_data("msg", "Nem adtál meg email-címet vagy már használatban van.");
                    }
                    else
                        set_flash_data("msg", "A jelszók nem egyeznek.");
                }
                else
                    set_flash_data("msg", "Nem adtál meg értesítési címet.");
            }
            else
                set_flash_data("msg", "Hibás taj számot adtál meg.");
        }
        else
            set_flash_data("msg", "Nem adtál meg nevet.");

        
        set_flash_data("email", $_POST['email']);  
        if($succes)

            header("Location: index.php?p=login");
        else
        {
            set_flash_data("taj", $_POST['taj']);
            set_flash_data("address", $_POST['address']);  
            set_flash_data("name", $_POST['name']);
            header("Location: index.php?p=register");
        }
        exit();
    }

    public function login()
    {
        $user = $this->users->findOne(['email' => $_POST['email']]);
        if($user != NULL)
        {
            if(password_verify($_POST['password'], $user['password']))
            {
                $_SESSION['id'] = $user['id'];

                if(empty($_POST['ref']))
                    header("Location: index.php?p=index");
                else
                    header("Location: index.php?p=join&id=" . $_POST['ref']);
                    
                exit();
            }
            else
                set_flash_data("msg", "Hibás jelszót adtál meg.");
        }
        else
            set_flash_data("msg", "Nem található felhasználó ezzel az email címmel.");

        set_flash_data("ref", $_POST['ref']);
        set_flash_data("email", $_POST['email']);
        header("Location: index.php?p=login");
        exit();
    }

    public function addEvent()
    {
        if($this->isLoggedIn() && $this->isAdmin())
        {
            if(isset($_POST['date']) && !empty($_POST['date']) && isset($_POST['time']) && !empty($_POST['time']) )
            {
                $date = date_create($_POST['date'] . ' ' . $_POST['time']);
                if($date)
                {
                    if($date > date_create("now"))
                    {
                        if(isset($_POST['count']) && is_numeric($_POST['count']) && intval($_POST['count']) > 0)
                        {
                            $this->addNewEvent($date, $_POST['count']);
                            header("Location: index.php?p=index");
                            exit();
                        }
                        else
                            set_flash_data("msg", "Adj meg valós fogadóhelyet.");
                    }
                    else
                        set_flash_data("msg", "Nem készíthetsz a múltba eseményt");
                }
                else
                    set_flash_data("msg", "Hibás dátum és/vagy idő formátumot adtál meg.");
            }
            else
                set_flash_data("msg", "Adj meg dátumot és időt.");
        }
        else
            set_flash_data("msg", "Csak admin felhasználó hozhat létre új eseményt");


        set_flash_data("date", $_POST['date']);
        set_flash_data("time", $_POST['time']);
        set_flash_data("count", $_POST['count']);
        header("Location: index.php?p=event");
        exit();
    }

    public function joinEvent()
    {
        $event = $this->apps->findById($_POST['id'] ?? "");
        if($this->isLoggedIn())
        {
            if($this->getApp() == NULL)
            {
                if($event != NULL)
                {
                    if(isset($_POST['accept']))
                    {
                        if($event['max'] > count($event['users']))
                        {
                            $this->join($_POST['id']);
                            set_flash_data("msg", "Sikeresen jelentkeztél az időpontra");
                            header("Location: index.php?p=index");
                            exit(); 
                        }
                        else
                            set_flash_data("msg", "Az időpont már betelt");
                    }
                    else
                        set_flash_data("msg", "Fogad el a feltételek hogy jelentkezzhess az időpontra.");
                }
                else
                    set_flash_data("msg", "Ez az esemény már nem létezik.");
            }
            else
                set_flash_data("msg", "Már jelentkeztél egy időpontra");
        }
        else
            set_flash_data("msg", "Be kell jelentkezned mielőtt csatlakoznál.");
        
        header("Location: index.php?p=join&id=" . $_POST['id']);
        exit();
    }

    public function leaveEvent()
    {
        if($this->isLoggedIn())
        {
            $app =  $this->getApp();
            if($app != NULL)
            {
                $this->leave($app['id']);
                set_flash_data("msg", "Sikeresen lemondtad az időpontot.");
                header("Location: index.php");
            }
            else
                set_flash_data("msg", "Nincs foglalásod");
        }
        else
            set_flash_data("msg", "Be kell jelentkezned mielőtt lemondanád a foglalásod.");

        header("Location: index.php");
        exit();
    }
}
?>