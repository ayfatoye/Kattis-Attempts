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
   int tests = 0;
   cin >> tests;
   int currSize = 0;
   int n = 0; int m = 0;
   int temp = 0;
   int result = 0;

   for(int i = 0; i < tests; i++){
        result = 0;
        cin >> n >> m;
        vector<vector<int>> vect(n);
        vector<int> prizes(n);

        for(int j = 0; j < n; j++){
            cin >> currSize;
            for(int k = 0; k < currSize; k++){
                cin >> temp;
                vect[j].push_back(temp);
            }
            cin >> temp;
            prizes[j] = temp;
        }

        // dbg(vect);
        // dbg(prizes);
        map<int, int> mapy;
        for(int j = 1; j <= m; j++){
            cin >> temp;
            mapy[j] = temp;
        }

        int min = INT32_MAX;
        int minP = 0;

        for(int j = 0; j < vect.size(); j++){
            min = INT32_MAX;
            for(int k = 0; k < vect[j].size(); k++){
                if(mapy[vect[j][k]] < min){
                    min = mapy[vect[j][k]];
                    // minP = vect[j][k];
                }
            }
            result += (min * prizes[j]);
        }
        // dbg(result);   
        cout << result << endl;     
   }
}
 
int main(){
    soln();
}