#include <iostream>
#include <list>
using namespace std;
#include <set>

void orderOfExecution(int N,int K) {
    // Create a set
    set<int> V;

    int personInOrderToKill = K; 

    if (K < 0)
     personInOrderToKill = K+N+1;
    

    // Push elements in the range [1, N] in the set
    for (int i = 1; i <= N; ++i) {
        V.insert(i);
    }

    // Iterator to store the current position
    auto it = V.begin();

    // Iterate until the size of the set is greater than 1
    int abc = 0;
    int number = 0;
    while (abc < personInOrderToKill) {
        // Advance the iterator by K positions
            it++;
            if (it == V.end()) {
                it = V.begin();
            }
    

        // Print the removed element
        number = *it;

        // Erase it from the set
        it = V.erase(it);

        // If the iterator points to the end of the set, wrap around to the beginning
        if (it == V.end()) {
            it = V.begin();
        }
        abc++;

    }

    // Print the first element of the set
    cout << number << " \n";
}

//Driver Function.

int main() {
  int n[10000];
  int k[10000];
  int lines;
  cin >> lines;

  for (int i = 0; i < lines; i++) {
    cin >> n[i];
    cin >> k[i];   
  }
  
  for (int i = 0; i < lines; i++) {
    orderOfExecution(n[i],k[i]);
  }
  
  
  return 0;
} 