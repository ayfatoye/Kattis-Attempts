#include <bits/stdc++.h>
using namespace std;
 
void soln(){
    /*
    - so we use two integers to simulate to stacks, 1(for taking) and 2(for droping)
    - whenever we reading in drop, we just add the following number to 2 (by storing it in currNum)
    - whenever we read in take, we store the following number in currNum
        - if currNum is greater than take, set take to 0, find (currNum - take), save it to diff
            - then add drop - (diff), set drop to 0
        - else: 
            - set take to take - currNum
        
    */
   string str = "";
//    string str2 = "";
//    string command = "";
//    string currNum = "";
//    int _currNum = 0;
//    int drop = 0;
//    int take = 0;
//    int diff = 0;
   while(getline(cin, str) && str != "0"){
        // if(issaNum(str)){
        //     for(int i = 0; i < stoi(str); i++){

        //     }
        // }
        string str2 = "";
        string command = "";
        string currNum = "";
        int _currNum = 0;
        int drop = 0;
        int take = 0;
        int diff = 0;

        for(int i = 0; i < stoi(str); i++){
            getline(cin, str2);
            stringstream ss(str2);
            ss >> command;
            ss >> currNum;
            _currNum = stoi(currNum);

            if(command == "DROP"){
                cout << "DROP " << "2 " << currNum << "\n";
                drop += _currNum;
            }
            else if (command == "TAKE"){
                if(_currNum > take){
                    diff = _currNum - take;
                    take = drop - diff;
                    cout << "MOVE " << "2->1 " << drop << "\n";
                    drop = 0;
                    cout << "TAKE " << "1 " << currNum << "\n";
                }
                else{
                    cout << "TAKE " << "1 " << currNum << "\n";
                    take -= _currNum;
                }
            }
        }
        // return 0;
        cout << "\n";
   }

// TESTING WHEN I HAD NO INTERNET: 
//  getline(cin, str2);
//             stringstream ss(str2);
//             ss >> command;
//             ss >> currNum;
//             // cout << command;
//             if(command == "DROP"){
//                 cout << "DROP " << "2 " << currNum;
//                 cout << "\n";
//                 return 0;
//             }
}

// bool issaNum(string& str){
//     for(char& c : str){
//         if(isdigit(c) == 0){
//             return false;
//         }
//     }
//     return true;
// }
 
int main(){
    soln();    
}