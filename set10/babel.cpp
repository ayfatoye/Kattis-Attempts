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

stack<string> s;
map<string, int> low;
map<string, int> node;
map<string, string> state;
int nextNode = 1;
int big = INT32_MIN;

map<string, set<string>> actualMap;
map<string, set<string>> understands;
map<string, set<string>> speaks;


int dfs(string person){
    s.push(person);
    node[person] = nextNode;
    low[person] = nextNode;
    nextNode++;
    state[person] = "e";

    for(auto& otherPer : actualMap[person]){
        if(state[otherPer] == "u"){
            low[person] = min(low[person], dfs(otherPer));
        }
        else{
            low[person] = min(low[person], node[otherPer]);
        }
    }

    if(low[person] == node[person]){
        string temp = " "; int count = 0;
        while(!s.empty() && temp != person){
            temp = s.top();
            count++;
            state[temp] = "u";
            s.pop();
        }
        // dbg(count);
        // cout << "big before: " << big << endl;
        big = max(big, count);
        // cout << "big output: " << big << endl;

    }

    return low[person];
}
 
void soln(){
    int num = 0;
    cin >> num;
    

    string person = ""; string langSpoken = "";
    string theRest = ""; string moGbo = "";
    
    // completely building speaks and understands
    for(int i = 0; i < num; i++){
        cin >> person >> langSpoken;
        node[person] = 0;
        low[person] = 0;
        state[person] = "u";

        speaks[langSpoken].insert(person);
        
        getline(cin, theRest);
        stringstream ss(theRest);

        while(ss >> moGbo){
            if(moGbo == "")
                break;
            understands[moGbo].insert(person);
        }
    }

    // for each pair of lang and set of people that speak it
    for(auto& pair : speaks){

        // for each person in the set of people that speak current language
        for(string currPerson : pair.second){

            for(string toThisPerson : understands[pair.first]){
                actualMap[currPerson].insert(toThisPerson);
            }

            for(string toThisPerson : pair.second){
                if(currPerson != toThisPerson){
                    actualMap[currPerson].insert(toThisPerson);
                }
            }

        }
    }
    int result = INT32_MIN;
    // printMap(actualMap);

    for(auto pair : actualMap){

        if(state[pair.first] == "u"){
            result = dfs(pair.first);
        }
        
    }

    result = num - big;
    cout << result << endl;






}
 
int main(){
    soln();
}