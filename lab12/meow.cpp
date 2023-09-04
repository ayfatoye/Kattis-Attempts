#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
class unionFind
{
public:
    vector<int> vect;
    vector<int> maxSize;    // should be called maxheight, it tells you the height of the mini-tree
    vector<int> actualSize; // this is the size of whatever mini set we're talking about. for example, actualSize[3] means what's the number of nodes in whatever tree/set 3 is in?
                            // to find the actualsize of a set, you do that by first finding the root of what set the element in question is in, and then you can find the actualsize

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

void soln()
{
    int m = 0, c = 0;
    cin >> m >> c;

    int from = 0, to = 0, sz = 0;
    vector<pair<int, pair<int, int>>> all_edges;
    int combs = c * (c - 1) / 2;

    for (int i = 0; i < combs; i++)
    {
        cin >> from >> to >> sz;
        all_edges.push_back({sz, {from, to}});
    }

    sort(all_edges.begin(), all_edges.end());
    vector<int> kruskies;
    vector<int> kruskiesNodes;
    unionFind uf(c);
    int k = 0;
    int l = 0;

    while (l < c - 1)
    {

        if (uf.find(all_edges[k].second.first) != uf.find(all_edges[k].second.second))
        {
            kruskies.push_back(all_edges[k].first);
            uf.merge(all_edges[k].second.first, all_edges[k].second.second);
            l++;
        }

        k++;
    }

    int sumKruskies = accumulate(kruskies.begin(), kruskies.end(), 0);

    (sumKruskies + c <= m) ? cout << "yes\n" : cout << "no\n";
}

int main()
{
    int t = 0;
    cin >> t;

    while (t--)
    {
        soln();
    }
}