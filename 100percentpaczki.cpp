#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//Metoda szybsza od cina/scanf do brania inputa dla liczb - wykorzystuje nisko poziomową funkcje z c - getchar() (dla windows) - dla linuxa jest getchar_unlocked()
static int parseNumber(void)
{
    int c, n;
    n = getchar();
    n = n-'0';

    while (isdigit((c = getchar())))
        n = 10*n + c-'0';
      return n;
}

// Rozwiązuje wykorzystując znany w literaturze problem plecakowy rekurencyjnie, źródło: https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
int packages(int W, int (&wt)[15], int (&profits)[15], int n){
 
    // Base Case
    if (n == 0 || W == 0)
        return 0;
 
    // If weight of the nth item is more
    // than Knapsack capacity W, then
    // this item cannot be included
    // in the optimal solution
    if (wt[n - 1] > W)
        return packages(W, wt, profits, n - 1);
 
    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else
        return max(
            profits[n - 1]
                + packages(W - wt[n - 1], wt, profits, n - 1),
            packages(W, wt, profits, n - 1));
}


//Zapisuje profity w tablicy
void getProfits(int items, int (&profits)[15]) {
    int profit;
    for (int i = 0; i < items; i++){
        profit = parseNumber();
        profits[i] = profit;
    }
}

//Zapisuje wagi w tablicy, optymalizuje profit przedmiotu dla wagi > 100, zlicza łączną sume wag przedmiotów
//(Metoda robi o wiele więcej rzeczy niż powinna, jednakże jest to o wiele bardziej wydajne niż rozbicie na więcej podmetod (kolejna iteracja po k wagach czy profitach nie jest optymalna :))
int getSumOfWeightsAndWriteWeightsProfits(int items, int (&wt)[15], int (&profits)[15] ) {
    int weight;
    int sumOfWeight = 0;
    for (int i = 0; i < items; i++){
        weight = parseNumber();
        wt[i] = weight;
        sumOfWeight += weight;
        if (weight > 100)
         profits[i]  > 5 ? profits[i] -= 5 : profits[i] = 0; 
    }
    return sumOfWeight;
}

//Zwraca n (items) największych profitów w tablicy - 
int getTheBigestProfits(int (&profits)[15], int items) {
    sort(profits, profits + items, greater<int>());
    int profit = 0;
    for (int i = 0; i < items; i++){
        profit += profits[i];
    }
    return profit;
    
}

//Jeśli suma wszystkich wag jest mniejsza od maksymalnej wagi to wystaczy wziąć n najbardziej cennych przedmiotów 
bool isSumOfWeightsLowerThanWeight(int sumOfWeights, int maxWeight) {
    return sumOfWeights <= maxWeight;
}

void initializePackages() { 
    int items;
    int profit;
    int weight;
    int maxWeight;
    int weights[15];
    int profits[15];
    
    items = parseNumber();

    getProfits(items,profits);  
    int sumOfWeights = getSumOfWeightsAndWriteWeightsProfits(items,weights,profits);
    
    maxWeight = parseNumber();
    

    isSumOfWeightsLowerThanWeight(sumOfWeights,maxWeight) ? 
    profit = getTheBigestProfits(profits,items)
    :
    profit = packages(maxWeight,weights,profits,items);
    
    profit > 20 ? profit -=20 : profit = 0;
    printf("%d",profit);
    printf("\n");

    
}

int main() {
    int lines;
    lines = parseNumber();


    for (int i = 0; i < lines; i++){

    initializePackages();
    
    }
    
    return 0;
}