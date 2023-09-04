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
std::ostream& operator<<(std::ostream& out, const std::deque<T>& vec) {
    if(vec.empty()) return out << "[]";
    out << '[';
    for(size_t i = 0; i < vec.size()-1; i++) out << vec.at(i) << ", ";
    return out << vec.back() << ']';
}

void balance(deque<ll>& first, deque<ll>& second){
    // ll temp = 0;
    if(first.size() > (second.size() + 1)){
        // temp = first.back();
        second.push_front(first.back());
        first.pop_back();
    }
    else if(second.size() > first.size()){
        first.push_back(second.front());
        second.pop_front();
    }
}

void soln(){
//    deque<ll> first = {1, 2, 3, 4, 5, 10};
//    deque<ll> sec = {4, 5, 6, 7};
   deque<ll> first;
   deque<ll> second;

//    dbg(first);
//    dbg(sec);

//    balance(first, sec);

//    dbg(first);
//    dbg(sec);
    ll n;
    string str;
    ll num;
    cin >> n;

    for(ll i = 0; i < n; i++){
        cin >> str;
        cin >> num;

        if(str == "push_back"){
            second.push_back(num);
            balance(first, second);
        }
        else if(str == "push_front"){
            first.push_front(num);
            balance(first, second);
        }
        else if(str == "push_middle"){
            second.push_front(num);
            balance(first, second);
        }
        else if(str == "get"){
            if(num < first.size()){
                cout << first[num] << "\n";
            }
            else{
                cout << second[num - first.size()] << "\n";
            }
        }
        

    }
}
 
int main(){
    soln();
}