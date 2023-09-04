#include <bits/stdc++.h>
using namespace std;
 
int soln(int n){
    int oldN = n; // original n
    int _n = n;
    string str = "";
    int len = 0;
    int edge1 = 0;
    int edge2 = 0;
    while(1 == 1){
        n++;
        str = to_string(n);
        len = str.length();
        if(str[len - 1] == '9' && str[len - 2] == '9'){
            edge1 = n;
            break;
        }
    }

    while(1 == 1){
        _n--;
        str = to_string(_n);
        len = str.length();
        if(str[len - 1] == '9' && str[len - 2] == '9'){
            edge2 = _n;
            break;
        }
    }

    int output = ((edge1 - oldN) > (oldN - edge2)) ? edge2 : edge1;
    return output;
}
 
int main(){
    int num = 0;
    cin >> num;
    int output = 0;

    if(num <= 99){
        cout << 99;
    }
    else{
        output = soln(num);
        cout << output;
        cout << "\n";
    }
}