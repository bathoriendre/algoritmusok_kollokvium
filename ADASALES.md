# ADASALES – Ada és utazó értékesítő / ADASALES - Ada and Travelling Salesman

Ada, a katicabogár Bugladesben él. Ez egy nagyon sajátos ország - rengeteg város van, de mivel a kormány nem "pazarolja" a pénzt, csak egy egyszerű út van az egyes várospárok között.

Ada utazó értékesítőként dolgozik. Városok között utazik, termékeket vásárol és ad el. A terméknek minden városban fix ára van (a vétel/eladás esetében ugyanaz). Mivel Ada kerékpárral utazik (hogy elkerülje az utazások kifizetését), így egyszerre legfeljebb egy tárgyat tud vinni.

Jelenleg valamelyik városban tartózkodik, és olyan várost szeretne választani, hogy minél több pénzt keressen azzal, hogy ebbe a városba utazik (egyszerű úton). Tudsz neki segíteni?

## Bemenet

Az első sorban 0 < N ≤ 105, 0 < Q ≤ 5×105, a városok száma és a lekérdezések száma lesz.

Ezután egy sor következik N egész számmal, 1 ≤ Ai ≤ 109, az ár az i-edik városban.

Ezután N-1 sor következik, amelyek mindegyike két 0 ≤ i, j < N (i ≠ j) számot tartalmaz, ami azt jelenti, hogy i és j város között egyszerű út van.

Ezután Q sorok következnek, amelyek mindegyike pontosan egy egész számot tartalmaz 0 ≤ i < N – a város, ahol Ada kezdődik.

## Kimenet

Írjuk ki Q sorokat, a maximális pénzt, amit Ada kereshet.

## Példa bemenet

6 6
1 2 3 4 5 4
1 0
1 2
1 3
3 4
4 5
0
1
2
3
4
5

## Példa kimenet

4
3
3
1
1
2