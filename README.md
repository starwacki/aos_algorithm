# aos_algorithm
Przechodzi wszystkie testy dla każdego algorytmu na 100% ( włącznie z optymalizacją) !

Zadanie 1
Banany
Punkty: 20
Limit czasu: 0.1-5s
Limit pamięci: 256MB
Jesteś małpą i zgłodniałeś/aś. Z głodu już nawet nie rozpoznajesz drzew. Od śmierci głodowej może
wybawić Cię tylko dobry algorytm bananowy. Napisz program, który rozpozna drzewo bananowe
wśród drzew. Jeśli drzewo jest bananowe, program powinien wyświetlić liczbę bananów
zdefiniowaną jako liczbę liści w drzewie, tj. liczbę wierzchołków o stopniu 1, w przeciwnym
przypadku 0. Drzewo bananowe Bn,k zdefiniowane jest jako n gwiazd na k wierzchołkach (n>0,
k>0), których wierzchołki o najwyższym stopniu połączone są z jednym dodatkowym
wierzchołkiem r.

Wejście
W pierwszej linii liczba kolejnych linii. W kolejnych liniach. Liczba wierzchołków grafu, a
następnie po spacji macierz sąsiedztwa wejściowego drzewa (wypisana od lewej do prawej z góry
na dół bez spacji).

Wyjście
W kolejnych liniach. Liczba bananów w drzewie bananowym lub 0 jeśli drzewo nie jest bananowe.
Przykład

Wejście
3
5 0010000110110000100100010
6 010010100000000111001000101000001000
7 0100000100001100011100010000001000001100000100000
Wyjście
2 bananas :)
0 bananas :(
4 bananas :)

Zadanie 2
Sekta
Znaleźliście się w nieodpowiednim miejscu i w nieodpowiednim czasie. Wśród n (np. n=20) 
osób (numerujemy od 1) wszyscy oprócz Ciebie chcą popełnić samobójstwo (niestety nie masz czasu na agitację). 
Guru wymyślił(a) następującą metodę: ustawiacie się w kółku i co 2-ga osoba zostaje 
zamordowana (nie pierwsza, a druga, nie trzecia, a czwarta, nie piąta, a szósta, itd.). 
W którym miejscu staniesz (wybieraj od 1 do 20)? Czas start masz 10 sekund. 
Który z kolei zginiesz? Kto jest następny? Kto zginie jako k-ty?
Niech n=10. Wówczas porządek jest następujący 2,4,6,8,10,3,7,1,9.
Przetrwała 5-tka. Jest to równoważne z n=10 i k=10. Niech n=10 i k=6. 
Wówczas jako szósta zginie osoba na miejscu 3. 
Przyjmujemy oznaczenia -1, -2, -3 itd. - oznaczają ostatnią osobę, 
przedostatnią osobę itd. Wówczas
n=11 i k=11 daje ten sam wynik co n=11 i k=-1,
n=7 i k=5 daje ten sam wynik co n=7 i k=-3.

Wejście
W pierwszej linii liczba kolejnych linii.
W następnych liniach po spacjach n i k.

Wyjście
W kolejnych liniach, miejsce w kręgu.


Przykłady
Wejście
10
4 4
5 -2
13 -6
16 -16
16 -13
7 -5
4 2
10 10
8 -1
3 -3

Wyjście
1
5
5
2
8
6
4
5
1
2

Zadanie 3
Paczki
Twoim zadaniem jest zapakowanie samochodu przedmiotami. Masz do wyboru n przedmiotów
Za przewóz i-tego przedmiotu możesz uzyskać Pi złotych (i=1,2,..,n).
Waga i-tego przedmiotu wynosi Wi (i=1,2,..,n).
Masa towaru w samochodzie nie może przekroczyć wartości C.
Upakuj samochód optymalnie, tj. tak by suma wag nie przekroczyła C oraz suma złotych była największa.
Możesz nie przyjąć zlecenia jeśli narazi Cię to na koszty. Niestety Pan, który przenosi przedmioty do samochodu pobiera stałą opłatę 20 zł za samochód.
Dodatkowo, koszt przeniesienia każdego załadowanego przedmiotu o wadze większej niż 100 kg wynosi 5 zł.

Dodatkowe informacje
Maksymalna ilość przedmiotów: 15.
Minimalny element w P i W: 0
Maksymalny element w P i W: 1000
Liczba testów (liczba uruchomień twojego programu): 10.
Wejście
W pierwszej linii liczba zapytań (samochodów do zapakowania) w danym teście.
W kolejnych liniach.
Ilość przedmiotów n.
Wypłaty za przedmioty Pi.
Wagi przedmiotów Wi.
Ładowność wozu C.
Wyjście
W kolejnych liniach.
Optymalny profit.
Przykład
Wejście
2
5
588 40 307 367 206
211 30 974 943 622
1766
1
596
997
550

Wyjście
965
0
Opis przykładu
W powyższym przykładzie: Liczba zapytań (samochodów do zapakowania) jest równa 2.
W pierwszym zapytaniu.
Ilość przedmiotów n=5.
Wypłaty za przedmioty Pi to 588 40 307 367 206 zł.
Wagi przedmiotów Wi to 211 30 974 943 622 kg.
Ładowność wozu C=1766 kg.
W drugim zapytaniu.
Ilość przedmiotów n=1.
Wypłaty za przedmioty Pi to 596 zł.
Wagi przedmiotów Wi to 997 kg.
Ładowność wozu C=550 kg.

Zadanie 4
Przekątne
Dla danego wielościanu wypukłego P w postaci list (poprawnie uszeregowanych) wierzchołków
ścian, wyznacz liczbę cykli na 4 wierzchołkach w grafie P' utworzonym przez przekątne
przestrzenne wielościanu P (tzn. przekątne, które nie łączą wierzchołków na tej samej ścianie) ?

Podpowiedź: Maksymalnie 1000 wierzchołków.
Wejście
W pierwszej linii: liczba instancji (liczba wielościanów)
W pierwszej linii danej instancji: liczba wierzchołków n i ścian f wielościanu P
W f kolejnych liniach danej instancji: liczba wierzchołków kolejnej ściany, a następnie po spacjach
poprawnie uszeregowane jej wierzchołki
Wyjście
W kolejnych liniach rozwiązanie problemu dla danej instancji (dla danego wielościanu):
liczba cykli na 4 wierzchołkach w grafie P'.
Przykład
Wejście
3
13 9
3 0 1 2
7 0 2 3 7 5 6 4
4 0 4 8 1
7 1 8 9 11 10 3 2
3 3 10 7
5 4 6 12 9 8
5 5 7 10 11 12
3 5 12 6
3 9 12 11
8 10
4 0 1 2 4
3 0 3 6
3 0 4 3
3 0 6 1
3 1 3 5
3 1 5 2
3 1 6 7
3 1 7 3
4 2 5 3 4
3 3 7 6
12 9
3 0 1 2
6 0 2 3 6 5 4
4 0 4 7 1
7 1 7 8 10 9 3 2
3 3 9 6
5 4 5 11 8 7
4 5 6 9 10
3 5 10 11
3 8 11 10

Wyjście
6
3
2
