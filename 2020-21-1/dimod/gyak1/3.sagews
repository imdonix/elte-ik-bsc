︠58f9104e-f214-463c-a2bf-37bab48caf62︠
'3. szakasz'
'Lista'
names = ['Rob', 'Clara']
ages = [21, 23]

print(names, ages)
print(len(names), 'Names:', names[0], names[1]) # len: tenyleges hossz, [0]: indexeles
print(len(ages), 'Ages:', ages[0], ages[1])
︡095fa8dd-cddd-40bf-b623-8e0d45a64db0︡{"stdout":"'3. szakasz'\n"}︡{"stdout":"'Lista'\n"}︡{"stdout":"(['Rob', 'Clara'], [21, 23])\n"}︡{"stdout":"(2, 'Names:', 'Rob', 'Clara')\n"}︡{"stdout":"(2, 'Ages:', 21, 23)\n"}︡{"done":true}
︠b71db1c5-ba58-48c2-8e05-35b27fdad5d0︠
names = ['Rob', 'Clara']
print(names)
del names[0] # elemet torol, elore hozza a tobbit
print(names)
names.append('Bob') # vegere szur be
print(names)
names.insert(0, 'Alice') # indexre szur be
print(names)
︡ab8c6082-00c2-4f1d-b992-bc1e8baa7bfc︡{"stdout":"['Rob', 'Clara']\n"}︡{"stdout":"['Clara']\n"}︡{"stdout":"['Clara', 'Bob']\n"}︡{"stdout":"['Alice', 'Clara', 'Bob']\n"}︡{"done":true}
︠cb2fee47-e99d-4e2e-bba4-21b025bc26a5︠
print(sorted(names)) # novekvo sorrend
print(names)

names.sort()
print(names)
︡0240336e-acc2-4ffa-84df-02e5e0282730︡{"stdout":"['Alice', 'Bob', 'Clara']\n"}︡{"stdout":"['Alice', 'Clara', 'Bob']\n"}︡{"stdout":"['Alice', 'Bob', 'Clara']\n"}︡{"done":true}
︠7756fc71-ebb9-41b5-b949-5359818ec34f︠
'Lista-konkatenacio'
students = ['Alice', 'Bob', 'Clara']
teachers = ['Fil', 'Clayton']
roster = students + teachers
roster
︡5b7fe743-1642-405d-9125-ddcd24450a70︡{"stdout":"'Konkatenacio'\n"}︡{"stdout":"['Alice', 'Bob', 'Clara', 'Fil', 'Clayton']\n"}︡{"done":true}
︠241cf1f6-686c-4964-9073-8fba1b2969fb︠
roster = ['Alice', 'Bob', 'Clara']
teachers = ['Fil', 'Clayton']
roster.extend(teachers)
roster
︡7d29c006-c8c9-4964-b8ba-b491435d4add︡{"stdout":"['Alice', 'Bob', 'Clara', 'Fil', 'Clayton']\n"}︡{"done":true}
︠b8aacf5b-6472-4e04-ba72-b213b7f07581︠
'Tuple'
person_1 = ('Rob', 21)
person_2 = ('Clara', 23)

print(person_1, person_2)

print('Names:', person_1[0], person_2[0])
print('Ages:', person_1[1], person_2[1])
︡b7a37519-aa6f-4cfb-88d4-bacabbdc9af4︡{"stdout":"'Tuple'\n"}︡{"stdout":"(('Rob', 21), ('Clara', 23))\n"}︡{"stdout":"('Names:', 'Rob', 'Clara')\n"}︡{"stdout":"('Ages:', 21, 23)\n"}︡{"done":true}
︠fa00fd58-47c9-4551-a1f6-1f4394f4134b︠
del person_1[0] # nem lehet a tuple elso/masodik felet kitorolni onmagaban
︡a6a0cfdb-e211-4557-ac62-1fc213cad25c︡{"stderr":"Error in lines 1-1\nTraceback (most recent call last):\n  File \"/cocalc/lib/python2.7/site-packages/smc_sagews/sage_server.py\", line 1234, in execute\n    flags=compile_flags), namespace, locals)\n  File \"\", line 1, in <module>\nTypeError: 'tuple' object doesn't support item deletion\n"}︡{"done":true}
︠8e7a40b5-464d-44af-8f92-324b1023f1d5︠
'Tuple-konkatenacio'
user_info = ('Alice', 25)
account_info = ('alice@gmail.com', 'zyxPasswordHashxyz')
record = user_info + account_info
record
︡de17ecd9-272e-4683-9b35-a154b77ae1aa︡{"stdout":"'Tuple-konkatenacio'\n"}︡{"stdout":"('Alice', 25, 'alice@gmail.com', 'zyxPasswordHashxyz')\n"}︡{"done":true}
︠bc1ed16b-82a7-41ab-946e-a835d69e5a31︠
record += ('6 days ago',)
record
︡39144812-db84-4aef-8cbe-cde652d8c45a︡{"stdout":"('Alice', 25, 'alice@gmail.com', 'zyxPasswordHashxyz', '6 days ago')\n"}︡{"done":true}
︠78908c03-c09c-40f0-86b4-02a539e43de6︠
record += ('6 days ago')
record
︡2b71184e-c14e-4b6e-86d5-df447b11c721︡{"stderr":"Error in lines 1-1\nTraceback (most recent call last):\n  File \"/cocalc/lib/python2.7/site-packages/smc_sagews/sage_server.py\", line 1234, in execute\n    flags=compile_flags), namespace, locals)\n  File \"\", line 1, in <module>\nTypeError: can only concatenate tuple (not \"str\") to tuple\n"}︡{"done":true}
︠b0959a17-daaf-4ea5-8ecc-b64789a76ccc︠
'Szakasz feletti ciklizalas'
names = ['Alice', 'Bob', 'Carol']
for idx in range(len(names)): # nem kell feltetlen elore definialni azt a valtozot, amivel iteralunk
    print(names[idx])
︡a58ce2de-3b0b-4a27-a73e-0b65aee6029e︡{"stdout":"'Szakasz feletti ciklizalas'\n"}︡{"stdout":"Alice\nBob\nCarol\n"}︡{"done":true}
︠e5ff77da-b136-4d10-b195-19e25d959ead︠
names = ['Alice', 'Bob', 'Carol']
for name in names:
    print(name)
︡bb711e4a-20e6-4a28-830b-541c618a36d0︡{"stdout":"Alice\nBob\nCarol\n"}︡{"done":true}
︠47c358ab-c316-489a-8e0b-4b3e21aab724︠
names = ['Alice', 'Bob', 'Carol']
for idx, name in enumerate(names):
    print(idx, name)
︡570b0985-5be7-4c91-9add-02019bbe9137︡{"stdout":"(0, 'Alice')\n(1, 'Bob')\n(2, 'Carol')\n"}︡{"done":true}
︠e9c0cbda-3ca6-4527-a21d-92441435865c︠
'List or tuple?'
'In addition to mutability, there is a "cultural" difference between tuples and lists. As shown in this example, lists are generally used when you have several items of the same "type", e.g. a list of names.'
'If you are getting a list of names from a database query, for example, you may not know how many names are going to be returned.'

'Tuples are used when you have multiple different pieces of information about one "thing", e.g. his name and age. '
'The cultural difference follows from the immutability of the tuple -- in the above tuple example, the 1th element is always the age, since we know there will not be an extra element inserted between the name and age. '
'Thus a tuple is more like a single database row, with each value corresponding to a column.'

'When you are the one typing in the values, it usually does not matter much which one you use.'
︡6e48cc2d-f277-4b78-8189-8486a32305c5︡{"stdout":"'Lista vagy tuple?'\n"}︡{"stdout":"'In addition to mutability, there is a \"cultural\" difference between tuples and lists. As shown in this example, lists are generally used when you have several items of the same \"type\", e.g. a list of names.'\n"}︡{"stdout":"'If you are getting a list of names from a database query, for example, you may not know how many names are going to be returned.'\n"}︡{"stdout":"'Tuples are used when you have multiple different pieces of information about one \"thing\", e.g. his name and age. '\n"}︡{"stdout":"'The cultural difference follows from the immutability of the tuple -- in the above tuple example, the 1th element is always the age, since we know there will not be an extra element inserted between the name and age. '\n"}︡{"stdout":"'Thus a tuple is more like a single database row, with each value corresponding to a column.'\n"}︡{"stdout":"'When you are the one typing in the values, it usually does not matter much which one you use.'\n"}︡{"done":true}
︠d50c8aa7-c739-4e5a-8887-0960fbaba4f6︠
'Szeleteles'
components = ['python', 'javascript', 'html', 'css']

print(components[1:3]) # a range(1,3)-beli indexekhez tartozo elemeket adja vissza, pl. [1, 2]
print(components[:2])  # visszaadja az elso indextol a megadott indexig az elemeket, 0-tol szamolva
print(components[2:])  # visszaadja az utolso indextol a megadott indexig az elemeket, 0-s indexre vegzodve
︡a586a5b9-65be-4c96-a147-92b627c2166e︡{"stdout":"'Szeleteles'\n"}︡{"stdout":"['javascript', 'html']\n"}︡{"stdout":"['python', 'javascript']\n"}︡{"stdout":"['html', 'css']\n"}︡{"done":true}
︠f2aff309-c275-4016-9340-cd903ad8b188︠
print(components[-1])
print(components[-3:-1])
print(components[:-2])
print(components[-2:])
︡ff47f0c6-954d-4d46-b9d6-325b647ea7f1︡{"stdout":"css\n"}︡{"stdout":"['javascript', 'html']\n"}︡{"stdout":"['python', 'javascript']\n"}︡{"stdout":"['html', 'css']\n"}︡{"done":true}
︠40b1bb9d-fdc9-40ac-983b-dd6b7ccc4e69︠
print(components[1::2])
print(components[::-1])
︡af92fb65-a333-44f1-8235-eccf788aece3︡{"stdout":"['javascript', 'css']\n"}︡{"stdout":"['css', 'html', 'javascript', 'python']\n"}︡{"done":true}
︠454f8c49-78ec-4f49-80d1-4f34c34f04ae︠
'Tagsag/Jelenlet'
'css' in components
components.index('css')
'java' in components

components.index('java')
︡89dbc451-8710-4fb7-a8fb-82a30dd66414︡{"stdout":"'Tagsag/Jelenlet'\n"}︡{"stdout":"True\n"}︡{"stdout":"3\n"}︡{"stdout":"False\n"}︡{"stderr":"Error in lines 5-5\nTraceback (most recent call last):\n  File \"/cocalc/lib/python2.7/site-packages/smc_sagews/sage_server.py\", line 1234, in execute\n    flags=compile_flags), namespace, locals)\n  File \"\", line 1, in <module>\nValueError: 'java' is not in list\n"}︡{"done":true}









