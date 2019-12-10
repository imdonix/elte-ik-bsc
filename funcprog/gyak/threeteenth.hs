data Privilege = Unprivileged | Admin
    deriving (Show,Eq)
data Cookie = LoggedIn String Privilege | LoggedOut
    deriving (Show,Eq)
type User = (String, String, Privilege)

db = [("dumbledore","abracadabra",Unprivileged), ("root", "secret", Admin), ("bela", "korte", Unprivileged)]

register :: String -> String -> Cookie -> [User] -> [User]
register username passwd (LoggedIn _ Admin) db = (username, passwd, Unprivileged) : db
register _ _ _ db = db

getUser username db 
    | elem username (map (\(s,_,_) -> s) db) = Just ((\(_,p,a) -> (p,a))(head (filter (\(s,_,_) -> s == username) db)))
    | True = Nothing

login u p db
    | elem (u,p) (map (\(a,b,_) -> (a,b)) db) = LoggedIn u Unprivileged
    | True = LoggedOut 

replacepass name new (n,p,pre)
    | name == n = (n,new,pre)
    | True = (n,p,pre)
passwd new (LoggedIn name _) db = map (replacepass name new) db
passwd _ _ db = db

delete name (LoggedIn _ Admin) db = filter (\(n,p,a) -> n /= name) db
delete _ _ db = db

users db = map (\(n,_,_) -> n) db