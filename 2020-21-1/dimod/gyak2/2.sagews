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

age_data['Jerry']
︡0401a79b-ca2b-441b-bb52-194bbbab1335︡{"stdout":"'Forras: https://share.cocalc.com/share/d8089187e18cbe1c1f7d4b3a12ffb5a2106abfbf/tutorials/Basics/Basics.ipynb?viewer=share'\n"}︡{"stdout":"'5. szakasz'\n"}︡{"stdout":"'Szotar'\n"}︡{"stdout":"23\n"}︡{"stdout":"True\n"}︡{"stdout":"False\n"}︡{"stdout":"23\n"}︡{"done":true}
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

friends['Martha'].append('Daniel')
print( friends['Martha'] )
︡0586b16a-8aad-40ae-8dc9-7e11acb73d12︡{"stdout":"['Bob', 'Carol', 'Daniel']\n"}︡{"done":true}
︠dfc26680-325e-40bb-892d-1471d8a36171︠
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









