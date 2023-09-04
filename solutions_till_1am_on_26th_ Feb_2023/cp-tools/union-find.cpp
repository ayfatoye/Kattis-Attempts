#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr << #x << " = " << x << endl
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
 