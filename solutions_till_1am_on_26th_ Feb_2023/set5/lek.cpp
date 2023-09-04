#include <bits/stdc++.h>
using namespace std;

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define WHITE   "\033[1;37m"
#define NC      "\033[0m"
#define dbg(x) cerr<< GREEN <<#x<<" = "<<x<< NC << endl
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
   string original = str;
   string str2 = "";

   string min(str.length(), 'z');
//    dbg(min);

   string a = "";
   string b = "";
   string c = "";

   for(ll i = 1; i < str.length()-1; i++){
        // a = str.substr(0, i);
        str = original;
        for(ll j = i+1; j < str.length(); j++){
            str = original;
            // str2 = "";
            // b = str.substr(i, (j - i));
            // c = str.substr(j, (str.length() - j));

            reverse(str.begin(), str.begin()+i);
            reverse(str.begin()+i, str.begin()+j);
            reverse(str.begin()+j, str.end());

            // str2 = a+b+c;

            // if(str2 < min){
            //     min = str2;
            // }

            // str2 = a+b+c;

            if(str < min){
                min = str;
            }

        }
   }

    cout << min << endl;

}
 
int main(){
    soln();
}