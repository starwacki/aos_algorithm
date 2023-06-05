#include <iostream>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <array>
using namespace std;
#include <string>
#include <cmath>


//Metoda jest nieco innym zapisem wzoru jawnego na rozwiazanie problemu: 2n - 2^(1+floor(Logn)) + 1
// nasz problem jest zmodyfikowany, jednakże funkcja jest szybka dla n=k i dużych liczb :) 
long long josephify(long long n){
 
    int ans = log2(n);
    long long poww = pow(2,ans);
    long long l = n - poww;
    return 2 * l + 1;
}


//Główna funkcja do zabijania
long long kill(long long n, long long k ) {

    int index;
    long long numberInFirstIndex = 1;
    long long numberInSecondIndex = 3;

    long long acutalKilledPersons = n/2;
    long long personsKilledInThisIteration = n/2;
    long long personsInCircle = n-acutalKilledPersons;

    long long firstNumberToKillInIteration;
    long long iterations = 1;

    if (n % 2 ==0) {
        firstNumberToKillInIteration = numberInSecondIndex;
        numberInSecondIndex = numberInFirstIndex + pow(2,iterations+1);
        index = 2;
    } else {
        firstNumberToKillInIteration = numberInFirstIndex;
        numberInFirstIndex = numberInSecondIndex;
        numberInSecondIndex = numberInFirstIndex + pow(2,iterations+1);
        index = 1;
    }

    while (acutalKilledPersons < k){

        (personsInCircle % 2 !=0 && index ==1) ? personsKilledInThisIteration = personsInCircle/2 + 1 : personsKilledInThisIteration = personsInCircle/2;
        
       //power jest rozbite ponieważ wychodzilo poza long longa.       
       if (k <= (acutalKilledPersons+personsKilledInThisIteration)){ 
         long long nextNumbers = k-acutalKilledPersons-1;
         long long power = pow(2,iterations+1);
         long long next = power*nextNumbers;
         return firstNumberToKillInIteration + next; 
       }
    
       iterations++;

       if ((personsInCircle % 2 == 0  && index == 2) || (personsInCircle % 2 != 0  && index == 1)){
        firstNumberToKillInIteration = numberInSecondIndex;
        numberInSecondIndex = numberInFirstIndex + pow(2,iterations+1);
        index = 2;
       } else {
        firstNumberToKillInIteration = numberInFirstIndex;
        numberInFirstIndex = numberInSecondIndex;
        numberInSecondIndex = numberInFirstIndex + pow(2,iterations+1);
        index = 1;
       }

        acutalKilledPersons = acutalKilledPersons + personsKilledInThisIteration;
        personsInCircle = personsInCircle - personsKilledInThisIteration;  
          
       }


       return -1;
}

long long orderOfExecution(long long N,long long K) {

    //optymalizuje k ujemne
    long long personInOrderToKill = (K < 0) ? K+N+1 : K; 
  
    //zwraca typa gdy N=K
    if (personInOrderToKill==N){
        return josephify(N);
     }

     //zwraca typa z pierwszej iteracji
    if (personInOrderToKill<=N/2)
     return 2*personInOrderToKill;
     
    
    return kill(N,personInOrderToKill);
}

//funkcja szybsza od cina/couta do brania inputa.
static long long parseNumber(void)
{
    long long c, n;
    bool  isMinus = false;

    n = getchar();
    if (n=='-') {
        isMinus = true;
        n = getchar()-'0';
    } 
    else 
       n = n-'0';
   
    while (isdigit((c = getchar())))
        n = 10*n + c-'0';

    if (isMinus)
      return -n;
    else
      return n;
}

int main() {
  long long n;
  long long k;
  long long lines = parseNumber();

    for (long long i = 0; i < lines; i++) {
    n = parseNumber();
    k = parseNumber();
    printf("%lld\n", orderOfExecution(n,k));
  }
  

  
  return 0;
}