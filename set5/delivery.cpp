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
   vector<pair<int, int>> posVect;
   vector<pair<int, int>> negVect;

   int n = 0; int k = 0;

   cin >> n >> k;

   int addy = 0; int numMail = 0;

   int z = 0;

   while(z < n){
        cin >> addy >> numMail;

        if(addy >= 0){
            posVect.push_back({addy, numMail});
        }
        else{
            negVect.push_back({abs(addy), numMail});
        }
        z++;
   }

   sort(posVect.begin(), posVect.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second > b.second;
        } else {
            return a.first > b.first;
        }
    }); 
   sort(negVect.begin(), negVect.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second > b.second;
        } else {
            return a.first > b.first;
        }
    });

//    dbg(posVect); dbg(negVect);

//    int dist = 0; int leftOver = 0;
//    int dropped = 0; 
//    int numTrips = 0;

//    for(int i = 0; i < posVect.size(); i++){
//         dropped = (leftOver < posVect[i].second) ? leftOver : posVect[i].second;
//         posVect[i].second -= dropped;
//         leftOver -= dropped;
        
//         if(posVect[i].second > 0){
//             if(posVect[i].second % k == 0){
//                 numTrips = posVect[i].second / k;
//             }
//             else if(posVect[i].second % k != 0){
//                 numTrips = posVect[i].second / k + 1;
//                 leftOver += (k - posVect[i].second % k);
//             }

//             dist += (numTrips * 2 * posVect[i].first);
//         }

        
//    }
   
// //    dist = 0;
//    leftOver = 0;
//    dropped = 0; numTrips = 0;

//    for(int i = 0; i < negVect.size(); i++){
//         dropped = (leftOver < negVect[i].second) ? leftOver : negVect[i].second;
//         negVect[i].second -= dropped;
//         leftOver -= dropped;
        
//         if(negVect[i].second > 0){
//             if(negVect[i].second % k == 0){
//                 numTrips = negVect[i].second / k;
//             }
//             else if(negVect[i].second % k != 0){
//                 numTrips = negVect[i].second / k + 1;
//                 leftOver += (k - negVect[i].second % k);
//             }

//             dist += (numTrips * 2 * negVect[i].first);
//         }

        
//    }
    int dist = 0; int leftOver = 0;
    int dropped = 0; 
    // int numTrips = 0;

    for(int i = 0; i < posVect.size(); i++){
        dropped = min(leftOver, posVect[i].second);
        // dropped = (leftOver < posVect[i].second) ? leftOver : posVect[i].second;
        posVect[i].second -= dropped;
        leftOver -= dropped;

        if(posVect[i].second > 0){
            int numTrips = posVect[i].second / k;

            if(posVect[i].second % k > 0){
                leftOver += (k - posVect[i].second % k);
                numTrips++;
            }

            dist += numTrips * posVect[i].first * 2;
            // dbg(dist);
        }
    }
    int temp = dist;

    dist = 0;
    leftOver = 0;
    dropped = 0;
    // numTrips = 0;

    for(int i = 0; i < negVect.size(); i++){
        dropped = min(leftOver, negVect[i].second);
        // dropped = (leftOver < negVect[i].second) ? leftOver : negVect[i].second;
        negVect[i].second -= dropped;
        leftOver -= dropped;

        if(negVect[i].second > 0){
            int numTrips = negVect[i].second / k;

            if(negVect[i].second % k > 0){
                leftOver += (k - negVect[i].second % k);
                numTrips++;
            }

            dist += numTrips * negVect[i].first * 2;
            // dbg(dist);
        }
    }

    dist += temp;




//    cerr << YELLOW << dist << NC << endl;
    cout << dist << endl;


}
 
int main(){
    soln();
}