︠f9302339-aef3-41c5-9995-bdef8f01f409︠
# Kilencedik gyakorlat
︡5b4c7a67-c7c2-41b8-ba71-9a624f2a1478︡
︠c9f5ec36-8c52-4913-9b34-52ec82e847e6s︠
# Olvasson be a billentyűzetről egy x egész számot, és írjon programot, amely kiírja az összes tökéletes számot x alatt!
# A számelméletben tökéletes számnak nevezzük azokat a természetes számokat, amelyek megegyeznek az önmaguknál kisebb osztóik összegével.
x = int(raw_input("Enter an integer: "))
for i in [2..x]:
    if i == sum(divisors(i)) - i:
        print(i)
print("Osztók összege: ",sum_of_smaller_divs(x))
︡7d5121bb-a94a-4750-a0f9-59d8a37752bd︡{"raw_input":{"prompt":"Enter an integer: "}}︡{"delete_last":true}︡{"raw_input":{"prompt":"Enter an integer: ","submitted":true,"value":"6"}}︡{"stdout":"6\n"}︡{"stdout":"Osztók összege:  6\n"}︡{"done":true}
︠beaba3d1-453a-4f06-8ced-e2240efae240s︠
# Írjon függvényt, amely visszatér a paraméterben kapott egész szám önmagánál kisebb osztóinak összegével!
def sum_of_smaller_divs(n):
    return sum(divisors(n)) - n

sum_of_smaller_divs(284)
︡2957bcd7-e93b-4709-8692-9ff0eb386322︡{"stdout":"220\n"}︡{"done":true}
︠43d693db-0282-47f9-8d28-38ca8cb481fd︠
# Írjon függvényt, amely előállítja egy egész szám osztóösszeg-sorozatát! A függvény egy kételemű listával
# térjen vissza: első eleme az osztóösszeg-sorozat listában tárolva, a második elem egy rendezett pár:
# a pár első komponense True, ha a sorozat terminál; False ha nem. Nem termináló sorozat esetén
# a pár második komponense legyen a sorozat periódusa!
def sum_of_smaller_divs(n):
    return sum(divisors(n)) - n

def Aliquot(n):
    result = list([n])
    next_item = sum_of_smaller_divs(n)
    while next_item != 0 and next_item not in result:
        result.append(next_item)
        next_item = sum_of_smaller_divs(next_item)
    if next_item == 0:
        return [result, (True, None)]
    else:
        return [result, (False, len(result) - result.index(next_item))]

Aliquot(10)
Aliquot(6)
Aliquot(220)
Aliquot(1000)
Aliquot(960)
︡90d5c872-bfa3-4a72-80f0-f6d77f7fedde︡{"stdout":"[[10, 8, 7, 1], (True, None)]\n"}︡{"stdout":"[[6], (False, 1)]\n"}︡{"stdout":"[[220, 284], (False, 2)]\n"}︡{"stdout":"[[1000, 1340, 1516, 1144, 1376, 1396, 1054, 674, 340, 416, 466, 236, 184, 176, 196, 203, 37, 1], (True, None)]\n"}︡{"stdout":"[[960, 2088, 3762, 5598, 6570, 10746, 13254, 13830, 19434, 20886, 21606, 25098, 26742, 26754, 40446, 63234, 77406, 110754, 171486, 253458, 295740, 647748, 1077612, 1467588, 1956812, 2109796, 1889486, 953914, 668966, 353578, 176792, 254128, 308832, 502104, 753216, 1240176, 2422288, 2697920, 3727264, 3655076, 2760844, 2100740, 2310856, 2455544, 3212776, 3751064, 3282196, 2723020, 3035684, 2299240, 2988440, 5297320, 8325080, 11222920, 15359480, 19199440, 28875608, 25266172, 19406148, 26552604, 40541052, 54202884, 72270540, 147793668, 228408732, 348957876, 508132204, 404465636, 303708376, 290504024, 312058216, 294959384, 290622016, 286081174, 151737434, 75868720, 108199856, 101437396, 76247552, 76099654, 42387146, 21679318, 12752594, 7278382, 3660794, 1855066, 927536, 932464, 1013592, 1546008, 2425752, 5084088, 8436192, 13709064, 20563656, 33082104, 57142536, 99483384, 245978376, 487384824, 745600776, 1118401224, 1677601896, 2538372504, 4119772776, 8030724504, 14097017496, 21148436904, 40381357656, 60572036544, 100039354704, 179931895322, 94685963278, 51399021218, 28358080762, 18046051430, 17396081338, 8698040672, 8426226964, 6319670230, 5422685354, 3217383766, 1739126474, 996366646, 636221402, 318217798, 195756362, 101900794, 54202694, 49799866, 24930374, 17971642, 11130830, 8904682, 4913018, 3126502, 1574810, 1473382, 736694, 541162, 312470, 249994, 127286, 69898, 34952, 34708, 26038, 13994, 7000, 11720, 14740, 19532, 16588, 18692, 14026, 7016, 6154, 3674, 2374, 1190, 1402, 704, 820, 944, 916, 694, 350, 394, 200, 265, 59, 1], (True, None)]\n"}︡{"done":true}
︠e14ca948-5367-4905-aa02-1bf99d4337a3︠
# Írjon függvényt a páros Goldbach-sejtés bemutatására! A páros Goldbach-sejtés szerint minden 2-nél nagyobb páros szám felírható két prímszám összegeként.
# Ha a függvény argumentuma nem megfelelő, a függvény dobjon ValueError kivételt!
def Even_Goldbach(n):
    if n <= 2 or n % 2 != 0:
        raise ValueError
    for i in prime_range(n):
        j = n - i
        if is_prime(j):
            return [i, j]

try:
    Even_Goldbach(6)
    Even_Goldbach(64562200)
    Even_Goldbach(64562201)
except ValueError:
    print("Nem megfelelő arg.")
︡e8dc248c-8a15-4168-b20b-a3070b9a19a2︡{"stdout":"[3, 3]\n[23, 64562177]"}︡{"stdout":"\nNem megfelelő arg.\n"}︡{"done":true}
︠ad9875f4-6550-4b6f-8894-c8d863a11ba3︠









