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
   

   int n = 0;
   int s = 0;
   string output = "";

   int result = 0;

   int currR = 0; int currB = 0;

   string str = ""; string justTheNums = "";
   cin >> n;

   for(int i = 0; i < n; i++){
        cin >> s;
        result = 0;
        output = "Case #";
        priority_queue<int> red;
        priority_queue<int> blue;

        for(int j = 0; j < s; j++){
            cin >> str;
            justTheNums = "";

            copy_if(str.begin(), str.end(), std::back_inserter(justTheNums), [](char c) {
                return std::isdigit(c);
            });

            if(str[str.length()-1] == 'R'){
                red.push(stoi(justTheNums));
            }
            else if(str[str.length()-1] == 'B'){
                blue.push(stoi(justTheNums));
            }


        }

        // if(red.empty() || blue.empty()){cerr << YELLOW << 0 << endl;}
        if(red.empty() || blue.empty()){cout << "Case #" << (i+1) << ": " << 0 << endl; continue;}

        while(!red.empty() && !blue.empty()){
            currR = red.top(); 
            red.pop();
            currB = blue.top(); 
            blue.pop();
            // dbg(currR);
            // dbg(currB);
            result += (currR + currB - 2);
            // dbg(result);
        }

        // result--;
        output += to_string((i+1));
        output += ": ";
        output += to_string(result);

        // cerr << YELLOW << output << endl;
        cout << output << endl;
        // cerr << YELLOW << result << endl;
        // // cerr << YELLOW << red.top() << endl;
        // cerr << YELLOW << blue.top() << endl;

   }
}
 
int main(){
    soln();
}