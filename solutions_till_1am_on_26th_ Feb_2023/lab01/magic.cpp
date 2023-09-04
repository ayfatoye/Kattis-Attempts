#include <iostream>
#include <map>
#include<string>
using namespace std;

// int soln(){

// }

int main(){
    string str;
    cin >> str;

    map<char, char> mapy;
    

    for(int i = 0; i < str.length(); i++){
        if(mapy.find(str[i]) != mapy.end()){ // this means there IS A REPEAT and I can't tell
            cout << 0 << "\n";
            return 0;
            // break;
        }
        else{
            mapy.insert({str[i], '-'});
        }
    }
    // at this point there is NO REPEAT and I CAN tell
    cout << 1 << "\n"; 
    return 0;
}