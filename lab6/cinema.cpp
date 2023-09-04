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

   vector<vector<int>> vect(n, vector<int>(m, 0));

   int k = 0;
   cin >> k;

   int r = 0; int c = 0;

   for(int i = 0; i < k; i++){
        cin >> r >> c;
        vect.at(r-1).at(c-1) = 1;
   }

   vector<int> result(9, 0);
//    dbg(result);
   int currAdjs = 0;
   
//    dbg(vect);
    for(int r = 0; r < n; r++){

        for(int c = 0; c < m; c++){
            if(vect[r][c] == 0){continue;}
            currAdjs = 0;
            if(r-1 >= 0 && c-1 >= 0){
                if(vect[r-1][c-1] == 1){
                    currAdjs++;
                }
            }
            if(r-1 >=0){
                if(vect[r-1][c] == 1){
                    currAdjs++;
                }
            }
            if(r-1 >= 0 && c+1 < m){
                if(vect[r-1][c+1] == 1){
                    currAdjs++;
                }
            }
            if(c-1 >= 0){
                if(vect[r][c-1] == 1){
                    currAdjs++;
                }
            }
            if(c+1 < m){
                if(vect[r][c+1] == 1){
                    currAdjs++;
                }
            }
            if(r+1 < n && c-1 >= 0){
                if(vect[r+1][c-1] == 1){
                    currAdjs++;
                }
            }
            if(r+1 < n){
                if(vect[r+1][c] == 1){
                    currAdjs++;
                }
            }
            if(r+1 < n && c+1 < m){
                if(vect[r+1][c+1] == 1){
                    currAdjs++;
                }
            }
            // dbg(currAdjs);
            result[currAdjs]++;
        }
        // result[currAdjs]++;
    }

    // dbg(currAdjs);
    // dbg(result);
    for(int i = 0; i < 9; i++){
        cout << result[i] << " ";
    }
    cout << endl;


}
 
int main(){
    soln();
}