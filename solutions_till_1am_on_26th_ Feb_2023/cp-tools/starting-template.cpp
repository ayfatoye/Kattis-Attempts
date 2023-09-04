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

template <typename T> //printing out queues
std::ostream& operator<<(std::ostream& out, std::queue<T> q) {
    if(q.empty()) return out << "[]";
    out << '[';
    while(!q.empty()){out << q.front() << ", "; q.pop();}
    return out << ']';
}

// template <typename T> // printing a map of <string, set<string>>
void printMap(std::map<string,set<string>>& mapy){
    cerr << BLUE;
    for(auto item : mapy){
        cerr << item.first << " [";

        for(auto item2 : item.second){
            cerr << item2 << ", ";
        }
        cerr << "]" << endl;
    }
    cerr << NC;
}

void printMap(vector<unordered_map<int, int>> mapy)
{
    cerr << BLUE;
    for (int i = 0; i < mapy.size(); i++)
    {
        cout << i << ":\n";
        for (auto &stuff : mapy[i])
        {
            cerr << i << " -> " << stuff.first << "(" << stuff.second << ")\n";
        }
    }
    cerr << NC;
}