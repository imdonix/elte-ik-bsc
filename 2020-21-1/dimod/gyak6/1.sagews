︠f51bbf1b-4775-4e9d-960b-a579614b0f65︠
# Írjon függvényt, amely egy adott N-hez megkonstruálja a legalább N hosszú, csupa összetett számokat tartalmazó intervallumot!

def compound_list(N):
    result = list()
    count = 1
    while len(result) < N:
        if is_prime(count):
            result = list([])
        else:
            result.append(count)
        count = count + 1
    return result

def compound_list2(N):
    return [factorial(N+1) + 2 .. factorial(N+1) + (N+1)]

compound_list(2)
compound_list2(2)
︡9c72d09f-d1de-4911-a65f-563079b43c06︡{"stdout":"[8, 9]\n"}︡{"stdout":"[8, 9]\n"}︡{"done":true}
︠3932d7c3-f73a-4178-bd17-b1236aec0840︠
# Írjon függvényt, amely eldönti, hogy a paramétere felbonthatatlan-e!

def Is_Irreducible(a):
    for b in [2..(a-1)]:
        if a % b == 0:
            return False
    return True

def Is_Unit(a):
    return (a == 1) or (a == -1)

def Is_Irreducible_sec(a):
    for b in [2..a]:
        if a % b == 0:
            c = a/b
            if (Is_Unit(b) and Is_Unit(c)):
                return True
    return False

Is_Irreducible(10)
Is_Irreducible_sec(10)
#Is_Irreducible(11)
#Is_Irreducible_sec(11)
︡9e179ecf-e54f-4ae6-b06e-e2c3bcb7e13b︡{"stdout":"False\n"}︡{"stdout":"False\n"}︡{"done":true}
︠37f9345a-0a98-465a-a28c-fdda6fc893f2︠
# Írjon függvényt a páros Goldbach-sejtés bemutatására! Ha a függvény argumentuma nem megfelelő, a függvény dobjon ValueError kivételt!

# A Goldbach-sejtés azt mondja ki, hogy:
# I. Minden 2-nél nagyobb páros szám előáll két prímszám összegeként.
# II. Minden 5-nél nagyobb páratlan szám előáll három prímszám összegeként.

def Even_Goldbach(n):
    if n <= 2 or n % 2 != 0:
        raise ValueError
    for i in prime_range(n):
        j = n - i
        if is_prime(j):
            return [i,j]

try:
    Even_Goldbach(40)
    Even_Goldbach(64562200)
    Even_Goldbach(64562201)
except ValueError:
    print "Nem megfelelő argumentum"
︡eb32bf63-eb7a-475e-ac8a-fe5309af95d9︡{"stdout":"[3, 37]\n[23, 64562177]"}︡{"stdout":"\nNem megfelelő argumentum\n"}︡{"done":true}
︠2470ef82-6873-4e77-bde5-32b856aaee09︠
# Számolja meg, hány prím van a [0;n] intervallumban!
n = input("Adjon meg egy számot")

len(prime_range(n))
len(prime_range(4))
︡d08243aa-97a1-49ec-968a-258dc67b3be7︡{"raw_input":{"prompt":"Adjon meg egy számot"}}︡{"delete_last":true}︡{"raw_input":{"prompt":"Adjon meg egy számot","submitted":true,"value":"3"}}︡{"stdout":"1\n"}︡{"stdout":"2\n"}︡{"done":true}
︠d337411e-7352-49a0-8351-0e01d04d8dc5︠










