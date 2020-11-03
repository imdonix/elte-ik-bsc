︠311497c4-3c56-41df-9227-5bea6e10a924︠
#1 - 1

testresults = {
    'Tibi': 4,
    'Istan': 3,
    'Csenge': 2,
    'Gábor': 1
}

testresults_update ={
    'Gábor': 5
}

testresults.update(testresults_update)

testresults['Károly'] = 3

testresults

︡a0530dd0-51f3-4492-adc6-b1d6d2a7407e︡{"stdout":"{'Tibi': 4, 'Istan': 3, 'Csenge': 2, 'Gábor': 5, 'Károly': 3}\n"}︡{"done":true}
︠667d028e-5723-4731-be7d-2aa96b957116︠
#1 - 2

factor(65445634324)
︡e8b53672-bcb7-469c-be15-8c2d60f71c81︡{"stdout":"2^2 * 7 * 103 * 2161 * 10501\n"}︡{"done":true}
︠19b65497-871a-48ca-b3f0-67a1e024b465︠

#1 - 3

var('a')
var('b')

factor((a^2) + (2*a*b) + (b^2))
︡d199f372-917e-44af-864c-94ae98f8ede6︡{"stdout":"a\n"}︡{"stdout":"b\n"}︡{"stdout":"(a + b)^2\n"}︡{"done":true}
︠25c9ebee-dc13-4974-8a97-f54fc9e3473a︠
#2 - 1

def primeofn(N):
    i = 2
    count = 0
    while count != N:
        if isprime(i):
            count +=1
        i +=1
    return i-1


def isprime(N):
    for x in range(2, N):
        if  N  % x == 0:
            return false
    return true

primeofn(4)
︡4d219476-c045-4617-a28b-8bf3b50e8cd8︡{"stdout":"7\n"}︡{"done":true}
︠f631d1d5-c7e3-4871-bee4-5eae7f587282︠

#2 - 2

def func(N):
    resoult = set([])
    if(N == 3 or N == 5):
        return resoult
    i = 0
    while len(resoult) != N:
        if((i % 3 == 0 or i % 5 == 0) and (i % 15 != 0)):
            resoult.add(i)
        i += 1
    return resoult

func(9)
︡9bebcc72-21ac-4070-8a55-22d0ad562021︡{"stdout":"{3, 5, 6, 9, 10, 12, 18, 20, 21}\n"}︡{"done":true}
︠ebec0d68-8f15-45b3-b681-13220786c7f5︠

#3 - 1

d = {1: [0, 1, 2, 5], 5: [2, 3], 2: [3, 0]}
G = Graph(d)
G.hamiltonian_path()
︡21792d1a-98dd-4bcf-9084-cbf7a84ade8d︡{"stdout":"Hamiltonian path from : Graph on 5 vertices\n"}︡{"done":true}
︠42b72b1d-689e-46a6-9c7d-6fd39cf00281︠
#3 - 2

G2 = DiGraph([[1, 2, 3], [(1,1), (1,2), (1,3), (2,2), (2,3), (3,1)]], loops = True)
path = G2.all_paths(1,3)
︡84d9a83a-4cdb-424e-b61f-f15a2f126291︡
︠b50f82af-5726-4b03-98a6-f0006b373973︠
path
︡25157c97-ea02-4e83-a940-4b795b0096f2︡{"stdout":"[[1, 2, 3], [1, 3]]\n"}︡{"done":true}
︠a002a34d-70b4-48f6-86bd-aa12b55c48e8︠

#3 - 3

#Sage-ben írja ki a képernyőre hogy a (1, 2), (4, 1), (2, 3), (2, 5),
#(7, 9), (8, 1), (6, 8), (8, 6), (3, 6) #párokkal meghatározott irányított
#gráfban melyik a maximális hosszúságú út a 4-es csúcsból a 6-os csúcsba,
#amelyik tartalmazza a 3-as csúcsot!
G = DiGraph([[1,2,3,4,5,6,7,8,9], [(1, 2), (4, 1), (2, 3), (2, 5), (7, 9),
(8, 1), (6, 8), (8, 6), (3, 6)]], loops=True)
G.show()
paths = G.all_paths(4, 6) # fordítva
paths
max_path = []
for p in paths:
    if 3 in p and len(p) < len(max_path):
        max_path = p
max_path
︡427745f8-8745-46a6-9293-5ba77342e288︡{"file":{"filename":"/home/user/.sage/temp/project-15e5591c-d6f7-4a5f-aa23-58570ec7d4b5/708/tmp_pig6xxym.svg","show":true,"text":null,"uuid":"6723afcb-7a0a-4f6b-b76a-83d38bd38ada"},"once":false}︡{"stdout":"[[4, 1, 2, 3, 6]]\n"}︡{"stdout":"[]\n"}︡{"done":true}
︠1ce175aa-e340-4885-9461-4cb9480e864c︠

#4 - 1

def IsAntisimmetric(A, R):
    for a in A:
        for b in A:
            if [a,b] in R and [b,a] in R and a != b:
                return False
    return True

IsAntisimmetric({1, 2, 3, 4}, [[1, 1], [2, 3], [3, 4], [4, 4]])
︡e7e9d1be-447d-459e-b932-581d8428887d︡{"stdout":"True\n"}︡{"done":true}
︠92c89085-d099-4019-bea2-d2f737bd69bds︠

#4 - 2

def IsItCovered(R, A):
    res = set(A)
    for x in R:
        if(x[0] in res):
            res.remove(x[0])
    return (len(res) <= 0, res)
    return res

IsItCovered([[1,2], [3,5], [5,0]], [1,2,3])
IsItCovered([[1,2], [3,5], [5,0]], [1,3])
︡6396a42d-cde1-4d53-aec1-cb60d3599b49︡{"stdout":"(False, {2})\n"}︡{"stdout":"(True, set())\n"}︡{"done":true}
︠ce9420f8-e40e-4f71-a7c4-1d52c6a626e0s︠

#5

def primelenn(O):
    res = set([])
    i = 2
    while len(res) < 2*O:
        if(isprime(i)):
            res.add(i)
        i +=1
    return res

def primeofn(N):
    i = 2
    count = 0
    while count != N:
        if isprime(i):
            count +=1
        i +=1
    return i-1

def isprime(N):
    for x in range(2, N):
        if  N  % x == 0:
            return false
    return true

def isoszettet(N):
    for x in range(2, N):
        if  N % x == 0:
            return true
    return false

N = int(raw_input("Enter a number"))
O = N

if isprime(N):
    N += 1;
    c = 0
    x = 0
    while c < 2:
        if isprime(N):
            c += 1
            x += N
        N +=1
else:
    x = factorial(N)

print(x)

if isoszettet(x):
    print('x egy öszette szám')
else:
    print('x nem öszette szám')

print(primelenn(O))
︡b30912bc-d867-4cea-b371-c77a58e05c8e︡{"raw_input":{"prompt":"Enter a number"}}︡{"delete_last":true}︡{"raw_input":{"prompt":"Enter a number","submitted":true,"value":"5"}}︡{"stdout":"18\n"}︡{"stdout":"x egy öszette szám\n"}︡{"stdout":"{2, 3, 5, 7, 11, 13, 17, 19, 23, 29}\n"}︡{"done":true}
︠45dd6676-9797-420c-858f-683782e7e4d5︠









