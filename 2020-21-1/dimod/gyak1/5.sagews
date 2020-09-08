︠d184a881-975e-4759-8274-d8f33e8847e9s︠
# Első gyakorlat: Ismerkedés a felülettel

# SHIFT + ENTER/ RUN gomb : program futtatása
# DELETE : program bezárása

'Forras: https://share.cocalc.com/share/d8089187e18cbe1c1f7d4b3a12ffb5a2106abfbf/tutorials/Basics/Basics.ipynb?viewer=share'
'5. szakasz'
'Szotar'
age_data = {'Jerry' : 23, 'Martha' : 21}

age_data['Jerry']  # extract Jerry's age

'Jerry' in age_data

'Mickey' in age_data

age_data['Mickey']
︡dd72618b-9e30-49e1-914e-d450c4abfd40︡{"stdout":"'5. szakasz'\n"}︡{"stdout":"'Szotar'\n"}︡{"stdout":"23\n"}︡{"stdout":"True\n"}︡{"stdout":"False\n"}︡{"stderr":"Error in lines 7-7\nTraceback (most recent call last):\n  File \"/cocalc/lib/python2.7/site-packages/smc_sagews/sage_server.py\", line 1234, in execute\n    flags=compile_flags), namespace, locals)\n  File \"\", line 1, in <module>\nKeyError: 'Mickey'\n"}︡{"done":true}
︠1e4841dc-8d3b-40a1-90d3-2fc7d09a1bdcs︠
list(age_data)
list(age_data.keys())
list(age_data.values())
︡a0bbd1a7-619a-41e1-a094-063dcfce3e59︡{"stdout":"['Martha', 'Jerry']\n"}︡{"stdout":"['Martha', 'Jerry']\n"}︡{"stdout":"[21, 23]\n"}︡{"done":true}
︠20a5b47f-03a1-4f85-8e91-5cb2db873e0es︠
for name in age_data:
    years = age_data[name]
    msg = '{} is {} years old'.format(name, years)
    print(msg)

list(age_data.items())
for name, years in age_data.items():
    msg = '{} is {} years old'.format(name, years)
    print(msg)
︡cbe00ef6-edb7-488e-bc64-63588d378dd4︡{"stdout":"Martha is 21 years old\nJerry is 23 years old\n"}︡{"stdout":"[('Martha', 21), ('Jerry', 23)]\n"}︡{"stdout":"Martha is 21 years old\nJerry is 23 years old\n"}︡{"done":true}
︠9170b89c-0b56-4869-ad38-0e24c0fcb6a9s︠
friends = {
    'Jerry': [
        'Alice',
        'Bob',
    ],
    'Martha': [
        'Bob',
        'Carol',
    ],
}

print( friends['Martha'] )
print( friends['Martha'][1] )
︡6c30abb9-e340-4136-b70c-5f5f62542999︡{"stdout":"['Bob', 'Carol']\n"}︡{"stdout":"Carol\n"}︡{"done":true}
︠a8e6461d-4f64-4deb-9b62-634dc197591es︠
friends['Martha'].append('Daniel')
print( friends['Martha'] )
︡8a718bb9-68a7-42d0-8c1d-b3b7f6b8c496︡{"stderr":"Error in lines 1-1\nTraceback (most recent call last):\n  File \"/cocalc/lib/python2.7/site-packages/smc_sagews/sage_server.py\", line 1234, in execute\n    flags=compile_flags), namespace, locals)\n  File \"\", line 1, in <module>\nNameError: name 'friends' is not defined\n"}︡{"done":true}︡
︠dfc26680-325e-40bb-892d-1471d8a36171︠
'Fajlbemenet es fajlkimenet'
with open('nato.txt') as f:
    text = f.read()
    lines = text.split('\n')
lines[:5]
lines[-1]
︡80c81dac-3ca4-45ca-b4bd-235641b8351d︡{"stdout":"'Fajlbemenet es fajlkimenet'\n"}︡{"stderr":"Error in lines 2-4\nTraceback (most recent call last):\n  File \"/cocalc/lib/python2.7/site-packages/smc_sagews/sage_server.py\", line 1234, in execute\n    flags=compile_flags), namespace, locals)\n  File \"\", line 1, in <module>\nIOError: [Errno 2] No such file or directory: 'nato.txt'\n"}︡{"done":true}
︠b3576857-5ff5-41c1-aabb-f10ba3124462︠
exam_scores = {
    'Alice': 88,
    'Bob': 89,
}
exam_retake_scores = {
    'Bob': 90,
    'Carol': 95
}

exam_scores.update(exam_retake_scores) # frissites
exam_scores
︡4ffe7b12-7cd9-4415-b762-311e35119563︡{"stdout":"{'Bob': 90, 'Alice': 88, 'Carol': 95}\n"}︡{"done":true}
︠d365c704-5d8b-4c2f-a9c5-a9318eb99fce︠









