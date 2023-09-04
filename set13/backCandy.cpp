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


int gcd(int a, int b)
{
    // cout << "31 \n";
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
// int gcd(int a, int b) { // the euclid theorem
//     a = std::abs(a);
//     b = std::abs(b);

//     if (a < b) {
//         std::swap(a, b);
//     }
//     cout << "43 \n";
//     while (b != 0) {
//         int temp = b;
//         b = a % b;
//         a = temp;
//     }

//     return a;
// }

ll EE(ll a, ll b, ll& x, ll& y)
{
    // what if b is bigger than a?
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
 
    ll x_p, y_p; 
    ll gcd = EE(b, a%b, x_p, y_p);
 

    x = y_p;
    y = x_p -  y_p * (a/b);
 
    return gcd;
}

void solve() {
    ll t;
    cin >> t;

    for (ll i = 0; i < t; ++i) {
        ll k, c;
        cin >> k >> c;

        if(c == 1){
            cout << k + 1 << endl;
            continue;
        }

        if(k == 1){
            if(c == 1){
                cout << 2 << endl;
                continue;
            }
            else{
                cout << 1 << endl; // if k is 1, and c is not 1, then y can be 1 and x can be c - 1
                continue;
            }
        }

        // if (gcd(k, c) != 1) {
        //     cout << "IMPOSSIBLE" << endl;
        // } else {
            ll x_prime = 0, y_prime = 0;
            ll output = EE(k, c, x_prime, y_prime);
            if(output != 1){
                cout << "IMPOSSIBLE" << endl;
                continue;
            }
            ll _x = -1 * x_prime;
            ll _y = y_prime;
            ll n = -1;
            // int result = ;
            // cout << x_prime << " " << y_prime << endl;
            
            while(_y < 0){
                _x = x_prime + (c/output)*n;
                _y = y_prime - (k/output)*n;
                n--;
            }
            // cout << "original: " << x_prime << " " << y_prime << endl;

            // cout << _x << " " << _y << endl;
            cout << _y << endl;
        // }
    }
}

int main() {
    solve();
    return 0;
}
