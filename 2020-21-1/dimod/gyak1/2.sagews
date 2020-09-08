︠d184a881-975e-4759-8274-d8f33e8847e9︠
# Első gyakorlat: Ismerkedés a felülettel

# SHIFT + ENTER/ RUN gomb : program futtatása
# DELETE : program bezárása

'Forras: https://share.cocalc.com/share/d8089187e18cbe1c1f7d4b3a12ffb5a2106abfbf/tutorials/Basics/Basics.ipynb?viewer=share'
'2. szakasz'
'Elagazasok es ciklusok'
x = 0

if x == 1: # ha
    print("x is 1")
elif x > 1: # mas esetben
    print("x is > 1")
else: # minden egyeb esetben
    print("x is < 1")
︡e8f0620b-0e5a-4e89-bc68-3f306dbe37b9︡{"stdout":"'2. szakasz'\n"}︡{"stdout":"'Elagazasok'\n"}︡{"stdout":"x is < 1\n"}︡{"done":true}
︠0fe79d93-024b-454f-85e7-da753bb3f0fb︠
x = 1
y = 5
z = 5

if z >= x and z <= y: # halmozott feltetelek
    print("z lies within range [x,y]")

if z == x or z == y: # megengedo vagy
    print("z lies on the boundary of the range [x,y]")
︡cb4d2dd7-9c83-462f-819b-75a7aae89f30︡{"stdout":"z lies within range [x,y]\n"}︡{"stdout":"z lies on the boundary of the range [x,y]\n"}︡{"done":true}
︠c1c00045-600e-42ed-805f-f44054fd72bd︠
i = 0

while i < 10: # a kettospont helyettesiti a { } jeleket
    print(i)
    i += 1  # equivalent to i = i + 1

print("Final value:", i)
︡5aee54b1-9f58-4bca-b7af-bab1f56fc69b︡{"stdout":"0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n"}︡{"stdout":"('Final value:', 10)\n"}︡{"done":true}
︠fcfd97c6-0bdb-40b7-8660-d08d62c1ded6︠
for j in range(0,10): # 0 es 9 kozotti szam
    print(j) # uj sor

print("Final value:", j)
︡41e6a86b-fdd2-471f-bfb1-359ec05c22fc︡{"stdout":"0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n"}︡{"stdout":"('Final value:', 9)\n"}︡{"done":true}
︠ac13f765-ad7e-4eab-a869-6b1c35b90f8a︠
list(range(10)) # 0-9
list(range(0, 10)) # 0-9
list(range(1, 10, 2)) # 1-9, minden masodik
list(range(10, 5, -1)) # 10-6, csokkeno sorrendben, egyesevel
︡7d6c6f42-336a-42d8-96bb-58fcd03af7e3︡{"stdout":"[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]\n"}︡{"stdout":"[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]\n"}︡{"stdout":"[1, 3, 5, 7, 9]\n"}︡{"stdout":"[10, 9, 8, 7, 6]\n"}︡{"done":true}
︠8826c94e-26d5-42e3-a51c-7d3b0a80f91a︠
︠b5176e10-28e2-4d4d-8aa1-6d299fb6a437︠









