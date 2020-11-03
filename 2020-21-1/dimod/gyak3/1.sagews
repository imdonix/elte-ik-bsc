︠1c0201ae-a797-459c-90d1-eddcdbab25d6︠
# Harmadik gyakorlat: relációk és függvények

# Egy X halmazon értelmezett binér relációt formálisan X-beli rendezett párok halmazaként szoktunk definiálni. Írjunk eljárásokat, melyek egy ilyen formában
# adott relációról megmondják, hogy az reflexív ill. tranzitív-e (két külön eljárást)! A bemenetük az X halmaz és a reláció.
# Pl.:
# Is_Reflexive({1, 2, 3, 4}, [[1, 1], [2, 2], [3, 3], [4, 4]]) válasza legyen True,
# Is_Transitive({1, 2, 3, 4}, [[1, 2], [2, 3], [1, 4], [2, 2]]) pedig False.

def Is_Reflexive(A, R):
    for i in A:
        if [i, i] not in R:
            return False
    return True

def Is_Transitive(A, R):
    for a in A:
        for b in A:
            for c in A:
                if[a,b] in R and [b,c] in R and [a,c] not in R:
                    return False
    return True

Is_Reflexive({1, 2, 3, 4}, [[1, 1], [2, 2], [3, 3], [4, 4]])
Is_Transitive({1, 2, 3, 4}, [[1, 2], [2, 3], [1, 4], [2, 2]])
︡314520d9-9023-4144-beb6-840526a4638a︡{"stdout":"(1, 3)\n"}︡{"stdout":"1\n"}︡{"stdout":"[3, 2]\n"}︡{"stdout":"True\n"}︡{"stdout":"False\n"}︡{"done":true}
︠e7840bf4-50e1-4496-86ff-f22fa532e902︠
# Írjon függvényt, amely megadja a paraméterként kapott reláció értelmezési tartományát!

def domain(R):
    result = set([])
    for i in R:
        result.add(i[0])
    return result

domain([[1, 1], [2, 2], [3, 3], [4, 4]])
︡9fcb2b39-19fd-482d-b28b-7f713f14c9a7︡{"stdout":"set([1, 2, 3, 4])\nset([1, 2, 3, 4])\n"}︡{"done":true}
︠962e6579-80bc-4a68-a69c-e85486e89f01︠
# Írjon függvényt, amely megadja egy paraméterként kapott reláció adott halmaz szerinti képét!

def image(R, H):
    result = set([])
    for i in R:
        if i[0] in H:
            result.add(i[1])
    return result

image([[1, 2], [2, 3], [1, 4], [2, 2]], {1, 2})
︡aa814f79-d472-4615-acb6-60ad8fc3fd14︡{"stdout":"set([2, 3, 4])\n"}︡{"done":true}
︠363247d2-8b59-4c02-ba48-61467a83b030︠
# Írjon függvényt, amely visszatér a paraméterként kapott ekvivalenciareláció ekvivalenciaosztályaival!

def Is_Reflexive(A, R):
    for i in A:
        if [i, i] not in R:
            return False
    return True

def Is_Transitive(A, R):
    for a in A:
        for b in A:
            for c in A:
                if[a,b] in R and [b,c] in R and [a,c] not in R:
                    return False
    return True

def Is_Simmetric(A, R):
    for a in A:
        for b in A:
            if [a,b] in R and [b,a] in R:
                return True
    return False

def domain(R):
    result = set([])
    for i in R:
        result.add(i[0])
    return result

def eq_Classes(R):
    result = set([])
    dmn = domain(R)
    for i in dmn:
       result.add(Set(image(R, {i})))
    return Set(result)

eq_Classes([[1,1],[1,5],[2,2],[3,3],[3,4],[4,3],[4,4],[5,1],[5,5]])
︡9a27ef72-fd71-4f59-81a9-0ac7ab97cd2e︡{"stdout":"{{3, 4}, {1, 5}, {2}}\n"}︡{"done":true}
︠c1b004ff-13fd-440b-8acb-752a7bde199d︠
# Írjon függvényt, amely paraméterként kapott függvény (a megadási módja az előző feladatokban is használt) adott helyen vett helyettesítési értékével tér vissza!

def function_value(f, x):
    for i in f:
        if i[0] == x:
            return i[1]
    return None

function_value([[1,2], [3,5], [5,0]], 5)
︡1a930f59-764c-4419-88fb-9773dda326c7︡{"stdout":"0\n"}︡{"done":true}
︠1c7d2ffe-add8-49f7-b14b-04aace62ace1︠
# Írjon függvényt, amely paraméterként kapott függvényről (a megadási módja az előző feladatokban is használt) eldönti, hogy injektív-e!

def domain(R):
    result = set([])
    for i in R:
        result.add(i[0])
    return result

def function_value(f, x):
    for i in f:
        if i[0] == x:
            return i[1]
    return None

def Is_Injective(f):
    dmn = domain(f)
    for i in dmn:
        for j in dmn:
            if function_value(f, i) == function_value(f, j) and i != j:
                return False
    return True

Is_Injective([[1,2], [3,5], [5,0]])
︡41d6347a-5413-4eb9-9386-40cceb8782e4︡{"stdout":"True\n"}︡{"done":true}
︠2a3ae475-6cda-479f-b387-37e94d1b0490︠
# SZÁMELMÉLETI FOGALMAK
# Oszthatóság: Egy a egész szám osztója egy b egész számnak, ha van olyan n egész szám, melyre a·n=b. Jele: a|b (a osztója b-nek).
# Egység: Az egységek olyan számok, melyek osztói minden aktuális számhalmazbeli számnak.
# Felbonthatatlan: A 'a' számtól (és nullától) különböző számot felbonthatatlan számnak nevezzük, ha csak úgy bontható fel két egész szám szorzatára, hogy valamelyik tényező egység, azaz: a = b * c => b vagy c egység.
# Prímszám: Az 'a' egységtől és nullától különböző számot prímszámnak (vagy röviden prímnek) nevezzük, ha csak úgy lehet osztója két egész szám szorzatának, ha legalább az egyik tényezőnek osztója, azaz: a | b * c => a | b vagy a | c.
# Összetett szám: Összetett számnak nevezzük az olyan 1-nél (szigorúan) nagyobb számokat, amelyeknek kettőnél több osztója van (, azaz van legalább egy valódi osztójuk).
# Másképp fogalmazva, az összetett szám nem lehet nulla, egység, vagy felbonthatatlan szám.

# Az alábbi diszkrét matematikai fogalmak köszönhetnek vissza az első zárthelyiben egy-egy programozási feladatban:
# halmaz, halmazrendszer, reláció, értelmezési tartomány, értékkészlet, leszűkítés, elem/halmaz képe,
# elem/halmaz inverz képe, reflexív, szimmetrikus, tranzitív, antiszimmetrikus, ekvivalenciaosztály, függvény, injektív, szürjektív.
