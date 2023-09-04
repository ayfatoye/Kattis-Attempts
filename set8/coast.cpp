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

template <typename T>
std::ostream& operator<<(std::ostream& out, std::queue<T> q) {
    if(q.empty()) return out << "[]";
    out << '[';
    while(!q.empty()){out << q.front() << ", "; q.pop();}
    return out << ']';
}
 
void soln(){
    int n = 0;
    int m = 0;
    cin >> n >> m;
    vector<vector<int>> input((n+2), vector<int>(m+2));
    vector<vector<bool>> checked((n+2), vector<bool>(m+2));

    for(int j = 0; j < m + 2; j++){
        input[0][j] = 0;
        input[n+1][j] = 0;
    }

    string str = "";
    for(int i = 1; i < n + 1; i++){
        cin >> str;
        input[i][0] = 0;
        input[i][m+1] = 0;

        for(int j = 1; j < m + 1; j++){
            input[i][j] = stoi(string(1, str[j-1]));
        }
    }

    queue<pair<int,int>> q;
    q.push({0, 0});
    checked[0][0] = true;

    pair<int, int> temp;
    int length = 0;
    int z = 0; //int sea = 0;
    
    while(!q.empty()){
        // dbg(q);
        // z++;
        temp = q.front(); q.pop();
        // dbg(q);

        if(temp.first - 1 >= 0){ // top
            if(input[temp.first-1][temp.second] == 0){
                if(checked[temp.first-1][temp.second] == false){
                    q.push({temp.first - 1, temp.second}); //sea++;
                    // cout << "line 72\n";dbg(q);
                    checked[temp.first-1][temp.second] = true;
                }
            }
            else{
                // if(checked[temp.first-1][temp.second] == false){
                //     length++;
                //     checked[temp.first-1][temp.second] = true;
                // }
                length++;
            }
        }

        if(temp.first + 1 < n+2){ // below
            if(input[temp.first+1][temp.second] == 0){
                if(checked[temp.first+1][temp.second] == false){
                    q.push({temp.first + 1, temp.second}); //sea++;
                    //cout << "line 88\n"; dbg(q);
                    checked[temp.first+1][temp.second] = true;
                }
            }
            else{
                // if(checked[temp.first+1][temp.second] == false){
                //     length++;
                //     checked[temp.first+1][temp.second] = true;
                // }
                length++;
            }
        }

        if(temp.second - 1 >= 0){ // left
            if(input[temp.first][temp.second - 1] == 0){
                if(checked[temp.first][temp.second - 1] == false){
                    q.push({temp.first, temp.second-1}); //sea++;
                    //cout << "line 104\n";dbg(q);
                    checked[temp.first][temp.second-1] = true;
                }
            }
            else{
                // if(checked[temp.first][temp.second-1] == false){
                //     length++;
                //     checked[temp.first][temp.second-1] = true;
                // }
                length++;
            }
        }

        if(temp.second + 1 < m + 2){ // the right
            if(input[temp.first][temp.second + 1] == 0){
                if(checked[temp.first][temp.second + 1] == false){
                    q.push({temp.first, temp.second+1}); //sea++;
                    // cout << "line 120\n";dbg(q);
                    checked[temp.first][temp.second+1] = true;
                }
            }
            else{
                // if(checked[temp.first][temp.second+1] == false){
                //     length++;
                //     checked[temp.first][temp.second+1] = true;
                // }
                length++;
            }
        }


    }

    // cout << RED << length << NC << endl; dbg(sea);
    cout << length << endl;


}
 
int main(){
    soln();
}