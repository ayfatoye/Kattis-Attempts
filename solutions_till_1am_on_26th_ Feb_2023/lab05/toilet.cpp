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
   string str = "";
   cin >> str;
   ll p1 = 0;
   ll p2 = 0;
   ll p3 = 0;
   bool u_up = true;


   if(str[0] == 'U'){u_up = true;}
   else if(str[0] == 'D'){u_up = false;}

   for(int i = 1; i < str.length(); i++){

        if(str[i] == 'U'){
            if(u_up){
                continue;
            }
            else{
                p1++; 
                u_up = true;
            }
        }
        else if(str[i] == 'D'){
            if(u_up){
                p1 += 2;
            }
            else{
                p1++; 
                u_up = true;
            }
        }
   }
   // POLICY 2: aaand stay DOWN!!
   if(str[0] == 'U'){u_up = true;}
   else if(str[0] == 'D'){u_up = false;}

   for(int i = 1; i < str.length(); i++){

        if(str[i] == 'U'){
            if(u_up){
                p2++;
                u_up = false;
            }
            else{
                p2 += 2; 
                // u_up = false;
            }
        }
        else if(str[i] == 'D'){
            if(u_up){
                p2 += 1;
                u_up = false;
            }
            else{
                continue;
            }
        }
   }

   // POLICY 3: the golden rule for the golden shower
   if(str[0] == 'U'){u_up = true;}
   else if(str[0] == 'D'){u_up = false;}

   for(int i = 1; i < str.length(); i++){

        if(str[i] == 'U'){
            if(u_up){
                continue;
            }
            else{
                p3++;
                u_up = true;
            }
        }
        else if(str[i] == 'D'){
            if(u_up){
                p3 += 1;
                u_up = false;
            }
            else{
                continue;
            }
        }
   }

   cout << p1 << endl << p2 << endl << p3 << endl;




}
 
int main(){
 soln();
}