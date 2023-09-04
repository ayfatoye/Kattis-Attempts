#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl
typedef long long ll;
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::pair<T1, T2>& pair) {
    return out << '(' << pair.first << ", " << pair.second << ')';
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec) {
    if(vec.empty()) return out << "[]";
    out << '[';
    for(size_t i = 0; i < vec.size()-1; i++) out << vec.at(i) << ", ";
    return out << vec.back() << ']';
}
// class unionFind {
//     public:
    
//     vector<int> vect;
    
//     unionFind(int numOfNodes){
//         for(int i = 0; i < numOfNodes; i++){
//             vect.push_back(i);
//         }
//     }
    
//     int find(int node){
//         if(node == vect[node]){
//             return node;
//         }
//         else {
//             //int ans = find(vect[node]);
//             //vect[node] = ans;
//             //return ans;
//             return vect[node] = find(vect[node]);
//         }
//     }
    
//     void merge(int eleA, int eleB){
//         int rootA = find(eleA);
//         int rootB = find(eleB);
//         vect[rootB] = rootA;
//     }
    
// };
 
void soln(){
   int k = 0;
   int n = 0;
   int curr = 0;
   int count = 0;

   vector<int> vect;
   vector<int> vect2;

   cin >> k;
   int curr2 = 0;


   for(int i = 0; i < k; i++){
    cin >> n;
    vect.clear();
    count = 0;
    
    if(n == 1){cout << "0\n"; continue;}
    // cin >> curr;
    for(int i = 0; i < n; i++){
        cin >> curr;
        vect.push_back(curr);
        vect2.push_back(curr);
    }
    // dbg(vect);
    // vect2 = sort(vect);
    sort(vect2.begin(), vect2.end());
    // dbg(vect);
    // dbg(vect2);

    // for(int i = 0; i < vect.size() - 1; i++){
    //     if(vect[i] > vect[i + 1]){
    //         count++;
    //     }
    // }
    // dbg(count);
    while(curr != vect.size() && curr2 != vect.size()){
        if(curr == vect.size() || curr2 == vect2.size()){
            break;
        }
        if(vect[curr] == vect[curr2]){
            curr++;
            curr2++;
            continue;
        }
        else{
            curr++;
            count++;
        }
    }

    cout << count << "\n"; // uncomment

    // cin >> curr;
    // for(int i = 0; i < n - 2; i++){
    //     cin >> curr2;
        
    // }
   }
   
}
 
int main(){
 soln();
}