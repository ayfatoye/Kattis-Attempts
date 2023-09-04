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
    map<ll, ll> mapy;
    mapy[1] = 1;
    mapy[2] = 2;
    mapy[6] = 3;
    mapy[24] = 4;
    mapy[120] = 5;
    mapy[720] = 6;
    mapy[5040] = 7;
    mapy[40320] = 8;
    mapy[362880] = 9;
    mapy[3628800] = 10;

    string str = "";
    cin >> str;
    ll key = 0;

    if (str.length() <= 7)
    {
        key = stoll(str);
        cout << mapy[key] << endl;
        // cout << mapy[120] << endl;
    }
    else{
        // if we pretend that str is 10^n, where n is the length of the string,
        // then we know that log(str) = n. so log(str) is either between it's length and it's length + 1
        // cout << str.length() + 3 << endl;

        // we know that str.length() - 1 <= log(str) < str.length(), log base 10
        // now we loop through and do what keyser said in office hours

        // for(int i = 1; i < str.length(); i++){
            
        // }
        double i = 2;
        double curr = 0;

        while(true){
            curr += log10(i);
            if(curr >= str.length() - 1){
                cout << i << endl;
                break;
            }
            i++;
        }
        
    }
}

int main()
{
    soln();
}