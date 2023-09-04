#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl
typedef long long ll;
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::pair<T1, T2>& pair) {
    return out << '(' << pair.first << ", " << pair.second << ')';
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec) {
    if(vec.empty()) return out << "[]";
    out << '[';
    for(size_t i = 0; i < vec.size()-1; i++) out << vec.at(i) << ", ";
    return out << vec.back() << ']';
}
 
void soln(){
   ll n;
   cin >> n;
   vector<ll> vect; vect.resize(n);

   for(ll i = 0; i < n; i++){
        cin >> vect[i];
   }

   sort(vect.begin(), vect.end(), [](ll a, ll b){return a > b;});
//    dbg(vect);

   for(ll i = 0; i < n; i++){
        vect[i] += (i + 1);
   }  

   sort(vect.begin(), vect.end(), [](ll a, ll b){return a > b;});

//    dbg(vect);
    cout << vect[0] + 1 << endl;

}
 
int main(){
 soln();
}