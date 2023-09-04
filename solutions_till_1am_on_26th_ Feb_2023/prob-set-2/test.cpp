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
class unionFind {
    public:
    
    vector<int> vect;
    
    unionFind(int numOfNodes){
        for(int i = 0; i < numOfNodes; i++){
            vect.push_back(i);
        }
    }
    
    int find(int node){
        if(node == vect[node]){
            return node;
        }
        else {
            int ans = find(vect[node]);
            vect[node] = ans;
            return ans;
        }
    }
    
    void merge(int eleA, int eleB){
        int rootA = find(eleA);
        int rootB = find(eleB);
        vect[rootB] = rootA;
    }
    
};
 
void soln(){
   
}
 
int main(){
 
}