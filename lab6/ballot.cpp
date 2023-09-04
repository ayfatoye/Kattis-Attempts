#include <bits/stdc++.h>
using namespace std;
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define WHITE   "\033[1;37m"
#define NC      "\033[0m"
#define dbg(x) cerr<<RED<<#x<<" = "<<x<<NC<<endl
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
   ll n = 0; ll b = 0;

   while(cin >> n >> b){

    if(n == -1){
        break;
    }

    ll temp = 0;

   priority_queue<pair<ll, pair<ll, ll>>> pq;

   for(ll i = 0; i < n; i++){
        cin >> temp;
        pq.push({temp, {temp, 1}});
        b--;
   }
   pair<ll, pair<ll, ll>> tp;
   ll avg = 0;

      
   for(ll i = 0; i < b; i++){
        tp = pq.top();
        pq.pop();
        if(tp.second.first % (tp.second.second + 1) > 0){
            avg = tp.second.first/(tp.second.second + 1) + 1;
        }
        else{
            avg = tp.second.first/(tp.second.second + 1);
        }
        pq.push({avg, {tp.second.first, tp.second.second + 1}});
   }

   cout << pq.top().first << endl;

   }
//    cin >> n >> b;
   
}
 
int main(){
    soln();
}