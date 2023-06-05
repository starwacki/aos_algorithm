#include <string>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;


int matrix[1000][1000]; //Globalna macierz wypełniona jedynkami
int matrixToSquare[1000][1000];  //Owoc podniesienia powyższej macierzy do kwadratu



//Metoda szybsza od cina/scanf do brania inputa dla liczb - wykorzystuje nisko poziomową funkcje z c - getchar() (dla windows) - dla linuxa jest getchar_unlocked()
static int parseNumber(void){
    int c, n;
    n = getchar();
    n = n-'0';

    while (isdigit((c = getchar())))
        n = 10*n + c-'0';
      return n;
}

//Zaznacza wierzcholki, które nie mają prawa być połączone wartościami 0
void clearUnconecctedTops(int allTops, int walls) {
    for (int i = 0; i < walls; i++){
        int topWalls;
        int wallTop;
        topWalls = parseNumber();

        int* topsArray = new int[topWalls];
        for (int j = 0; j < topWalls; j++){
            wallTop = parseNumber();
            topsArray[j] = wallTop;
        }

        int wallTop1;
        int wallTop2;
        for (int j = 0; j < topWalls-1; j++){

            wallTop1 = topsArray[j];
        
            for (int k = j+1; k < topWalls; k++){
                wallTop2 = topsArray[k];
                matrix[wallTop1][wallTop2] = 0;
                matrix[wallTop2][wallTop1] = 0;
                }
        }


        delete[] topsArray;
    }    
}

void initializeMatrix(int tops) {
    for (int i = 0; i < tops; i++){
        for (int j = 0; j < tops; j++){
            matrix[i][j] = 1;
            matrix[j][i] = 1;
            matrix[i][i] = 0;
        }
    }
}

int squareMatrixAndGetAllCycles(int tops) {
    int sumOfConnections =0;
    for (int i = 0; i < tops; i++) {
        for (int j = i; j < tops; j++) {
            int sum = 0;
            if (i!=j){
                 for (int k = 0; k < tops; k++) {
                sum += matrix[i][k] * matrix[k][j];
            }
              if (sum >= 2){
                sumOfConnections += (sum*(sum-1))/2;
              }
              
            }
        }
    }
    return sumOfConnections;
}

void diagonals() {
    int tops; //Wierzcholki
    int walls; //Ściany

    tops = parseNumber();
    walls = parseNumber();
    
    initializeMatrix(tops);
    clearUnconecctedTops(tops,walls);
    int allCycles = squareMatrixAndGetAllCycles(tops);

    printf("%d\n",allCycles/2);
}

int main() {
	int lines;
    lines = parseNumber();

    for (int i = 0; i < lines; i++){
	    diagonals();
    }
}