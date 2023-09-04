#include <bits/stdc++.h>
using namespace std;
 
// int soln(){
 
// }
 
int main(){
    int n = 0; // num of participants
    int b = 0; // budget
    int h = 0; // num of hotels
    int w = 0; // num of weekends

    string p = ""; // price of current hotel
    int beds = 0; // current num of available beds
    int minBed = 0; // in hindsight, this should be named maxBed
    string output = "";
    // bool stayHome = true;
    
    string str = "";
    int currPrice = 0;
    string useless = "";
    string fuckThis = "";
    getline(cin, fuckThis);
    stringstream s1(fuckThis);

    s1 >> n >> b >> h >> w; 
    // cout << "n: " << n << " b: " << b << " h: " << h << " w: " << w << "\n";
    int minPrice = -1;
    vector<int> vect;

    /*
    - we take it one hotel at a time:
        - check if the price is within budget AND the minBed is >= n: 
            - then update the global minPrice variable if necessary
    - at the end of it, if minPrice is still -1, return "stay home":
        - else: return minPrice
    */
    

    while(getline(cin, p)){
        // cout << "p is: " << p << "\n";
        // return 0;
        getline(cin, str);
        // cout << "str is: " << str << "\n";
        // return 0;
        stringstream ss(str);
        ss >> minBed;
        for(int i = 0; i < w - 1; i++){
            int temp = 0;
            ss >> temp;
            if(temp > minBed){
                // cout << "ssh1 ";
                // return 0;
                minBed = temp;
            }
        }
        // if minBed is less than n, print not enough
        // cout << "minBed: " << minBed << "\n";
        // cout << "p is: " << p << "\n";
        // return 0;
        currPrice = stoi(p);
        currPrice *= n;

        if(b >= currPrice && minBed >= n){
            vect.push_back(currPrice);       
        }
    }
    if(vect.empty()){
        string output = "stay home";
        cout << output;
        return 0;
    }

    else{
        sort(vect.begin(), vect.end());
        int output = vect.at(0);
        cout << output;
        return 0;
    }


}