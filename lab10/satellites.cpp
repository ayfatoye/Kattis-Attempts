#include <bits/stdc++.h>
using namespace std;
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define WHITE "\033[1;37m"
#define NC "\033[0m"
#define dbg(x) cerr << RED << #x << " = " << x << NC << endl
typedef long long ll;
template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &out, const std::pair<T1, T2> &pair)
{
    return out << '(' << pair.first << ", " << pair.second << ')';
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vec)
{
    if (vec.empty())
        return out << "[]";
    out << '[';
    for (size_t i = 0; i < vec.size() - 1; i++)
        out << vec.at(i) << ", ";
    return out << vec.back() << ']';
}
void printMap(vector<unordered_map<int, double>> mapy)
{
    cerr << BLUE;
    for (int i = 0; i < mapy.size(); i++)
    {
        cout << i << ":\n";
        for (auto &stuff : mapy[i])
        {
            cerr << i << " -> " << stuff.first << "(" << stuff.second << ")\n";
        }
    }
    cerr << NC;
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

double findRadius(pair<pair<double, double>, double>& a, pair<pair<double, double>, double>& b){
    double ans = 0;

    ans += (b.first.first - a.first.first) * (b.first.first - a.first.first);
    ans += (b.first.second - a.first.second) * (b.first.second - a.first.second);
    ans -= (b.second + a.second);

    return ans;
}

void soln()
{
    int n = 0;
    cin >> n;
    vector<pair<pair<double, double>, double>> vect(n);
    double a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        vect[i] = {{a, b}, c};
    }

    vector<unordered_map<int, double>> graph(n);

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){
            graph[i][j] = findRadius(vect[i], vect[j]);
        }
    }
    
}

int main()
{
    soln();
}