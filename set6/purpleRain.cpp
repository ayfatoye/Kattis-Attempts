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
   string str = "";
   cin >> str;

   vector<int> vect;
   vector<int> vect2;
   
   int l1 = 0; int l2 = 0; int r1 = 0; int r2 = 0; // l1, r1 is the range of the largest sum when B = 1 and R = -1, and l2, r2 is the range the other way

   for(int i = 0; i < str.length(); i++){
        if(str[i] == 'B'){
            vect.push_back(1);
        }
        else{vect.push_back(-1);}
   }

   int l_max = vect.at(0);
   int g_max = vect.at(0); 

   for(int i = 1; i < vect.size(); i++){
        if(vect.at(i) > l_max + vect.at(i)){
            l_max = vect.at(i);
            if(l_max > g_max){
                g_max = l_max;
                
            } 
            l1 = i;
            r1 = i;           
        }
        else{
            l_max += vect.at(i);
            if(l_max > g_max){
                g_max = l_max;
                r1 = i;
            }
        }
   }

    

   for(int i = 0; i < str.length(); i++){
        if(str[i] == 'B'){
            vect2.push_back(-1);
        }
        else{vect2.push_back(1);}
   }

   int g_max2 = vect2.at(0);
   l_max = vect2.at(0);
   for(int i = 1; i < vect2.size(); i++){
        if(vect2.at(i) > l_max + vect2.at(i)){
            l_max = vect2.at(i);
            if(l_max > g_max2){
                g_max2 = l_max;
                
            }   
            l2 = i;
            r2 = i;         
        }
        else{
            l_max += vect2.at(i);
            if(l_max > g_max2){
                g_max2 = l_max;
                r2 = i;
            }
        }
   }

   if(g_max2 > g_max){
        cout << l2 + 1 << " " << r2 + 1<< endl;
   }
   else if(g_max > g_max2){
        cout << l1 + 1 << " " << r1 + 1 << endl;
   }
   else{
        if(l1 < l2){
            cout << l1 + 1 << " " << r1 + 1 << endl;
        }
        else if(l2 < l1){
            cout << l2 + 1 << " " << r2 + 1 << endl;
        }
        else{
            if(r1 < r2){
                cout << l1 + 1 << " " << r1 + 1 << endl;
            }
            else {
                cout << l2 + 1 << " " << r2 + 1 << endl;
            }
        }
   }

}
 
int main(){
    soln();
}