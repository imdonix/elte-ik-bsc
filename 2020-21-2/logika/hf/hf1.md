## Feladat

Formalizáljuk a következő állításokat! Ehhez az ítéletváltozók jelentéseit is adjuk meg! Mivel a mondatok összefüggnek, így ügyeljünk arra, hogy az azonos állításokat azonos ítéletváltozóval jelöljük!

A formalizálás után, közös igazságtábla segítéségével vizsgáljuk meg, hogy az első három formulának szemantikus következménye-e a 4. formula? teljesül-e?

- F1. Vettem egy új könyvet és végig is olvastam.

- F2. Ha bölcsebb lettem, akkor biztosan végigolvastam a könyvet.

- F3. Ha vettem egy új könyvet, de nem olvastam végig, akkor nem lettem bölcsebb.

----

- G. Ha bölcsebb lettem, akkor biztosan vettem egy új könyvet, amelyet végig is olvastam.

# Megoldás

- `A` - Vettem egy új könyvet
- `B` - Végig olvastam a könyvet
- `C` - Bölcsebb lettem

---

- F1 = `A ∧ B`
- F2 = `C → B`
- F3 = `(A ∧ ¬B) → ¬C`

- G = `C → (A ∧ B)`

| A | B | C | A ∧ B  | C → B  | (A ∧ ¬B) → ¬C   | C → (A ∧ B)   |
|---|---|---|--------|--------|-----------------|---------------|
| I | I | I | **I**  | **I**  | **I**           | **I**         |
| I | I | H | I      | I      | I               | I             |
| I | H | I | H      | H      | H               | H             |
| I | H | H | H      | I      | I               | I             |
| H | I | I | H      | I      | I               | H             |
| H | I | H | H      | I      | I               | I             |
| H | H | I | H      | H      | I               | H             |
| H | H | H | H      | I      | I               | I             |

Az igazság tábla első sorára teljesül a szemantikus következmény.