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

ll a = 0, b = 0, c = 0;
ll nextTime(ll currt)
{
    return (((a * currt + b) % c) + 1);
}

void soln()
{
    ll probs = 0, totalT = 0;
    cin >> probs >> totalT;
    ll t0 = 0;
    cin >> a >> b >> c >> t0;

    vector<ll> vect;
    vect.push_back(t0);

    for (ll i = 1; i < probs; i++)
    {
        vect.push_back(nextTime(vect.back()));
    }

    sort(vect.begin(), vect.end());

    ll solving = 0;
    ll penalty = 0;

    for(ll i = 0; i < vect.size(); i++){
        
        if(solving + vect[i] >= totalT){
            cout << i << " " << penalty % 1000000007 ;
            return;
        }
        solving += vect[i];
        penalty += solving;            
    }

    cout << probs << " " <<  penalty % 1000000007 << endl;

}

int main()
{
    soln();
}