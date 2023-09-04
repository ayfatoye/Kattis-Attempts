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

/*
readin -> n
for loop through n:
    readin -> l and antNum
    mid2 -> -1
    mid -> -1
    
    for loop through antNum
        put each position into vect<int>
    end for

    sort vect

    if antNum is odd:
        mid -> vect at antNum/2
        shortTime = vect at (mid or l - mid) depending on which is shorter
        push the following into the maxPQ:
            // vect at 0
            l - vect at 0
            vect at n-1
            // l - vect at n - 1


    else :
        mid -> vect at antNum/2 - 1
        mid2 -> vect at antNum/2
*/

/*
revised strat:



find the ant (or 2) closest to the mid point on the rope
then the shortest time will be the time it takes said ant to get of the rope

*/
 
void soln(){
    int n = 0;
    cin >> n;
    int l = 0;
    int antNum = 0;
    int mid = 0;
    vector<int> vect;
    int shortTime = 0;
    int longTime = 0;
    int minDiff = INT32_MAX;
    float diff = 0.0;


    while(n--){
        cin >> l >> antNum;
        minDiff = INT32_MAX;
        mid = -1;
        vect.resize(antNum);

        for(int i = 0; i < antNum; i++){
            cin >> vect[i];
            diff = abs(vect[i] - static_cast<float>(l)/2);
            if(diff < minDiff){
                minDiff = diff;
                mid = vect[i];
            }
            // dbg(mid);
        }
        shortTime = (mid < (l - mid)) ? mid : l - mid;
        sort(vect.begin(), vect.end());
        longTime = (vect[antNum-1] > (l - vect[0])) ? vect[antNum - 1] : l - vect[0];
        // cout << RED << shortTime << " " << longTime << NC <<  endl;
        cout << shortTime << " " << longTime <<  endl;

    }
}
 
int main(){
    soln();
}