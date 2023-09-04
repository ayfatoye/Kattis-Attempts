#include <bits/stdc++.h>
using namespace std;

bool isPS(double n){
    // cout << "sqrt of n: " << floor(sqrt(n)) << "\n";
    double sqOfn = floor(sqrt(n));
    // cout << "sqrt(n) * sqrt(n): " << floor(sqOfn * sqOfn) << "\n";
    return (n == sqOfn * sqOfn);
}
void soln(string str){
    // string str = "";
    //double test = 0;
    cin >> str;
    int len = str.length();
    
    double nextSq = len;
    if(!isPS(len)){ // if the len of the input isn't a square number, find the next num that is
        while(!isPS(nextSq)){
            nextSq++;
        }
    }
    // cout << "i: " << i << "\n";
    
    int chunk = sqrt(nextSq); // break the string into substrings, or "chunks", of this size. the table is a chunk x chunk table
    // cout << "chunk: " << chunk << "\n";
    // cout << "i: " << i << "\n";

    // loop throught and take one chunk at a time until you can't take a chunck anymore
        // take the remaining 
    
    vector<vector<char>> vec; int k = 0;

    vec.resize(chunk);

    for(int i = 0; i < chunk; i++){
        vec.at(i).resize(chunk);
    }
    // cout << "\n";

    for(int i = 0; i < chunk; i++){
        // cout << "here";
        for(int j = 0; j < chunk; j++){
            if(k < str.length()){
                vec[i][j] = str[k]; k++; //k is used to iterate through the input string
            }
            else{
                vec[i][j] = '*';
            }
           
        }

    }

    // for(int i = 0; i < chunk; i++){
    //     for(int j = 0; j < chunk; j++){
            
    //         cout << vec[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";

    for(int i = 0; i < chunk; i++){
        for(int j = chunk - 1; j >= 0; j--){
            if(vec[j][i] != '*'){
                cout << vec[j][i];
            }
            
        }
    }
    // cout << "\n";
    return;
}
 
int main(){
    string str = "";
    cin >> str;

    while(getline(cin, str)){
        soln(str);
        cout << "\n";
    }
    
}