︠305015b1-56cf-4293-974d-94eacca0aeca︠
# Második gyakorlat: Gráfok

# Rajzolja ki a következő irányítatlan gráfot: 1: [0,1,2,5], 5: [2,3], 2: [3,0]

d = dict() # vagy d = {}

d = {1: [0, 1, 2, 5], 5: [2, 3], 2: [3, 0]}
d
G = Graph(d)
G.show()
︡11e52489-885c-48eb-98ba-4c4768b1b20a︡{"stdout":"{1: [0, 1, 2, 5], 2: [3, 0], 5: [2, 3]}\n"}︡{"file":{"filename":"/home/user/.sage/temp/project-54b4e4b7-6e81-4838-8da2-99e235a7b487/534/tmp_UkKW_5.svg","show":true,"text":null,"uuid":"8734c17e-47af-4434-ad34-3d37fe3bef56"},"once":false}︡{"done":true}
︠c7530397-e875-4c22-8cda-f42400f1df84︠
# Rajzoljuk ki azt a gráfot, amelynek csúcsai V = {1, 2, 3, 4}, az élei pedig E = {(1,1), (1,2), (1,3), (2,1), (2,2), (2,3), (3,1), (3,2), (3,4), (4,3), (4,4)} !
G = Graph({1: [1, 2, 3], 2: [1, 2, 3], 3: [1, 2, 4], 4: [3, 4]})
G.show()
︡705c2acc-b985-4d3b-8f09-9b2f6ea861e0︡{"file":{"filename":"/home/user/.sage/temp/project-54b4e4b7-6e81-4838-8da2-99e235a7b487/534/tmp_gHSdN6.svg","show":true,"text":null,"uuid":"40de72f7-62d5-4262-94b2-2ea23f351d70"},"once":false}︡{"done":true}
︠fabcc3a5-f675-4660-879d-a23d96ff1122s︠
# Szorgalmi: Rajzoljuk ki azt a gráfot, aminek a csúcsai 1 és N közötti egész számok, és élek azon csúcsok között vannak, amelyeknek összege prímszám

# Rajzoljuk ki a következő gráfot: csúcsai az {1, 2, 3, 4, 5} kételemű részei, az élek pedig azok közt a csúcsok közt mennek, melyeknek összegei relatív prímek
    {1, 2}
    set([1, 2])
    Set([1, 2])
n = 5
v = Set([Set([i, j]) for i in [1..n] for j in [1..n] if i < j])
v

d = dict()
for i in v:
    d[i] = [j for j in v if (gcd(sum(i), sum(j)) == 1) and (sum(i) % 2 == 1) and (sum(j) % 2 == 1)]

G = Graph(d)
G.show()
︡2a314aa3-d92d-4e5e-a293-fcf4407e3d26︡{"stdout":"set([1, 2])"}︡{"stdout":"\n"}︡{"stdout":"set([1, 2])\n"}︡{"stdout":"{1, 2}\n"}︡{"stdout":"{{2, 4}, {1, 2}, {1, 5}, {1, 4}, {3, 5}, {3, 4}, {2, 3}, {2, 5}, {1, 3}, {4, 5}}\n"}︡{"file":{"filename":"/home/user/.sage/temp/project-60104356-1b0b-4ce4-9e4d-4d21e2ce19f0/342/tmp_sPxtOm.svg","show":true,"text":null,"uuid":"f8afe807-ec6f-4701-98d1-1d98f554947f"},"once":false}︡{"done":true}
︠0f26b3f1-74f4-46a7-976c-5b64de2bdf1a︠
# Rajzolja ki a következő gráfot: (2,2), (1,2), (1,3), (1,3), címkézze rendre az éleket: c, a, b, d karakterekkel
G = Graph([[1, 2, 3],[(2,2,'c'), (1,2,'a'), (1,3,'b'), (1,3,'d')]], multiedges = True, loops = True)
G.show(edge_labels = True)
︡d55893aa-181e-4c73-a13a-d8b1d5b1a452︡{"file":{"filename":"/home/user/.sage/temp/project-54b4e4b7-6e81-4838-8da2-99e235a7b487/534/tmp_2WSCKO.svg","show":true,"text":null,"uuid":"d3243e60-7e09-46d3-8b63-bc78ef6f60f9"},"once":false}︡{"done":true}
︠46c50c16-2785-4bbc-8ac6-4d789a8b1210︠
# Rajzolja ki a következő irányított gráfot: (1,2), (3,1), (1,4)
G = DiGraph([[1, 2, 3, 4],[(1,2), (3,1), (1,4)]])
G.show()
︡2ba001cf-7e4b-4b07-9c94-1ce6e54d7e04︡{"file":{"filename":"/home/user/.sage/temp/project-54b4e4b7-6e81-4838-8da2-99e235a7b487/534/tmp_vfcbju.svg","show":true,"text":null,"uuid":"969e89cc-c070-4975-92f2-479e1d9b0a7d"},"once":false}︡{"done":true}
︠8aa0ad5f-67ce-4c56-b16b-0303161aca93︠
# Tekintsük az 2. feladat gráfját. Adja meg a gráf fokszámsorozatát, a 0-ból 5-be menő összes lehetséges utat
d = {1: [0, 1, 2, 5], 5: [2, 3], 2: [3, 0]}
G = Graph(d)
G.all_paths(0, 5)
# Rajzolja ki G egy Hamilton gráfját
H = G.hamiltonian_path()
H.show()
︡487b2a4a-0cfb-4dd6-8ea3-95d93dc99aa4︡{"stdout":"[[0, 1, 2, 3, 5], [0, 1, 2, 5], [0, 1, 5], [0, 2, 1, 5], [0, 2, 3, 5], [0, 2, 5]]\n"}︡{"file":{"filename":"/home/user/.sage/temp/project-54b4e4b7-6e81-4838-8da2-99e235a7b487/534/tmp_cV3ICB.svg","show":true,"text":null,"uuid":"2f1518b5-387d-439e-88fb-eb7faed1f206"},"once":false}︡{"done":true}
︠545c9592-16ec-4111-b844-8d7a9e2e7f31s︠
# Sage-ben írja ki a képernyőre hogy a (1, 2), (1, 4), (1, 9), (2, 3), (2, 5), (7, 9), (1, 8), (8, 1), (6, 8), (8, 6)
# párokkal meghatározott irányított gráfban melyik a maximális hosszúságú út a 3-as csúcsból a 9-es csúcsba, amelyik nem tartalmazza a 4-es csúcsot
G = DiGraph([[1,2,3,4,5,6,7,8,9], [(1, 2), (1, 4), (1, 9), (2, 3), (2, 5), (7, 9), (1, 8), (8, 1), (6, 8), (8, 6)]])
G.show()
paths = G.all_paths(3,9)
paths
max_path = []
for p in paths:
    if 4 not in p and len(p) > len(maximum):
        max_path = p
max_path
︡5e6a21a4-16f3-4ff8-8f85-0e3f75eadefe︡{"file":{"filename":"/home/user/.sage/temp/project-60104356-1b0b-4ce4-9e4d-4d21e2ce19f0/333/tmp_13Qruf.svg","show":true,"text":null,"uuid":"fff0813f-ba2d-4800-aa49-7a180914c4f7"},"once":false}︡{"stdout":"[]\n"}︡{"stdout":"[]\n"}︡{"done":true}
︠1ef70af0-70b5-477d-ad20-8d67262d9e63︠









