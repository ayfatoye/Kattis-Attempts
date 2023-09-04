#include <bits/stdc++.h>
using namespace std;
 
// int soln(){
 
// }
 
int main(){
    long n = 0;
    long t = 0;
    long temp = 0;
    string str = "";
    string str2 = "";

    getline(cin, str);
    stringstream ss(str);
    ss >> n >> t; 

    getline(cin, str2);
    stringstream ss2(str2);
    vector<long long> vect;
    map<long, long> mapy;
    for(long i = 0; i < n; i++){
        ss2 >> temp;
        vect.push_back(temp);
    }

    if(t == 1){
        cout << "7";
        // cout << "\n";
    }
    else if(t == 2){
        if(vect[0] > vect[1]){
            cout << "Bigger";
        }
        else if(vect[0] == vect[1]){
            cout << "Equal";
        }
        else{
            cout << "Smaller";
        }
        
    }
    else if(t == 3){
        sort(vect.begin(), vect.begin() + 3);
        cout << vect[1];
    }
    else if(t == 4){
        cout << accumulate(vect.begin(), vect.end(), 0ll);  
    }
    else if (t == 5){
        long sum = 0;
        for(long curr : vect){
            if(curr % 2 == 0){
                sum += curr;
            }
        }
        cout << sum;
    }
    else if(t == 6){
        char c = 'a';
        for(long t : vect){
            c = (t%26) + 'a';
            cout << c;
        }
        // long t = 7;
        // char c = t + 'a';
        // cout << c;
    }
    else if(t == 7){
        long i = 0;
        while(1 == 1){
            if(vect[i] >= n){
                cout << "Out"; return 0;
            }
            else if(vect[i] == n-1){
                cout << "Done"; return 0;
            }
            else{
                if(mapy.find(i) != mapy.end()){
                    cout << "Cyclic"; return 0;
                }
                mapy.insert({i, 1});
                i = vect[i];
            }
        }

    }
}