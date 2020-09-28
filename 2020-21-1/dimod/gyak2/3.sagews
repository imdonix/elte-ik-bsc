︠84e2b833-ab53-4891-93e3-81d183c93573︠
'1. feladat: Szamitsuk ki az 555-faktorialist!'
# factorial(555)
︡5c5f225f-29c5-4e49-9ecc-efe19fd96c9b︡{"stdout":"'1. feladat: Szamitsuk ki az 1000-faktorialist!'\n"}︡{"done":true}
︠7358010c-19b6-4185-9197-d68adf740f94︠
'2. feladat: Irassuk ki a PI szam erteket 234 tizedesjegy pontosaggal!'
# reset('n')
# n(pi, 234)
︡6f2d5626-36bc-4e8d-aa03-0c6da53c666e︡{"stdout":"'2. feladat: Irassuk ki a PI szam erteket 857 tizedesjegy pontosaggal!'\n"}︡{"done":true}
︠f94ab74e-7240-4ace-bacb-516ffa1ec573︠
'3. feladat:  Adjuk meg a (3+9i)(3-8i) eredmenyet!'
# (3+9i)*(3-8i)
︡e8fba26e-8fa4-4e5c-bae6-4902cf80dba7︡{"stdout":"'3. feladat:  Adjuk meg a (3+2i)(5-3i) eredmenyet!'\n"}︡{"done":true}
︠61164ca9-68ee-4390-9f32-f01917f1b9d4︠
'4. feladat:  Keressunk egy olyan szamot, aminek szinusza sqrt(2)/2!'
# arcsin(sqrt(2)/2)
︡5a6e7b04-8e42-4874-a0ac-8c9d36e66856︡{"stdout":"'4. feladat:  Keressunk egy olyan szamot, aminek szinusza 1/2!'\n"}︡{"done":true}
︠bb6d7445-dae3-4f5f-8a4b-5adeeff9d02cs︠
'5. feladat: Irjuk fel a 5342634632512543646623001324 szam primfelbontasat!'
# factor(5342634632512543646623001324)
︡d879fe28-bbb7-40dd-8b72-f1c40dc2edd2︡{"stdout":"'5. feladat: Irjuk fel a 5342634632512543646623001324 szam primfelbontasat!'\n"}︡{"done":true}
︠cd23a5fe-f24e-49b8-bcae-75056f4e879c︠
'6. feladat: Szamitsuk ki pi-ben a tizedespont utani 2008. es 2017. jegy kozotti szamjegyek altal meghatarozott 10 jegyu szamot!'
# ötlet a 7-10. számjegyekre: Mod(floor(pi*10^10),10000) vagy floor(n(pi, digits=12) * 10^10) % 10^4
# floor(n(pi, digits=2018) * 10^2017) % 10^10 # első helyi értéken 0 van
︡d650dcbb-b4de-4a05-97e2-53bd67ecaf5e︡{"stdout":"'6. feladat: Szamitsuk ki pi-ben a tizedespont utani 2008. es 2017. jegy kozotti szamjegyek altal meghatarozott 10 jegyu szamot!'\n"}︡{"done":true}
︠375e649c-4225-4037-a661-05b624ae794cs︠
'7. feladat: Bonstuk fel a zarojeleket a ((x+y+12)^2 + (x+y-11)^3)^10 kifejezesben!'
# var('x')
# var('y')
# expand(((x+y+12)^2 + (x+y-11)^3)^10)
︡9e5b85db-01e0-46b8-adfc-c35f024cd77b︡{"stdout":"'7. feladat: Bonstuk fel a zarojeleket a ((x+y+12)^2 + (x+y-11)^3)^10 kifejezesben!'\n"}︡{"done":true}
︠86f0cc7b-0977-46ce-af49-41940c11149as︠
'8. feladat: Alakitsuk szorzatta a a^3b+b^3c+c^3a-ab^3-bc^3-ca^3 kifejezest!'
# var('a')
# var('b')
# var('c')
# factor(a^3*b+b^3*c+c^3*a-a*b^3-b*c^3-c*a^3)
︡c435f610-fb61-4954-8539-a56b9f2073ec︡{"stdout":"'8. feladat: Alakitsuk szorzatta a a^3b+b^3c+c^3a-ab^3-bc^3-ca^3 kifejezest!'\n"}︡{"done":true}
︠60b2a828-9829-499f-8545-6279801828eb︠
'9. feladat: Szamitsuk ki a sum(1/n^4) n=1..infinity osszeget szimbolikusan es numerikusan 20 tizedesjegyre is!'
# var('n')
# sum(1/n^4, n, 1, infinity)
︡732bbf9a-6958-4529-9706-3a825fb7de01︡{"stdout":"n\n"}︡{"stdout":"1/90*pi^4\n"}︡{"done":true}
︠20ba0da1-a6f4-4e14-b96d-be54c5cdf786︠










