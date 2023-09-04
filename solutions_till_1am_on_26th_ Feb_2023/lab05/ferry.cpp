#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define WHITE   "\033[1;37m"
#define NC      "\033[0m"
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
   int c = 0;
   cin >> c;

   int l = 0;
   int m = 0;
   int currCap = 0;
   int totalCrosses = 0;

   int a = 0; 
   string b = "";
   string currBank = "l";

//    priority_queue<int, vector<int>, greater<int>> left;
//    priority_queue<int, vector<int>, greater<int>> right;
    queue<int> left;
    queue<int> right;
   

   

   for(int i = 0; i < c; i++){
    cin >> l; l *= 100;
    cin >> m;
    currBank = "l";

        for(int j = 0; j < m; j++){
            cin >> a >> b;
            totalCrosses = 0;
            if(b == "left"){
                left.push(a);
            }
            else if(b == "right"){
                right.push(a);
            }
        }

        // int yo = 0;

        while((!left.empty() || !right.empty())){
            currCap = 0; // offloading the ferry
            // cout << "loop \n";

            if(currBank == "l"){
                // cerr << BLUE << "hits right\n";
                if(!left.empty()){
                    // dbg(currCap); dbg(left.front()); dbg(l);
                    while(!left.empty() && currCap + left.front() <= l){
                        // cerr << YELLOW << "in while: \n";
                        // dbg(currCap); dbg(left.front()); dbg(l);
                        currCap += left.front();
                        left.pop();
                        // cerr << RED << "in while after: \n";
                        // dbg(currCap); dbg(left.front()); dbg(l);
                        // cerr << NC;
                    }
                
                // currCap = 0;
                 }
                 totalCrosses++;
                currBank = "r";
            }

            else if(currBank == "r"){
                // cerr << BLUE << "hits right\n";
                if(!right.empty()){
                    while(!right.empty() && currCap + right.front() <= l){
                        currCap += right.front();
                        right.pop();
                    }
                
                // currCap = 0;
                 }
                totalCrosses++;
                currBank = "l";
            }

            // yo++;
            
            
        }

        // cout << BLUE << totalCrosses << NC << endl;
        cout << totalCrosses << endl;




        
   }


}
 
int main(){
 soln();
}
