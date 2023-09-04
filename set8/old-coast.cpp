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
/*
currSquare is the square bfs is called on in soln(), where bfs starts
*/
int bfs(pair<int, int> currSquare, vector<vector<int>>& input, vector<vector<bool>>& checked){
    int lengthOfIsland = 4; // first square by itself will have 4 sides
    dbg(input);
    dbg(checked);
    if(checked[currSquare.first][currSquare.second] == true){return 0;}
    else{
        queue<pair<int,int>> q;
        q.push({currSquare.first, currSquare.second});
        checked[currSquare.first][currSquare.second] = true;
        pair<int, int> temp;

        while(!q.empty()){
            temp = q.front(); q.pop();
            dbg(temp);
            // since in soln() i'm going from left to right and top to bottom,
            //      i shouldn't have to check the top and left.
            if(temp.second + 1 < input[0].size()){ // checking square to the right
                if(input[temp.first][temp.second + 1] == 1){
                    q.push({temp.first, temp.second + 1});
                    checked[temp.first][ temp.second + 1] = true;
                    lengthOfIsland--;
                    lengthOfIsland += 3;
                }
            }
            if(temp.first + 1 < input.size()){
                if(input[temp.first + 1][temp.second] == 1){
                    q.push({temp.first + 1, temp.second});
                    checked[temp.first + 1][ temp.second] = true;
                    lengthOfIsland--;
                    lengthOfIsland += 3;
                }
            }
        }
    }
    return lengthOfIsland;
}

void soln(){
   int n = 0; int m = 0;
   cin >> n >> m;
   int numOfNodes = n * m;
   vector<vector<int>> input(n, vector<int>(m));
   vector<vector<bool>> checked(n, vector<bool>(m));

   int lengthOfCoast = 0;
   
   for(int i = 0; i < n; i++){

        for(int j = 0; j < m; j++){
            cin >> input[i][j];
        }
   }
   

   for(int i = 0; i < n; i++){

        for(int j = 0; j < m; j++){
            if(input[i][j] == 1){
                lengthOfCoast += bfs({i, j}, input, checked);
            }
        }
   }

   cout << BLUE << lengthOfCoast << NC << endl;
   
}
 
int main(){
    soln();
}