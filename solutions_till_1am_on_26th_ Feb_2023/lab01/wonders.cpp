#include <bits/stdc++.h>
using namespace std;
 
// int soln(){
 
// }
 
int main(){
    map<char, int> mapy;
    int min = 0; // the card set with the least cards. this should be the same as the number of "7-point" sets.
    string str = "";
    cin >> str;

    for(int i = 0; i < str.length(); i++){
        if(mapy.find(str[i]) != mapy.end()){ // true means it's already in the map
            mapy.at(str[i])++;
        }
        else{
            mapy.insert({str[i], 1});
        }
    }
    
    min = mapy.begin()->second;

    for(auto i = mapy.begin(); i != mapy.end(); i++){
        if(i->second < min){
            min = i->second;
        }
    }
    
    // int output = 0;
    if(mapy.size() < 3){
        min = 0;
    }
    int output = min * 7;
    //cout << "min: "<< min << "\n";

    for(auto i = mapy.begin(); i != mapy.end(); i++){
        output += (i->second * i->second);
    }

    cout << output << "\n";
}