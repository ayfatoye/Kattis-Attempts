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
   int n = 0; int _count = 0;
   cin >> n;
   string str = "";
   string temp = "";
   
   for(int i = 0; i < n; i++){
        cin >> temp;
        str += temp;
   }
//    dbg(str);
   reverse(str.begin(), str.end());
   ll bellCount = 0;

   for(ll i = 0; i < str.length(); i++){
        if(str[i] == 'O'){
            bellCount += 1ll << i;
        }
   }




   cout << bellCount << endl;
   
}
 
int main(){
    soln();
}