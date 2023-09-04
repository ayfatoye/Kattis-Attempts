#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define WHITE   "\033[1;37m"
#define NC      "\033[0m"
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

class unionFind
{
public:
    vector<int> vect;
    vector<int> maxSize; // should be called maxheight, it tells you the height of the mini-tree
    vector<int> actualSize; // this is the size of whatever mini set we're talking about. for example, actualSize[3] means what's the number of nodes in whatever tree/set 3 is in?

    unionFind(int numOfNodes)
    {
        for (int i = 0; i < numOfNodes; i++)
        {
            vect.push_back(i);
            maxSize.push_back(1);
            actualSize.push_back(1);
        }
    }

    int find(int node)
    {
        if (node == vect[node])
        {
            return node;
        }
        else
        {
            int ans = find(vect[node]);
            vect[node] = ans;
            return ans;
        }
    }

    void merge(int eleA, int eleB)
    {
        int rootA = find(eleA); // root of the set eleA belongs to
        // approach is to merge the set eleB is a part of into eleA's set
        int rootB = find(eleB);
        if (rootA == rootB)
        {
            return;
        }

        if (maxSize[rootA] == maxSize[rootB])
        {
            actualSize[rootA] += actualSize[find(rootB)];
            vect[rootB] = rootA;
            maxSize[rootA]++;
            
            
        }
        else if (maxSize[rootA] > maxSize[rootB])
        {
            actualSize[rootA] += actualSize[find(rootB)];
            vect[rootB] = rootA;
            // actualSize[rootA]++;
            // actualSize[rootB]++;

        }
        else
        {
            actualSize[rootB] += actualSize[find(rootA)];
            vect[rootA] = rootB;
            // actualSize[rootA]++;
            // actualSize[rootB]++;
        }
        // balancing the actual sizes of the mini trees and the sets
        // if(actualSize[rootA] > actualSize[rootB]){
        //     actualSize[rootB] = actualSize[rootA];
        // }
        // else if(actualSize[rootB] > actualSize[rootA]){
        //     actualSize[rootA] = actualSize[rootB];
        // }
    }
};
 
void soln(){
    int n = 0; int q = 0;
    cin >> n >> q;

    string query = "";

    int a = 0; int b = 0;

    unionFind uf(n + 1);

    for(int i = 0; i < q; i++){
        cin >> query;
        if(query == "t"){
            cin >> a >> b;
            uf.merge(a, b);
        }
        else if(query == "s"){
            cin >> a;
            // cout << BLUE << uf.actualSize[uf.find(a)] << NC << endl;
            cout << uf.actualSize[uf.find(a)] << endl;
        }
    }
}
 
int main(){
    soln();
}