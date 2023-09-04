#include <bits/stdc++.h>  
using namespace std;

// int soln(){

// }

int main(){

    string str = "";
    int time = 0;
    string letter = "";
    string acc = ""; // is either right or wrong
    int numCorrect = 0; // number of right entries 
    int sum = 0;
    map<string, int> mapy; // key is letter, and value is number of times (before first right) that it is in the input

    while(getline(cin, str) && str != "-1"){
        stringstream s(str);
        s >> time;
        s >> letter;
        s >> acc;

        if(acc == "right"){
            numCorrect++;
            if(mapy.find(letter) != mapy.end()){ // true if it's already in the map
                sum += ((mapy.at(letter)*20) + time);
            }
            else{
                sum += time;
            }
        }
        else if(acc == "wrong"){
            if(mapy.find(letter) != mapy.end()){ // true if it's already in the map
                mapy.at(letter)++;
            }
            else{
                mapy.insert({letter, 1});
            }
        }
    }

    cout << numCorrect << " " << sum;

}


    
