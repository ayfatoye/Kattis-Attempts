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
   int m = 0;
   cin >> n >> m;

   int a = 0; int b = 0;

   vector<vector<int>> vect(n+1);

   map<int, int> mapy;

   for(int i = 1; i <= n; i++){
        mapy[i] = 0;
   }

   for(int i = 0; i < m; i++){
        cin >> a >> b;
        vect[a].push_back(b);
        mapy[b]++;
   }
//    dbg(vect);

   queue<int> q;

   for(int i = 1; i <= n; i++){
        if(mapy[i] == 0){
            q.push(i);
        }
   }

   int temp = 0;

   vector<int> result;

   while(!q.empty()){
        temp = q.front();
        result.push_back(temp);
        // cout << temp << endl;
        q.pop();
        for(int i = 0; i < vect[temp].size(); i++){
            mapy[vect[temp][i]]--;
            if(mapy[vect[temp][i]] == 0){
                q.push(vect[temp][i]);
            }
        }
   }

   if(result.size() != n){
        cout << "IMPOSSIBLE" << endl;
   }
   else{
        for(int i : result)
            cout << i << endl;
   }


}
 
int main(){
    soln();
}