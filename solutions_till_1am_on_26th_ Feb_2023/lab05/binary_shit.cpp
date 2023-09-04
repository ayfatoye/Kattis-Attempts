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
   
   unsigned long long m;
   string str;

   cin >> n;
   bitset<sizeof(ll) * 8> bin(n);

   //cout << bin << endl; // should be 1101

   str = bin.to_string();
   reverse(str.begin(), str.end());

   //cout << str << endl; // should be 1011
   str.erase(str.find_last_not_of('0') + 1, string::npos);

   m = bitset<sizeof(long long) * 8>(str).to_ulong();

   cout << m << endl;
}
 
int main(){
 soln();
}