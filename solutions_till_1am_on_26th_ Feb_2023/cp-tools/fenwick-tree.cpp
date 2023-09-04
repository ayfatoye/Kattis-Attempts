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
