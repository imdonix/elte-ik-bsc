## Igazságtábla

- F1 - lorem
- F2 - ipsum
- K - ez

1. Formalizálás
    - F1 - A v B
    - F2 - A & C
    - K - C
2. Teljes Igazságtábla
3. Indok

{F1, F2, ..., Fn} |=0 G -> 
mivel minden olyan I interpretáció, amely kielégíti az F
formulahalmazt (I |=0 {F1, F2, ...Fn}), az kielégíti a G következményformulát
(I |=0 G) is.

## Igazságértékelő fun

- Sima:
    1. Igaz/Hamis-ra kiértékelem
    2. Össze szeded egy halmazba az interpretációkat
    * Ellentmondás kijöhet
- Szematikus következmény:
    1. Átalakítás
        - {¬B,(C ∨ B) ∧ (¬D ∨ C)} |=0 C
        - ¬B ⊃ ((C ∨ B) ∧ (¬D ∨ C)) ⊃ C
    2. Tautológia vizsgálat:
        - hamishalmaz esetén - mindenhol ellentmondást kell kapni
    3. Kiértékel hamishalmazra
    4. Ha mindenhol ellentmondást kapsz akkor teljesül.

## Elsőrendű formalizálás
## Elsőrendű értéktábla