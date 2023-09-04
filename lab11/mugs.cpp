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
    int D;
    cin >> D;

    // bool found = false;
    int n1 = 0;
    int n2 = 0;
    
    if(D % 4 == 2){
        cout << "impossible\n";
        return;
    }
    else if(D % 4 != 0){
        n1 = (D-1)/2;
        n2 = (D+1)/2;
    }
    else{
        n1 = (D/4) - 1;
        n2 = (D/4) + 1;
    }

    cout << n1 << " " << n2 << endl;
}

int main()
{
    soln();
}