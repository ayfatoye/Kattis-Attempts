#include <bits/stdc++.h>
using namespace std;
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define WHITE   "\033[1;37m"
#define NC      "\033[0m"
#define dbg(x) cerr<<RED<<#x<<" = "<<x<<NC<<endl
#define dbg_blue(x) cerr<<BLUE<<#x<<" = "<<x<<NC<<endl
#define dbg_green(x) cerr<<GREEN<<#x<<" = "<<x<<NC<<endl
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
        // dbg(node);
        if (node == vect[node])
        {
            // cout << "line46\n";
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
        // dbg_green("start merge with: "); 
        // cout << eleA << " " << eleB << endl;;
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
        // dbg_green("end merge\n");
    }
};
  
void soln(){
   vector<pair<int, pair<int, int>>> all_edges;
   vector<pair<int, int>> all_nodes;
   int num_tests = 0;
   cin >> num_tests;
   int s = 0; int p = 0;
   int x = 0; int y = 0; 
   int temp = 0;
   double result = 0.0;
   
   while(num_tests--){
        all_edges.clear(); all_nodes.clear();
        cin >> s >> p;
        for(int i = 0; i < p; i++){
            cin >> x >> y;
            all_nodes.push_back({x, y});
        }
        // dbg(all_nodes);
        for(int i = 0; i < all_nodes.size(); i++){

            for(int j = i+1; j < all_nodes.size(); j++){
                temp = 0;
                temp = (pow((all_nodes[j].first - all_nodes[i].first), 2));
                temp += (pow((all_nodes[j].second - all_nodes[i].second),2));
                all_edges.push_back({temp, {i, j}});
            }
        
        }
        // dbg(all_edges);
        sort(all_edges.begin(), all_edges.end());
        vector<int> kruskies;
        vector<int> kruskiesNodes;
        unionFind uf(p);
        int k = 0;
        int l = 0;
        // dbg(all_edges);
        // while(kruskies.size() < all_edges.size() - s - 1){
        // while(kruskiesNodes.size() < p + 1){
        while(l < p - 1){
            // dbg((all_edges[k].second.first));
            // dbg(kruskies.size()); dbg(all_edges.size()); dbg(s);
            // dbg_blue(uf.vect);
            
            // dbg_green(kruskies);
            
            if(uf.find(all_edges[k].second.first) != uf.find(all_edges[k].second.second)){
                kruskies.push_back(all_edges[k].first);
                // kruskiesNodes.push_back(all_edges[k].second.first);
                // kruskiesNodes.push_back(all_edges[k].second.second);
                uf.merge(all_edges[k].second.first, all_edges[k].second.second);
                l++;
            }
            // dbg_blue(uf.vect);
            // dbg_green(kruskies);
            k++;
        }
        // cout << RED << fixed << setprecision(2) << sqrt(kruskies.back()) << NC << endl;
        // dbg(kruskies.at((kruskies.size() - 1) - (s - 1)));
        dbg(kruskies);
        result = sqrt(kruskies.at((kruskies.size() - 1) - (s - 1)));
        cout << fixed << setprecision(2) << result << endl;

   }


}
 
int main(){
    soln();
}