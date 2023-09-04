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
 
void soln(){
    string num = "";
    getline(cin, num);
    int n = stoi(num);
    stringstream ss;
    string str = "";
    set<int> daSet;
    int curr = 0;
    map<set<int>, int> mapy;
    int max = 1;
    int finMax = 0;


    while(getline(cin, str) && (str != "fin")){
        ss.clear();
        ss.str(str);
        daSet.clear();
        //500,000,000
        for(int i = 0; i < 5; i++){
            ss >> curr;
            daSet.insert(curr);
        }
        // dbg(daSet);

        if(mapy.find(daSet) != mapy.end()){
            mapy[daSet]++;
            if(mapy[daSet] > max){
                max = mapy[daSet];
            }
        }
        else{
            mapy.insert({daSet, 1});
        }

    }
    if(mapy.size() == n){
        cout << n << "\n";
    }
    else{
        for(const auto& ele : mapy){
            if(ele.second == max){
                finMax += max;
            }
        }
        dbg(finMax);
        if(finMax > max){
            cout << finMax << "\n";
        }
        else{
            cout << max << "\n";
        }
        
    }
    

    // int n = 0;
    // cin >> n;

    // for(int i = 0; i < (n*5); i++){

    // }
}
 
int main(){
    soln();
}