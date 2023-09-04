#include <bits/stdc++.h>
using namespace std;
 
// int soln(){
 
// }
 
int main(){
    // 2:45 AM, 1/27: can't think of an algorithm that'd do this faster than O(n^2)
    priority_queue<int, std::vector<int>, std::greater<int>> minP;
    priority_queue<int> maxP;
    vector<int> greatVect;
    vector<int> smolVect;
    int count = 0;
    vector<int> vect;

    string str = "";
    string str2 = "";
    int temp = 0;

    getline(cin, str);
    getline(cin, str2);

    stringstream ss(str2);

    for(int i = 0; i < stoi(str); i++){
        ss >> temp;
        vect.push_back(temp);
    }

    // for(int i = 0; i < vect.size(); i++){
    //     cout << vect[i]; 
    // }
    // cout << "\n";

    for(int i = 0; i < vect.size(); i++){
        maxP.push(vect[i]);
        if(maxP.top() == vect[i]){
            greatVect.push_back(vect[i]);
        }
        else{
            continue;
        }
    }
    map<int, int> mapy;
    // cout << "greater Vect: " << "\n";
    for(int i = 0; i < greatVect.size(); i++){
        // cout << greatVect[i] << " "; 
        mapy.insert({greatVect[i], 0});
    }
    // cout << "\n";

    
    for(int i = vect.size()-1; i >= 0; i--){
        minP.push(vect[i]);
        if(minP.top() == vect[i]){
            smolVect.push_back(vect[i]);
        }
        else{
            continue;
        }
    }
    // cout << "smolVect: " << "\n";
    // for(int i = 0; i < vect.size(); i++){
    //     cout << smolVect[i] << " "; 
    // }


    // vector<int> result;

    // set_intersection(greatVect.begin(), greatVect.end(), smolVect.begin(), smolVect.begin(), inserter(result, result.begin()));

    // cout << "size: " << result.size(); cout << "\n";
    for(int i = 0; i < smolVect.size(); i++){
        if(mapy.find(smolVect[i]) != mapy.end()){
            count++;
        }
    }
    // cout << "ans: " << count;
    cout << count << "\n";
    // finding all nums greater than anything on their left 
    // for(int i = 0; i < )
}