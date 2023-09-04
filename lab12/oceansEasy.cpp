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

string intToBinaryString(int n)
{
    string binaryString = "";

    for (int i = 3; i >= 0; i--)
    {
        if (n & (1 << i))
        {
            binaryString += "1";
        }
        else
        {
            binaryString += "0";
        }
    }

    return binaryString;
}
 
void soln(){
    int t = 0;
    cin >> t;
    int n = 0;

    vector<int> vect;
    for(int i = 0; i < t; i++){
        vect.clear();
        cin >> n;
        vect.resize(n);

        if(n == 1){
            cout << 2 << endl;
            continue;
        }
        else if(n == 2){
            cout << 3 << endl;
            continue;
        }
        vect[0] = 2;
        vect[1] = 3;

        for(int j = 2; j < n; j++){
            vect[j] = ((vect[j - 1] + vect[j - 2]) % 1000000007);
        }

        cout << vect.back() << endl;
    }
    
}
 
int main(){
    soln();
 
}