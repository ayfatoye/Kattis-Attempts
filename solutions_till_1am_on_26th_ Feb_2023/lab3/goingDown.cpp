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
//    string str = "";
   ll n = 0;
   ll k = 0;
   ll first = 0;
   ll curr = 0;
//    ll g_max = 0;
   ll l_max = 0;


//    cin >> n >> k;
//    vector<pair<ll, ll>> vect;

//    for(ll i = 0; i < n; i++){
//     cin >> curr;
//     vect.emplace_back(curr, 1);
//     vect.emplace_back(curr + 1000, -1);
//    }

// //    dbg(vect.size());
//     sort(vect.begin(), vect.end());
//     dbg(vect);
//     dbg(vect[3]);
//     dbg(vect[3].second);

//     for(ll i = 0; i < vect.size(); i++){
//         if(vect[i].second == 1){

//             l_max++;
//             dbg(l_max);
//         }
//         else{
//             if(l_max > g_max){
//                 g_max = l_max;
//             }
//             l_max = 0;
//         }

//     }
//     dbg(g_max); dbg(k);
    

//     // ll output = ceil(g_max / k);
//     // dbg(output);
//     // cout << output << "\n";

    // if(g_max % k == 0){
    //     cout << (g_max/k) << "\n";
    // }
    // else{
    //     cout << (g_max/k + 1) << "\n";
    // }

    queue<ll> q;
    cin >> n >> k >> first;
    if(n == 1){
        cout << "1\n";
        return;
    }

    // dbg(first);
    q.push(first);


    // if request1 is 0, and request2 is 1000, treating it like request1 finishes before request2 goes through

    for(ll i = 0; i < n - 1; i++){
        cin >> curr;
        // dbg(curr); //dbg(q.front());
        while((q.front() + 1000) <= curr && (!q.empty())){
            // dbg(q.front());
            q.pop();
            // dbg(q.front());
        }
        // cout << "here: " << curr;
        q.push(curr);

        if(q.size() > l_max){
            l_max = q.size();
        }
    }

    if(l_max % k == 0){
        cout << (l_max/k) << "\n";
    }
    else{
        cout << (l_max/k + 1) << "\n";
    }
}
 
int main(){
 soln();
}