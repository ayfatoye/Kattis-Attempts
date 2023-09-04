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

int compareGrids(pair<pair<int, int>, pair<int, int>> leftRect, pair<pair<int, int>, pair<int, int>> rightRect){
    // if they overlap: 
    bool overLap = false;
    pair<pair<int, int>, pair<int, int>> _leftRect;
    pair<pair<int, int>, pair<int, int>> _rightRect;

    if(leftRect.first.first < rightRect.first.first)
    // if(rightRect.first.first < leftRect.second.first && rightRect.first.second < leftRect.second.second && rightRect.second.first > leftRect.first.first && rightRect.second.second > leftRect.first.second){
    //     overLap = true;
    // }
    // else if(leftRect.first.first < rightRect.second.first && leftRect.first.second < rightRect.second.second && leftRect.second.first > rightRect.first.first && leftRect.second.second > rightRect.first.second){
    //     overLap = true;
    // }
    if(rightRect.first.first < leftRect.second.first && rightRect.first.second < leftRect.second.second && rightRect.second.first > leftRect.first.first && rightRect.second.second > leftRect.first.second){
        overLap = true;
    }
    else if(leftRect.first.first < rightRect.second.first && leftRect.first.second < rightRect.second.second && leftRect.second.first > rightRect.first.first && leftRect.second.second > rightRect.first.second){
        overLap = true;
    }

    if(overLap){

    }
}

void soln(){


    // before 
   
}
 
int main(){
 
}