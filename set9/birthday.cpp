#include <bits/stdc++.h>
using namespace std;
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define WHITE "\033[1;37m"
#define NC "\033[0m"
#define dbg(x) cerr << RED << #x << " = " << x << NC << endl
typedef long long ll;
template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &out, const std::pair<T1, T2> &pair)
{
    return out << '(' << pair.first << ", " << pair.second << ')';
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vec)
{
    if (vec.empty())
        return out << "[]";
    out << '[';
    for (size_t i = 0; i < vec.size() - 1; i++)
        out << vec.at(i) << ", ";
    return out << vec.back() << ']';
}

bool bridgeFS(vector<vector<int>>& vect, vector<int>& lowNum, vector<int>& nodeNum){
    for(int i = 0; i < vect.size(); i++){
        for(int j = 0; j < vect[i].size(); j++){
            if(lowNum[i] > nodeNum[vect[i][j]]){
                return true;
            }
            else if(lowNum[vect[i][j]] > nodeNum[i]){
                return true;
            }
        }
    }
    return false;
}
int counter = 0;

int dfs(vector<vector<int>>& vect, vector<int>& lowNum, vector<int>& nodeNum, int& nextNode, int currNode, vector<bool>& visited, int parent){
    visited[currNode] = true;
    nodeNum[currNode] = nextNode;
    lowNum[currNode] = nextNode;
    nextNode++;
    counter++;

    

    for(int i = 0; i < vect[currNode].size(); i++){
        if(vect[currNode][i] == parent){
            continue;
        }
        if(!visited[vect[currNode][i]]){
            // parent[vect[currNode][i]] = currNode;
            int low = dfs(vect, lowNum, nodeNum, nextNode, vect[currNode][i], visited, currNode);
            if (low < lowNum[currNode]){
                lowNum[currNode] = low;
            }
        }
        else{            
                if(nodeNum[vect[currNode][i]] < lowNum[currNode]){
                    lowNum[currNode] = lowNum[vect[currNode][i]];
                    // low = lowNum[currNode];
                }
            
        }
        
    }

    return lowNum[currNode];
}

void soln()
{
    int n = 0;
    int e = 0;
    cin >> n >> e;
    int a = 0;
    int b = 0;
    vector<vector<int>> vect(n);
    int nextNode = 0; // we assign this at each step of dfs to the actual nodes
    int currNode = 0; // the node we're currently performing dfs on
    int shouldBeZero = 0;
    int bridgeExists = false;

    vector<int> lowNum(n); vector<int> nodeNum(n); // nodeNum stores the dfs nextNodes for each actual node
    vector<bool> visited(n);
    // vector<int> parent(n);


    while (n != 0)
    {
        if(e == 0){cout << "No\n"; continue;}
        lowNum.clear();
        lowNum.resize(n);
        nodeNum.clear();
        nodeNum.resize(n);
        nextNode = 0;
        visited.clear();
        visited.resize(n);
        vect.clear();
        vect.resize(n);
        // bridgeExists = false;
        // parent.clear();

        for (int i = 0; i < e; i++)
        {
            cin >> a >> b;
            vect[a].push_back(b);
            vect[b].push_back(a);
        }
        counter = 0;        
        shouldBeZero = dfs(vect, lowNum, nodeNum, nextNode, 0, visited, -1);

        if(counter == n){
            bridgeExists = bridgeFS(vect, lowNum, nodeNum);

            if(bridgeExists){cout << "Yes\n";}
            else{cout << "No\n";}
        }
        else{
            cout << "Yes\n";
        }

        cin >> n >> e;
    }
}


int main()
{
    soln();
}