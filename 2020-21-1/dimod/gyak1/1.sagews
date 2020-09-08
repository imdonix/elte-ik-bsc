︠d184a881-975e-4759-8274-d8f33e8847e9s︠
# Első gyakorlat: Ismerkedés a felülettel

# SHIFT + ENTER/ RUN gomb : program futtatása
# DELETE : program bezárása

'Forras: https://share.cocalc.com/share/d8089187e18cbe1c1f7d4b3a12ffb5a2106abfbf/tutorials/Basics/Basics.ipynb?viewer=share'
︡ddce002d-6c32-4177-b816-a812e2c7c32f︡{"stdout":"'Forras: https://share.cocalc.com/share/d8089187e18cbe1c1f7d4b3a12ffb5a2106abfbf/tutorials/Basics/Basics.ipynb?viewer=share'\n"}︡{"done":true}
︠5189b3cb-1c7d-45a7-b75a-ef59dd99a569︠
'1. szakasz'
'Valtozok es kiirasuk'
x = 0 # letrehozunk egy X valtozot, aminek az erteket 0-ra allitjuk
print(x) # kiiratjuk X-et

y = 'code' # nincs tipusmegnevezes, az ertekadassal ez megtortenik automatikusan
print(y)

print(x, y) # tobbet is kiirathatunk
︡6279bf78-e05a-4a93-8ea1-3707e1cb0797︡{"stdout":"'1. szakasz'\n"}︡{"stdout":"'Valtozok \\xc3\\xa9s kiirasuk'\n"}︡{"stdout":"0\n"}︡{"stdout":"code\n"}︡{"stdout":"(0, 'code')\n"}︡{"done":true}
︠59010315-add0-4e0f-8ce4-8198b164d1eas︠
'Egy blokk vegrehajtasat nem kell feltetlen tulgondolni.'
x + 4
︡7d93be56-a6d0-4e61-a519-3d60068cc023︡{"stdout":"'Egy blokk vegrehajtasat nem kell feltetlen tulgondolni.'\n"}︡{"stdout":"4\n"}︡{"done":true}
︠2b70c41b-1350-4997-aefa-96d1391c24e9︠
'Konkatenacio'
x, y = 2, 3 # parhuzamos ertekadas
z = x + y
print(z)
︡ab5bd0fa-e30e-40ee-b2fd-5e92812ca6a1︡{"stdout":"'Konkatenacio'\n"}︡{"stdout":"5\n"}︡{"done":true}
︠d7eb980c-2932-43a9-a6d7-59ffe18f42ccs︠
x = 2
x = x + 3
print(x)
︡6dd039f6-42a2-41dc-a16c-92d0ea883e12︡{"stdout":"5\n"}︡{"done":true}
︠b6ef52f9-b4de-463d-9829-ac3608f4f9f1︠
x = 2
x += 3
print(x)
'A -= es a *= is letezik.'
︡784fc8a0-3870-4fc5-b872-2f5eb726e3ba︡{"stdout":"5\n"}︡{"stdout":"'A -= es a *= is letezik.'\n"}︡{"done":true}
︠9e7e0794-1fc3-492e-bbcd-4e06f42af3a9︠
'Osszehasonlitas'
4 < 5 # logikai ertekeket ad vissza
4 > 5
4 == 4
4 >= 4
︡23468508-104a-4dd4-81c9-63a6cc2dc1c7︡{"stdout":"'Osszehasonlitas'\n"}︡{"stdout":"True\n"}︡{"stdout":"False\n"}︡{"stdout":"True\n"}︡{"stdout":"True\n"}︡{"done":true}
︠f091899c-78e2-4097-bbd1-181f57977d50︠
'Numerikus operatorok'
5 / 2 # hagyomanyos osztas
5 // 2 # egeszreszes osztas
5 % 2 # maradekos osztas
5 ** 2 # hatvanyozas, 5 a 2-en

x = 5
x **= 2
print(x)
︡f7269f81-0001-4157-b310-1490531b7645︡{"stdout":"'Numerikus operatorok'\n"}︡{"stdout":"5/2\n"}︡{"stdout":"2\n"}︡{"stdout":"1\n"}︡{"stdout":"25\n"}︡{"stdout":"25\n"}︡{"done":true}
︠e363168d-b1b6-4d97-808f-3a5d52d40625︠
'Fuggvenyek es argumentumok'
def square(x): # X a bemeno parameter
    return x * x

square(4) # fuggveny meghivasa
︡ab742edb-1a83-4a8d-86d2-cdba7167d8fe︡{"stdout":"'Fuggvenyek'\n"}︡{"stdout":"16\n"}︡{"done":true}
︠7040d177-4f14-4f2c-8641-0a986f695874︠
def pow(x, exponent=2 # az exponent erteke 2, ha nincs ertek megadva):
    result = x ** exponent
    return result

print( pow(4) )
print( pow(4,3) )
︡4ea04d64-6aee-4eb0-899a-ff714799d7dd︡{"stdout":"16\n"}︡{"stdout":"64\n"}︡{"done":true}
︠78665936-92f0-4f03-8bac-173a146b7290︠










