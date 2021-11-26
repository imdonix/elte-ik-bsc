## 1 alfeladat
Konfigurálja fel az r6-r8 routerek interfészeit a következő módon:
- r6-s4 irányába: 32.0.0.254/8 legyen. r6-h5 irányába: 42.0.0.254/8 legyen. r6-r8 irányába: 192.168.114.1/24 legyen.
- r7-s5 irányába: 32.0.0.253/8 legyen. r7-h6 irányába: 52.0.0.254/8 legyen. r7-r8 irányába: 192.168.110.1/24 legyen.
- r8-r6 irányába: 192.168.114.2/24 legyen. r8-r7 irányába: 192.168.110.2/24 legyen. r8-h4 irányába: 62.0.0.254/8 legyen.

## 2 alfeladat
Állítsa be a routing táblákat úgy, hogy bármely hosztról bármely másik hoszt elérhető legyen. Mininet terminálban a pingall parancs ad lehetőséget az elérhetőségek gyors tesztelésére!
1) A h1 és a h2 állomások az r6 routert használják minden kimenő forgalmuknak a továbbításához, míg a h3 az r7-es routert! Továbbá az r8-as router a 32.0.0.0/8 hálózat eléréséhez a forgalmat az r6-os router felé irányítsa! A többi állomás esetén a táblabeállítások egyértelműek, továbbá kérdéses esetben szabadon eldönthető.

## 3 alfeladat
Iptables segítségével állítson be port forwarding (DNAT) szabályt az r6 router h5 hoszt felé eső interfészén úgy, hogy a 122, 222, 322 TCP portokra érkező a forgalmat továbbítsa a h1, h2 h3 22-es TCP portjára. Továbbá a h5 hálózatából jövő és h1-h3 hálózatába menő TCP forgalmakat blokkoljuk (DROP). Adja meg a kiadott iptables parancsokat.

## A beadás formátuma
1db input.txt file legyen ami tartalmazza soronkent a kiadott parancsokat. A parancsokat úgy kell megadni, mintha a mininet console-ban adtuk volna ki. pl: 'h1 ping 10.0.0.2' , vagyis a h1 hoszton kiadott 'ping 10.0.0.2' parancs.