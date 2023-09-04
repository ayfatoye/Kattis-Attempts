#include <bits/stdc++.h>
using namespace std;
 
// int findNext(map<int, int>& mapy, string str, int i){
//     int l = i;
//     while(l > 0){
//         if(mapy.find(l) != mapy.end()){
//             l--;
//         }
//         else{
//             break;
//         }
//     }
//     return l;

// }
 
int main(){
    string str = "";
    cin >> str;
    // int next = 0;
    // // int i = 0; 
    // // while(str.find('<') != string::npos){
    // //     i = str.find('<');
    // //     str.erase(i, 1);
    // //     i--;
    // //     // cout << "help"; return 0;
    // //     // cout << "i: " << i; cout << "\n";
    // //     // cout << "str: " << str; cout << "\n";
    // //     str.erase(i, 1);
    // // } 
    // // cout << str;
    // // cout << "\n";
    // map<int, int> mapy; // contains all the indices we want to remove

    // for(int i = 0; i < str.length(); i++){
    //     if(str[i] == '<'){
    //         mapy.insert({i, 0});
    //         if(str[i - 1] != '<'){
    //             mapy.insert({i - 1, 0});
    //         }
    //         else{
    //             next = findNext(mapy, str, i); // returns the closest index value going left from i that isn't in mapy yet
    //             mapy.insert({next, 0});
    //         }
    //     }
    // }
    // string output = "";

    // for(int i = 0; i < str.length(); i++){
    //     if(mapy.find(i) != mapy.end()){
    //         continue;
    //     }
    //     else{
    //         output += str[i];
    //     }
    // }

    // cout << output; cout << "\n";
    stack<char> stack;
    for(int i = 0; i < str.length(); i++){
        if(str[i] != '<'){
            stack.push(str[i]);
        }
        else{
            stack.pop();
        }
    }
    string output = "";
    while(!stack.empty()){
        output += stack.top();
        stack.pop();
    }
    reverse(output.begin(), output.end());
    cout << output; cout << "\n";

}