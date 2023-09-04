#include <iostream>
#include <map>
#include <string>
using namespace std;

int soln(){
    int n;
    int sum;
    cin >> n;
    while(cin >> n){
        sum += n;
    }

    return sum;
}

int main(){
    cout << soln();
}