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
 
// void soln(){
//    string str = "";
//    ll n = 0;
//    ll m = 0;

//    int a = 0;
//    int b = 0;
//    string currCommand = "";

//    cin >> n >> m; // n is how long str should be, m is how we'll loop through input

//    for(ll i = 0; i < n; i++){
//         str += '0';
//    }

//    for(ll i = 0; i < m; i++){
//         a = 0;
//         b = 0;
//         currCommand = "";
//         cin >> currCommand >> a;

//         if(currCommand == "F"){
//             if(str[a] == '0'){str[a] = '1';}
//             else if(str[a] == '1'){str[a] = '0';}
//         }
//         else if(currCommand == "C"){
//             cin >> b;
//         }
//    }
// }
inline int LSOne(const int x){
    return x & (-x);
}

class FT{
    vector<long long> a;
    int n;

    public:
    
    FT(int x){
        n = x;
        a.resize(x+1, 0);
    }

    void incr(int elem, long long val){
        while(elem <= n){
            a[elem] += val;
            elem = elem + LSOne(elem);
        }
    }

    long long rsq(int elem){
        long long summation = 0;
        while(elem){
            summation += a[elem];
            elem -= LSOne(elem);
        }
        return summation;
    }
    
    long long rsq(int i, int j){
        return rsq(j) - rsq(i - 1);
    }
};

void soln(){
    string str = ""; string command = "";
    int n = 0; ll k = 0;
    cin >> n >> k;

    ll insertAt = 0; 
    ll l = 0; ll r = 0;

    for(ll i = 0; i < n + 1; i++){
        str += '0';
    }

    FT ft(n);    

    for(ll i = 0; i < k; i++){
        cin >> command;
        if(command == "F"){
            cin >> insertAt;

            if(str[insertAt] == '0'){
                ft.incr(insertAt, 1);
                str[insertAt] = '1';
            }

            else if(str[insertAt] == '1'){
                ft.incr(insertAt, -1);
                str[insertAt] = '0';
            }

            // ft.incr()
        }

        else if(command == "C"){
            cin >> l >> r;
            cout << ft.rsq(l, r) << endl;
        }
    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    soln();
}