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
   int n = 0; 
   cin >> n;
   vector<int> days(n);
   ll currM = 100;
   ll currS = 0;
   ll most = 100;

   for(int i = 0; i < n; i++){
        cin >> days[i];
   }
//    dbg(days);

   for(int i = 0; i < n-1; i++){
        if(currM >= days[i] && currS < 100000LL){
            currS = min(100000LL, currM/days[i]);
            currM -= currS * days[i];
        }
        if(days[i+1] < days[i]){
            currM += days[i] * currS;
            currS = 0;
        }
        most = max(most, currM);
   }

   cout << (max(most, currM + days[n-1] * currS)) << endl;
}
 
int main(){
    soln();
}