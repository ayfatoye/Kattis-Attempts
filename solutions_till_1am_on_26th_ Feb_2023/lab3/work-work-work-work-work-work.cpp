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

template <typename T>
std::ostream& operator<<(std::ostream& out, std::priority_queue<T, std::vector<T>, std::greater<T>> vec) {
    if(vec.empty()) return out << "[]";
    out << '[';
    // for(size_t i = 0; i < vec.size()-1; i++) out << vec[i] << ", ";
    // return out << vec.back() << ']';
    while(!vec.empty()){
        out << vec.top() << " ";
        vec.pop();
    }
    out << "end of queue]";
    
}
 
void soln(){
    ll n = 0;
    ll m = 0;
    ll x = 0;
    ll y = 0;
    ll count = 0;

    std::priority_queue<int, std::vector<int>, std::greater<int>> miniQq;
    vector<pair<ll,ll>> vect;

    cin >> n >> m;
    cin >> x >> y;
    // miniQq.push(x + y);
    vect.push_back(make_pair(x, y));

    for(int i = 0; i < n - 1; i++){
        cin >> x >> y;
        vect.push_back(make_pair(x, y));
        /*
        - so have a vector of pairs
        - and a min pq

        - build the vector
        - put first thing's ending in the pq
        - loop through the rest of the vector: 
            - if curr.first > pq.top + m and pq not empty:
                - while curr.first > pq.top + m and pq not empty:
                    - pq.pop
            
            - else: 
                - add curr.first + curr.sec to the pq
            
        */

    }
    sort(vect.begin(), vect.end());
    // dbg(vect);
    miniQq.push(vect[0].first + vect[0].second);
    // dbg(miniQq);

    for(ll i = 1; i < vect.size(); i++){
        // cout << "here0: ";
        // dbg(miniQq);
        // dbg(vect[i]);
        while(!miniQq.empty() && vect[i].first > (miniQq.top() + m)){
                miniQq.pop();
            }

        if(!miniQq.empty() && vect[i].first < miniQq.top()){
            miniQq.push(vect[i].first + vect[i].second);
        }
        else if(!miniQq.empty() && (vect[i].first >= (miniQq.top())) && (vect[i].first <= (miniQq.top() + m))){
            // cout << "here1: ";
            // dbg(miniQq);
            // while(vect[i].first > (miniQq.top() + m) && !miniQq.empty()){
            //     miniQq.pop();
            // }
            // dbg(miniQq);
            count++;
            miniQq.push(vect[i].first + vect[i].second);
            miniQq.pop();
        }
        else if(miniQq.empty()){
            miniQq.push(vect[i].first + vect[i].second);
        }
        // else{
        //     // cout << "here2: ";
        //     // miniQq.push(vect[i].first + vect[i].second);
        //     // // dbg(miniQq);
        //     // count++;
        //     // miniQq.pop();
        //     // // dbg(miniQq);
        //     while(vect[i].first > (miniQq.top() + m) && !miniQq.empty()){
        //         miniQq.pop();
        //     }
            
        // }
        // dbg(miniQq);
    }

    // dbg(count);
    cout << count << "\n";
   
}
 
int main(){
 soln();
}