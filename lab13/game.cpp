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
int n = 0;
int k = 0;

int supeMod(string &s)
{
    // if (isdigit(s)){
        int _s = stoi(s);

        if(_s > 0){
            return _s % n;
        }
        else{
            return (-1 * (abs(_s) % n));
        }
    // }
    // else{

    // }
    cout << "superMode not work\n" << endl;
    return 0;    
}

void soln()
{
    cin >> n >> k;
    string s = "0";
    int holder = 0;
    stack<int> st;
    int m = 0;

    for(int i = 0; i < k; i++){
        cin >> s;
        // if(isdigit(s[0])){
        //     holder += supeMod(s [0]);
        //     st.push(s[0]);
        // }
        // else{
        //     cin >> m;
        //     while(m--){
        //         holder -= supeMod(st.top());
        //         st.pop();
        //     }
        // }
        if(s == "undo"){
            cin >> m;
            while(m--){
                // holder -= supeMod(st.top());
                st.pop();
                holder = st.top();
                dbg(holder);
            }
        }
        else{
            dbg(supeMod(s));
            holder += supeMod(s);
            dbg(holder);
            st.push(holder);
        }
    }

    cout << holder << endl;
}

int main()
{
    soln();
}