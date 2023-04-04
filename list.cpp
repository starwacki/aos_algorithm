#include <iostream>
#include <list>
using namespace std;
#include <string>


//Driver Function.

int main() {
  list<int> list;

  for (int i = 1; i <= 10; ++i)
  {
    list.push_back(i);
  }

 for (auto it = list.begin(); it != list.end(); it++) {
        cout << *it << " ";
    }
  

  
  return 0;
}