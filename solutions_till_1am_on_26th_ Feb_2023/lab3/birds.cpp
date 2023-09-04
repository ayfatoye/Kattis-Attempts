#include <bits/stdc++.h>
using namespace std;
 
void soln(){
    int l; int d; int n;
    vector<int> vect;
    string b = ""; // current birds
    int output = 0; 

    cin >> l >> d >> n; getline(cin, b);
    if(l < 12){
        cout << 0 << "\n";
        return;
    }
    else if(l == 12 && n == 0){
        cout << 1 << "\n";
        return;
    }
    else if(l == 12 && n == 1){
        cout << 1 << "\n";
        return;
    }
    else if(n == 0){
        cout << ((l - 12)/5) + 1 << "\n";
        return;
    }
    

    for(int i = 0; i < n; i++){
        getline(cin, b);
        vect.push_back(stoi(b));
    }
    
    sort(vect.begin(), vect.end());
    // cout << "vect[0]: " << vect[0] << " d: " << d; cout << "\n";
    output += (((vect[0] - 6) / d));
    // cout << "output: " << output; cout << "\n";

    for(int i = 1; i < vect.size(); i++){
        // cout << "vect[i]: " << vect[i] <<" vect[i - 1]: "<< vect[i - 1] <<" d: " << d; cout << "\n";
        output += (((vect[i] - vect[i-1])/d) - 1);
        // cout << "output: " << output; cout << "\n";
    }
    // cout << "l: " << l << " vect.size: " << vect.size() << " vect.size - 1: " << (vect[vect.size() - 1]) << "\n";

    output += (((l - 6) - (vect[vect.size() - 1])) / d);

    cout << output; cout << "\n";

}
 
int main(){
    soln();
}