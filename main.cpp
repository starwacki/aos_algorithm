#include <iostream>
#include <list>
using namespace std;
#include <set>
#include <string>

int orderOfExecution(int N,int K) {
    
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
    return number;
}

//Driver Function.

int main() {
  string answer;
  int lines;
  int n;
  int k;
  cin >> lines;

  for (int i = 0; i < lines; i++) {
    cin >> n;
    cin >> k;
    answer.append(to_string(orderOfExecution(n,k)));
    answer.append("\n");
  }

  cout << answer;
  
  return 0;
}