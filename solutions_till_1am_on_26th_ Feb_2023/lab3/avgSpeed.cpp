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
class unionFind {
    public:
    
    vector<int> vect;
    
    unionFind(int numOfNodes){
        for(int i = 0; i < numOfNodes; i++){
            vect.push_back(i);
        }
    }
    
    int find(int node){
        if(node == vect[node]){
            return node;
        }
        else {
            // int ans = find(vect[node]);
            // vect[node] = ans;
            // return ans;
            return vect[node] = find(vect[node]);
        }
    }
    
    void merge(int eleA, int eleB){
        int rootA = find(eleA);
        int rootB = find(eleB);
        vect[rootB] = rootA;
    }
    
};
 
void soln(){
   double totalDist = 0;
   double lastTimeChange = 0;
   double tempTime = 0; string h; string m; string s;

   double currSpeed = 0;
   string str = "";
   stringstream ss;

   /*
   - take input
    - if it has a space: 
        - find (time now - lastTimeChange) and use it to find
        distance covered using currSpeed
        - update totalDist
        - update currSpeed
        - update lastTimeChange


    - else:
        - find (time now - lastTimeChange) and use it to find
        distance covered using currSpeed
        
        
   */
  while(getline(cin, str)){
    ss.clear();
    if(str.find(" ") != string::npos){
        ss.str(str);
        getline(ss, h, ':');// ss >> h;
        getline(ss, m, ':');// ss >> m;
        getline(ss, s, ' ');// ss >> s;
        // dbg(h); dbg(m); dbg(s);
        tempTime = (stod(h) + (stod(m)/60.0) + (stod(s)/(3600.0)));
        // dbg(tempTime);
        // dbg(lastTimeChange);
        totalDist += ((tempTime - lastTimeChange) * (currSpeed));
        getline(ss, str, '\n'); currSpeed = stod(str);
        lastTimeChange = tempTime;
    }
    else{
        ss.str(str);
        getline(ss, h, ':');// ss >> h;
        getline(ss, m, ':');// ss >> m;
        getline(ss, s, ' ');// ss >> s;
        // dbg(h); dbg(m); dbg(s);
        tempTime = (stod(h) + (stod(m)/60.0) + (stod(s)/(3600.0)));
        cout << str << " " << fixed << setprecision(2) << (totalDist) + (tempTime - lastTimeChange) * (currSpeed) << " km\n";
    }
  }
//   dbg(totalDist);
}
 
int main(){
 soln();
}