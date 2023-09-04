#include <bits/stdc++.h>
using namespace std;
#define dbg(x) //cerr<<#x<<" = "<<x<<endl
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
 
class unionFind {
    public:

    vector<int> vect;
    vector<int> maxSize; // should be called maxheight, it tells you the height of the mini-tree

    unionFind(int numOfNodes){
        for(int i = 0; i < numOfNodes; i++){
            vect.push_back(i);
            maxSize.push_back(1);
        }
    }

    int find(int node){
        // dbg(node);
        // dbg(vect[node]);
        if(node == vect[node]){
            //cerr << YELLOW << "this sucks\n"; 
            return node;
        }
        else {
            //cerr << YELLOW << "this sucks2\n";
            int ans = find(vect[node]);
            vect[node] = ans;
            return ans;
        }
    }

    void merge(int eleA, int eleB){
        //cerr << RED << "sam is v awesome\n";
        // dbg(eleA);
        int rootA = find(eleA); // root of the set eleA belongs to
        // approach is to merge the set eleB is a part of into eleA's set
        //cerr << RED << "sam is v awesome2\n";
        int rootB = find(eleB);
        if(rootA == rootB) {return;}

        if(maxSize[rootA] == maxSize[rootB]){
            vect[rootB] = rootA;
            maxSize[rootA]++;
        }
        else if(maxSize[rootA] > maxSize[rootB]){
            vect[rootB] = rootA;
        }
        else{
            vect[rootA] = rootB;
        }
        
    }

}; 
 
void soln(){
    /*
    - only thing I can think of is: O(n^2)
    - make a union-find ds
        - double loop through:
            - if the current cell is #:
                - check all it's adjacent nodes
                    // - check if the current node is in a set:
                    - if num of # is exactly 2: 
                        - add curr node to a new set
                        - then check if curr node is in a set, then merge those two sets into one:
                            - else do nothing and continue the loop
        
        - end loop

        then return the number of sets in the union-find
                    

    */  
   vector<string> vectStr;
   int m = 0; int n = 0;
   string str = "";
   int curr = 0;
   cin >> m >> n;
   unionFind uf(m*n);

   

   vectStr.resize(m);

   for(int i = 0; i < m; i++){
        cin >> str;
        vectStr[i] = str;
   }

   for(int i = 0; i < m; i++){

        for(int j = 0; j < n; j++){

            // //cerr << RED << "here bitch" << endl;
            if(j - 1 >= 0){
                if(vectStr[i][j-1] == '#'){
                    uf.merge(curr, curr-1);
                }
              
            }

            //cerr << RED << "fuck my life" << endl;

            if(j + 1 < n){
                if(vectStr[i][j+1] == '#'){
                    // dbg(curr);
                    // dbg(curr+1);
                   uf.merge(curr, curr+1);
                }
                
            }

            //cerr << RED << "here 1" << endl;

            if(i - 1 >= 0){
                if(vectStr[i-1][j] == '#'){
                    uf.merge(curr, curr-n);
                }
                
            }

            if(i + 1 < m){
                if(vectStr[i+1][j] == '#'){
                    uf.merge(curr, curr+n);
                }
                
            }

            if((i-1 >= 0) && (j-1 >= 0)){
                if(vectStr[i-1][j-1] == '#'){
                    uf.merge(curr, (curr-n-1));
                }
                
            }

            if((i-1 >= 0) && (j+1 < n)){
                if(vectStr[i-1][j+1] == '#'){
                    uf.merge(curr, (curr-n+1));
                }
                
            }

            if((i+1 < m) && (j-1 >= 0)){
                if(vectStr[i+1][j-1] == '#'){
                    uf.merge(curr, (curr+n-1));
                }
                
            }

            if((i+1 < m) && (j+1 < n)){
                if(vectStr[i+1][j+1] == '#'){
                    uf.merge(curr, (curr + n + 1));
                }
                
            }
        }

        curr++;
   }
   cerr << YELLOW << "sam so smart\n";

   int result = 0;

   for(int i = 0; i < uf.vect.size(); i++){
        if(uf.vect[i] == i){
            result++;
        }
   }
   cerr << YELLOW << "sam so smart2\n";

   cerr << RED << result << endl;
   
}
 
int main(){
    soln();
}