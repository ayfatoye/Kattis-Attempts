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
   int n = 0; int m = 0;
   cin >> n >> m;
   vector<vector<int>> vect(n + 1);
   vector<bool> checked(n + 1);
   int a = 0; int b = 0;

   for(int i = 0; i < m; i++){
        cin >> a >> b;
        vect[a].push_back(b);
        vect[b].push_back(a);
   }
//    dbg(vect);
   map<int, int> depth;

   queue<int> q;
   q.push(1);

   depth[1] = 0;
   int currDepth = 1;
//    checked[1] = true;

   int currNode = 0;
   while(!q.empty()){
        currNode = q.front();
        q.pop();

        for(int i = 0; i < vect[currNode].size(); i++){
            if(checked[vect[currNode][i]] == false){
                q.push(vect[currNode][i]);
                checked[vect[currNode][i]] = true;
                depth[vect[currNode][i]] = depth[currNode] + 1;
            }
        }
   }

//    cout << RED << depth[n] - 1 << NC << endl;
      cout << depth[n] - 1 << endl;

}
 
int main(){
    soln();
}