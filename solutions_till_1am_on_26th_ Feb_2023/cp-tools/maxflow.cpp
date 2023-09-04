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

// MAXFLOW starts here:
vector<unordered_map<int, int>> vect;
vector<int> parent;
vector<bool> visited;
vector<int> flows;
int result = 0;

void readjustEdges(int upFlow){
    int curr = 1;
    

    while(curr != 0){
        vect[curr][parent[curr]] += upFlow;
        vect[parent[curr]][curr] -= upFlow;
        curr = parent[curr];
        // parent = parent[curr];
    }

}
 
int maxFlow(vector<unordered_map<int, int>>& vect){
    // building graph
    int e = 0;
    int n = 0;
    cin >> n >> e;
    int from = 0; int to = 0; int flow = 0;
    vect.resize(n);
    parent.resize(n);
    visited.resize(n);
    flows.resize(n);
    bool sinkFound = true;

    while(e--){
        cin >> from >> to >> flow;
        vect[from][to] = flow;
        vect[to][from] = 0;
    }

    int curr = 0; // item just popped in bfs while loop

    // actual maxFlow algorithm
    while(sinkFound){
        sinkFound = false;
        parent.clear(); parent.resize(n);
        visited.clear(); visited.resize(n);
        flows.clear(); flows.resize(n);

        queue<int> q;
        q.push(0);
        parent[0] = -1; 
        flows[0] = INT_MAX;
        visited[0] = true;


        while(!q.empty() && !sinkFound){
            curr = q.front();
            q.pop();

            for(auto& pair : vect[curr]){
                if(visited[pair.first] == false){
                    // visited[pair.first] = true;

                    if(pair.second != 0){
                        q.push(pair.first);
                        parent[pair.first] = curr;
                        flows[pair.first] = min(pair.second, flows[curr]);
                        visited[pair.first] = true;

                        if(pair.first == 1){
                            sinkFound = true;
                        }
                    }
                }
            }
        }

        if(sinkFound){
            result += flows[1];

            readjustEdges(flows[1]);
        }
        else{
            break;
        }

    }

    // dbg(result);
    return result;
    
}

int main(){
    cout << maxFlow(vect) << endl;
}