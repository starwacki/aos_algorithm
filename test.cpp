#include <iostream>
#include <list>
using namespace std;
// Header files, namespaces to use
// ordered set
#include <set>

// Returns position of survivor among a circle
// of n persons and every second person being
// killed
int josephus(int n,int l)
{
    // Find value of 2 ^ (1 + floor(Log n))
    // which is a power of 2 whose value
    // is just above n.
    int p = 1;
    while (p <= n)
        p *= 2;
 
    // Return n - 2^(1+floor(Logn)) + 1
    int k = (1+l) % n +1;
    cout << k << " usunieta";
    return n - p/2 + 1;
}

//Driver Function.

int main() {
    int n = 5;
    int k = 5;
  
    cout << josephus(n,k);
  
  
  
  return 0;
}