#include <iostream>
using namespace std;

void soln(int n, int m){
    /*
    - if they're the same, return n + 1
    - if they're diff:
        - return the smaller plus one to the larger plus one
    */
   if(n == m){
    cout << (n + 1);
    return;
   }

   int a = (n < m) ? n + 1 : m + 1;
   int b = (n < m) ? m + 1 : n + 1;

   for(int i = a; i <= b; i++){
    cout << i << "\n";
   }
}

int main(){
    int n;
    int m;
    cin >> n;
    cin >> m;
    soln(n, m);
}

