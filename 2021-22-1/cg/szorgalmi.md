Teames zip-elve kell beküldeni

# 1 SDL-Eseménykezelés
- Egérmutató körül keringjen egy kör (200 szakasz) (50 sugár) (100 keringés sugara) (5 másodpercenként)
- Q - keringés sugár csökken
- E - keringés sugár növekszik
- SPACE - megfordul a keringés + új színt (véletlen)
- Ha a kör az ablak széléhez érne (ehhez most elég egy négyzetként gondolnunk rá, átmérőnyi oldalhosszal), akkor ugyanúgy megfordul a keringés iránya és új színt kap.
- Határidő = 10.18 20:00

# 2 Transzformáció

- 3 gúla, (x,z) síkon, köztük 2 egység
- Kamera WASD mozgás, QE fel-le
- gúlák mozogjonak, 5s fel-le 3-3 egységnyit 

# 3 Földgömb

- Induljunk ki a 01_Normals gyakorlat anyagából (Teamsben feltöltve)
- Törlési szín (háttér színe): [0.05, 0.05, 0.05]	
- Adott két textúra (earthmap1k.jpg és earthspec1k.jpg a gyakorlati anyagok között Teamsben)
	
- Legyen forgó irányfényforrásunk: XZ síkban kört ír le a fénysugarak iránya, Y = 0, egy kör 20 mp.
- Fény színe: La, Ld és Ls is [1.0, 1.0, 0.85]
- Anyagszínek: Ka = [0.1, 0.1, 0.1], Kd = [1.0, 1.0, 1.0], Ks = [2.0, 2.0, 2.0]	
- Spekuláris visszaverődés: ahol a spekuláris textúra 0 ott nincs spekuláris visszaverődés, ellenkező esetben 32-t használjunk kitevőnek a spekuláris képletben.