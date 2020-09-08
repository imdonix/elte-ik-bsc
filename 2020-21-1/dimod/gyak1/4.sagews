︠d184a881-975e-4759-8274-d8f33e8847e9︠
# Első gyakorlat: Ismerkedés a felülettel

# SHIFT + ENTER/ RUN gomb : program futtatása
# DELETE : program bezárása

'Forras: https://share.cocalc.com/share/d8089187e18cbe1c1f7d4b3a12ffb5a2106abfbf/tutorials/Basics/Basics.ipynb?viewer=share'
'4. szakasz'
'String'
name = "John Jacob Jingleheimer"
'J' in name # valid logikai kerdes
'z' in name
'John' in name
name.index('Jacob')
name[5:10]
name[:6]
name[::-1]

print(name.lower())
print(name.upper())
print('four score and seven years ago'.title())

name = "John Jacob Jingleheimer"
name = name + ' Schmidt'
name

name += ' Jr'
name
︡40552e84-8d3e-4819-b0c4-007227809721︡{"stdout":"'4. szakasz'\n"}︡{"stdout":"'String'\n"}︡{"stdout":"True\n"}︡{"stdout":"False\n"}︡{"stdout":"True\n"}︡{"stdout":"5\n"}︡{"stdout":"'Jacob'\n"}︡{"stdout":"'John J'\n"}︡{"stdout":"'remiehelgniJ bocaJ nhoJ'\n"}︡{"stdout":"john jacob jingleheimer\n"}︡{"stdout":"JOHN JACOB JINGLEHEIMER\n"}︡{"stdout":"Four Score And Seven Years Ago\n"}︡{"stdout":"'John Jacob Jingleheimer Schmidt'\n"}︡{"stdout":"'John Jacob Jingleheimer Schmidt Jr'\n"}︡{"done":true}
︠bef15bc0-6816-4334-ba9b-54947577bbbds︠
print( '{}! His name is my name too!'.format(name) )
︡b6714452-fe95-4948-bf33-f3be6ae23145︡{"stdout":"John Jacob Jingleheimer Schmidt Jr! His name is my name too!\n"}︡{"done":true}
︠7d53950f-59b0-48ae-9460-8150a9e53963︠
person = ('Rob', 21)

# Az argumentumok implicit elhelyezese
print( '{} is {} years old'.format(person[0], person[1]) )

# Az argumentumok explicit elhelyezese
print( '{1} years ago, {0} was born. Yes {1} years old!'.format(person[0], person[1]) )

# Nevesitett argumentumok
print( '{age} years ago, {name} was born. Yes {age} years old!'.format(name=person[0], age=person[1]) )
︡eb3456bd-a8b4-4c83-b56d-521d7c32df1e︡{"stdout":"Rob is 21 years old\n"}︡{"stdout":"21 years ago, Rob was born. Yes 21 years old!\n"}︡{"stdout":"21 years ago, Rob was born. Yes 21 years old!\n"}︡{"done":true}
︠ab62e525-7e3b-4a5f-9de5-f10afb967f3b︠
german = 'Floß'
swiss = german.replace('ß', 'ss') # lecsereles
print('{} -> {}'.format(german, swiss))
︡6962147a-e0fd-4817-8c7c-7b2e67f2a478︡{"stdout":"Floß -> Floss\n"}︡{"done":true}
︠8b27a784-cf66-4d0f-b164-89f0b2867020s︠
sentence = 'I sure do love Python string manipulation'
sentence.replace(' ', '')
︡0b91fd11-9c10-41a6-965b-2a3fd4a4af3e︡{"stdout":"'IsuredolovePythonstringmanipulation'\n"}︡{"done":true}
︠0e84725e-595c-408d-bb7a-48421a1c5807︠
sentence = 'I sure do love Python string manipulation'
words = sentence.split(' ') # szetvagas
words
︡cca3a75c-2361-4579-8ce2-469872b36c7e︡{"stdout":"['I', 'sure', 'do', 'love', 'Python', 'string', 'manipulation']\n"}︡{"done":true}
︠67553f2f-6648-4ce0-bf18-7f14d45275bes︠
' '.join(words)
︡6850ac5d-7dc1-4107-a3cd-01f6f2c33e41︡{"stdout":"'I sure do love Python string manipulation'\n"}︡{"done":true}
︠2a3126f0-5caf-41cf-a789-21fd9e806b0cs︠
', '.join(words)
︡ccc1c1b1-e2a8-4ec0-8d7d-ac822e6c1ef1︡{"stdout":"'I, sure, do, love, Python, string, manipulation'\n"}︡{"done":true}
︠11831f0e-d08d-4f22-bfd9-45179f52cbfbs︠









