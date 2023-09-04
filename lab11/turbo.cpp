#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
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

template <class T>
using ordered_set= tree<T, null_type, less<T>, rb_tree_tag,
             tree_order_statistics_node_update>;


ordered_set<pair<int, int>> sA;
set<pair<int, int>> sB;

int phase = 1;
void shit(pair<int, int> old)
{
    pair<int, int> newP;
    newP.first = old.second;
    newP.second = old.first;
    if(phase % 2 == 1){
        cout << sA.order_of_key(newP) << endl;
    }
    else{
        cout << sA.size() - sA.order_of_key(newP) - 1 << endl;
    }
    
    sA.erase(newP);
}

void soln()
{
    int n = 0;
    cin >> n;

    pair<int, int> t0;
    pair<int, int> t1;
    int t3 = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> t3;

        t0 = {i + 1, t3};
        sA.insert(t0);

        t1 = {t3, i + 1};
        sB.insert(t1);
    }

    // int phase = 1;
    while (!sA.empty())
    {
        if (phase % 2 == 1)
        {
            t0 = *(sB.begin());
            shit(t0);
            sB.erase(t0);
        }
        else{
            auto it = sB.end();
            t0 = *(--it);
            shit(t0);
            sB.erase(t0);
        }
        phase++;
    }
}

int main()
{
    soln();
}