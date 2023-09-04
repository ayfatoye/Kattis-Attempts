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
   int a = 0; int b = 0; int c = 1; int d = -1; int temp = 0;
   cin >> a;
   for(int i = 0; i < a; i++){
        cin >> b;
        vector<vector<int>> vect(41, vector<int>(1001, -1));
        vector<int> vect2;
        vect2.resize(b+1);
        // --b;
        vector<vector<int>> vect3(41, vector<int>(1001, 0));
        

        for(int j = 1; j <= b; j++){
            cin >> temp;
            vect2.at(j) = temp;
        }
        vect.at(0).at(0) = 0;

        for(int j = 1; j <= b; j++){
            for(int k = 0; k <= 1000 - vect2.at(j); k++){
                d = k - vect2.at(j);
                c = k + vect2.at(j);
                if(d >= 0){
                    if(vect.at(j-1).at(d) != -1 && vect.at(j - 1).at(c) != -1){
                        int temp2 = vect.at(j-1).at(c); //int temp3 = 0;
                        vect.at(j).at(k) = min(max(k, vect.at(j-1).at(d)), temp2);
                        // vect3.at(j).at(k) = (max(k, vect.at(j-1).at(d)), temp2);
                        if(max(k, vect.at(j-1).at(d)) <= vect.at(j-1).at(c)){
                            vect3.at(j).at(k) = c;
                        }else {
                            vect3.at(j).at(k) = d;
                        }
                    }
                    else if(vect.at(j-1).at(c) != -1){
                        vect.at(j).at(k) = vect.at(j-1).at(c);
                        vect3.at(j).at(k) = d;
                    }
                    else if(vect.at(j-1).at(d) != -1){
                        vect.at(j).at(k) = max(k, vect.at(j-1).at(d));
                        vect3.at(j).at(k) = c;
                    }
                }
                else if(vect.at(j-1).at(c) != -1){
                    vect.at(j).at(k) = vect.at(j-1).at(c);
                    vect3.at(j).at(k) = d;
                }
            }
        }
        vector<int> result(b+1);
        // --b;
        int pushing = 0;

        for(int j = b; j >= 1; j--){
            result[j] = vect3.at(j).at(pushing);
            pushing = pushing - vect2.at(j)*vect3.at(j).at(pushing);
        }
        if(vect.at(b).at(0) != -1){
            for(int j = 1; j <= b; j++){
                
                if(result.at(j) == c){
                    cout << "U";
                }
                else{
                    cout << "D";
                }

            }
            cout << endl;
        }
        else{
            cout << "IMPOSSIBLE" << endl;
        }


   }

}
 
int main(){
    soln();
}