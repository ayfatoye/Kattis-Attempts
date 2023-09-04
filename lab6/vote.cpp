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
   int t = 0;
   cin >> t;
   int n = 0;
   int currCount = 0;
   int currSum = 0;
   vector<int> vect;
   int candidateNum = 0;
//    auto max = 0;
   

   for(int i = 0; i < t; i++){
        cin >> n;
        currSum = 0;
        vect.clear();
        for(int j = 0; j < n; j++){
            cin >> currCount;
            currSum += currCount;
            vect.push_back(currCount);
        }
        auto max = max_element(vect.begin(), vect.end());
        if(count(vect.begin(), vect.end(), *max) > 1){
            cout << "no winner\n";
            continue;
        }
        auto itr = find(vect.begin(), vect.end(), *max);
        candidateNum = distance(vect.begin(), itr);
        candidateNum++;

        if(currSum/2 < *max){
            cout << "majority winner " << candidateNum << endl;
        }
        else{
            cout << "minority winner " << candidateNum << endl;
        }


   }
}
 
int main(){
    soln();
}