Készíts programot, ami leszimulálja az erőforrások lefoglalását és felszabadítását a JSON fájlban megadott topológia, kapacitások és igények alapján! Teszteléshez használható a mellékelt: cs1.json

Script paraméterezése: python3 client.py cs.json

A program kimenete:

`esemény sorszám. < esemény név >: < node1 > <-> < node2 > st:< szimuálciós idő > [- < sikeres/sikertelen >]`

Pl.
1. igény foglalás: A<->C st:1 – sikeres
2. igény foglalás: B<->C st:2 – sikeres
3. igény felszabadítás: A<->C st:5
4. igény foglalás: D<->C st:6 – sikeres
5. igény foglalás: A<->C st:7 – sikertelen …