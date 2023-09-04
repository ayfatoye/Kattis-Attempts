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

void soln()
{
    int m = 0;
    cin >> m;
    int temp = 0;
    map<int, int> mapy;

    for (int i = 1; i < 74; i++)
    {
        for (int j = i + 1; j < 74; j++)
        {
            temp = (i * i * i) + (j * j * j);
            mapy[temp]++;
        }
    }

    int _max = INT32_MIN;
    for(auto [key, val] : mapy){
        if(val > 1 && key <= m){
            _max = max(key, _max);
        }
    }

    if(_max == INT32_MIN){
        cout << "none" << endl; return;
    }
    cout << _max << endl;
}

int main()
{
    soln();
}