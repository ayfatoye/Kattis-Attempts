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

void soln() {
    int n = 0;
    cin >> n;
    vector<int> socks(2 * n);

    for (int i = 0; i < 2 * n; i++)
        cin >> socks[i];

    // vector<int> stack2;
    int cnt = 0;
    
    stack<int> s1;
    for(int i = 2*n - 1; i >= 0; i--)
        s1.push(socks[i]);

    stack<int> s2;

    while(!s1.empty()){
        if(s2.empty() || s1.top() != s2.top()){
            s2.push(s1.top());
            s1.pop();
            cnt++;
        }
        else{
            s2.pop();
            s1.pop();
            cnt++;
        }
    }
    if(!s2.empty())
        cout << "impossible\n";

    else{
        cout << cnt << endl;
    }
}

int main() {
    soln();
}
