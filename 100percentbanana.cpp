#include <iostream>
#include <cstdio>
#include <regex>
using namespace std;
#include <string>
#include <list>
#include <algorithm>
#include <unordered_set>


//Metoda szybsza od cina/scanf do brania inputa dla liczb - wykorzystuje nisko poziomoa funkcje z c - getchar() (dla windows) - dla linuxa jest getchar_unlocked()
static int parseNumber(void)
{
    int c, n;
    n = getchar();
    n = n-'0';

    while (isdigit((c = getchar())))
        n = 10*n + c-'0';

      return n;
}


//Metoda bardzo szybko zlicza ilość znaków w stringu - o wiele szybciej niż ewentualne użycie regexa/pętli
int countCharacterOccurrences(const std::string& text, char character) {
    return count_if(text.begin(), text.end(), [character](char c) { return c == character; });
}


int countBananasAndGetGrandchildrenAndChildrensRows(unordered_set<int>& set,string &grandChildRows, string text, int k) {
    int banana = 0;
    int iterations = 0;

    for (int j = 0; j < static_cast<int>(text.length()); ){
      string fragment = text.substr(j, k);

      if (countCharacterOccurrences(fragment,'1') == 1) {
       int index = fragment.find_first_of('1')+1;
       set.insert(index);
       grandChildRows.append(to_string(iterations+1));
       banana++;
    }

      j = j+k;
      iterations++;   
    }

    return banana;
}


//W przypadku gdy mamy k-1 połączeń to mamy graf postaci rodzic-(k-1) dzieci, odraz wyświetlamy ilość bananów jako k-1, bo nie ma innych możliwośći.
bool isChildrenParentGraph(int k, int banana) {
  return banana==k-1;
}

// Niech k jest łączną ilość naszych wierzchołków, zatem po wcześniejszym obliczeniu ilości bananów
// Powinniśmy mieć dokładnie k-banana-1 dzieci ( -1 ponieważ wcześniej rozważyliśmy sytuacje gdy graf ma dwa stopnie),
// Na tym poziomie jedyną możliwościa jest graf 3 stopniowy, zatem odejmujemy od wszystkich wierzchołków również rodzica.
// Jesli nasza ilość dzieci = k-banana-1, a graf powinien byc równy ( czyli każde dziecko powinno mieć taką samą ilość bananów)
// Z czego wynika,  iż banana % dzieci ==0.
bool isGoodChildrenAndGrandchildNumbers(int k, int banana) {
  return banana % (k-banana-1) == 0;
}


// @see bool isChildrenHavePropertConnections(int k, string text, int possibleChildrens, int singleChildrenConnections)
bool isGoodChildrensConnection(int possibleChildrens, int singleChildrenConnections, int childrens) {
  return (possibleChildrens == singleChildrenConnections && childrens == possibleChildrens + 1) || (childrens == possibleChildrens);
}

//Sprawdza czy istnieje dokładnie k-banana-1 dzieci co mają możliwe banana/k+1 połączeń 
//UWAGA!! TO NIE GWARANTUJE PEŁNEGO SPŁENIENIA ZASAD ZADANIA -> MOŻLIWE JEST STWORZENIE GRAFU, KTÓRY SPEŁNIA ZASADE A NIE JEST GWIAZDĄ.
//Ważne: w sytuacji gdy ilość dzieci jest równa ich możliwym połączeniom to possibleChildrens będzie +1 ponieważ wliczony zostanie rodzic.
bool isChildrensWithPropertyConnectionsNumber(int k, string text, int possibleChildrens, int singleChildrenConnections) {
  int childrens = 0;

  for (int m = 0; m < static_cast<int>(text.length()); ){
    string fragment = text.substr(m, k);
    if (countCharacterOccurrences(fragment,'1') == singleChildrenConnections) {
        childrens++;
    }
    m = m+k;   
  }
    
  if (isGoodChildrensConnection(possibleChildrens,singleChildrenConnections,childrens)) 
    return true;
  else 
    return false;
}

//Sprawdza czy każde dziecko z podanych w zbiorze ma dokładnie banana/k+1 połączeń 
bool isAllChildrensHaveGoodConnections(unordered_set<int>& set,string text, int k, int singleChildrenConnections) {

   bool isEssa = true;
   for (unordered_set<int>::iterator it = set.begin(); it != set.end(); ++it) {
        int element = *it;
        string fragment = text.substr(k*(element-1),k);
        int connections = countCharacterOccurrences(fragment,'1');
        if (connections != singleChildrenConnections){
          isEssa = false;
          break;
        }
    }
    return isEssa;

}

//Liczy banany dla kolejnych możliwości 
void coutBananasForGoodChildrenAndGrandchildNumbers(int k, int banana, string text, unordered_set<int>& set, string grandChildRows) {

    int possibleChildrens = k-banana-1;  //Możliwych dzieci mamy tylko k ( ilosc wszystkich wierzcholkow - ilosc wierzcholkow z jednyn polaczeniem ( banany) - 1 (rodzic))
    int singleChildrenConnections = banana/possibleChildrens+1; //Dziecko może tylko ilosc polaczen == banana/dzieci + 1 (rodzic) 

    if (isChildrensWithPropertyConnectionsNumber(k,text,possibleChildrens,singleChildrenConnections) &&  isAllChildrensHaveGoodConnections(set,text,k, singleChildrenConnections))
          printf("%d bananas :)\n", banana);
    else 
          printf("0 bananas :(\n");
    
}

//Wszysttkie zasady są dla grafów gdzie wierzcholki są >2, zatem należy wykluczyć sytuacje dla najprosztego grafu postaci rodzic-dziecko 
bool isTheSimplestGraph(int banana, int k) {
return banana==k;
}

//Główna funkcja dla podstawowych struktur ( prosty grafy postaci rodzic-dzieci oraz rodzic-dzieci-wnuki)
void coutBananas(int k, string text) {

    unordered_set<int> childrenRows; //Tworzy zbiór rodziców -> (zawiera numery linii teoretycznych rodziców)
    string grandChildRows = "";  //Lokuje wszystkie numery linii wnuków

    int banana = countBananasAndGetGrandchildrenAndChildrensRows(childrenRows,grandChildRows,text,k);

    if (isChildrenParentGraph(k,banana) || isTheSimplestGraph(banana,k))
      printf("%d bananas :)\n", banana);
    else if (isGoodChildrenAndGrandchildNumbers(k,banana)) 
      coutBananasForGoodChildrenAndGrandchildNumbers(k,banana,text,childrenRows,grandChildRows);
    else 
      printf("0 bananas :(\n");
}



int main() {

   string text;
    int k;
    int lines;
    lines = parseNumber();

    for (int i = 0; i < lines; i++){

    k = parseNumber();

    getline(cin, text);

    coutBananas(k,text);

    }
    

  return 0;
} 