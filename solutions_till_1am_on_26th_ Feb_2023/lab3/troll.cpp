#include <bits/stdc++.h>
using namespace std;
 
void soln(){
    double b; int k; int g;
    cin >> b >> k >> g;
    b--;

    double groups = k / g;
    double output = 0.0;

    if(groups == 1){
        cout << b; cout << "\n";
    }

    else if(groups >= b){
        cout << "1"; cout << "\n";
    }
    else{
        // cout << "b: " << b << "groups: " << groups; cout << "\n";
        output = ceil(b/groups);
        cout << output; cout << "\n";
    }
    
}
 
int main(){
    soln();
}