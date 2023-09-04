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
    ll t; ll n; 
   ll currentT = 0;

   cin >> currentT >> t >> n;

    vector<long long> walk(n + 1);
    vector<long long> rides(n);
    vector<long long> intervals(n);

   

   for(ll i = 0; i < n + 1; i++){
        cin >> walk[i];
   }

   for(ll i = 0; i < n; i++){
        cin >> rides[i];
   }

   for(ll i = 0; i < n; i++){
        cin >> intervals[i];
   }

   dbg(walk); 
   dbg(rides);
   dbg(intervals);

   for(ll i = 0; i < n; i++){
        currentT += walk[i];
        if((currentT % intervals[i]) != 0){
            currentT += (intervals[i] - (currentT % intervals[i]));
        }
        currentT += rides[i];
   }
   currentT += walk[n];

   if(currentT <= t){
        cout << "yes\n";
   }
   else{
    cout << "no\n";
   }
   

   
}
 
int main(){
     soln();
}