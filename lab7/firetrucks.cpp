#include <bits/stdc++.h>
using namespace std;
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define WHITE   "\033[1;37m"
#define NC      "\033[0m"
#define dbg(x) cerr<<RED<<#x<<" = "<<x<<NC<<endl
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
                            //to find the actualsize of a set, you do that by first finding the root of what set the element in question is in, and then you can find the actualsize

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

        }
        else
        {
            actualSize[rootB] += actualSize[find(rootA)];
            vect[rootA] = rootB;
        }
    }
};

void soln(){
   int n = 0;
   cin >> n;
   int m = 0;
   int d = 0;

   map<int, int> mapy;
   vector<vector<pair<int, int>>> vect(n + 1);

   // building the adjency list that represent the graph that represent the relations between people via numbers
   for(int i = 1; i <= n; i++){
        cin >> m;
        for(int j = 0; j < m; j++){
            cin >> d;
            if(mapy.find(d) != mapy.end()){
                vect[i].push_back({d, mapy[d]});
                vect[mapy[d]].push_back({d, i});
            }
            else{
                mapy[d] = i;
            }
        }
   }
//    dbg(vect);

   // perform bfs to find correct output

   queue<int> q;
   vector<bool> alreadySeen(n+1);
   int currNode = 1;
   alreadySeen[currNode] = true;
   q.push(currNode);
   string result = "";
   int nodesFound = 0;

   while(!q.empty()){
        currNode = q.front();
        q.pop();

        for(int i = 0; i < vect[currNode].size(); i++){
            if(alreadySeen[vect[currNode][i].second] == false){
                alreadySeen[vect[currNode][i].second] = true;
                // dbg(vect[currNode][i].second);
                q.push(vect[currNode][i].second);
                // dbg(q.front());
                result += (to_string(currNode) + " " + to_string(vect[currNode][i].second) + " " + to_string(vect[currNode][i].first) + "\n");
                nodesFound += 3;
            }
        }
   }
//    dbg(nodesFound);
//    dbg(result);

   if(nodesFound != (3 * (n - 1))){
        cout << "impossible" << endl;
   }
   else{

        // cout << RED << result;
        cout << result;
   }

}
 
int main(){
    soln();
}