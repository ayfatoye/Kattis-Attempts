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

bool bridgeFS(vector<vector<int>> &vect, vector<int> &lowNum, vector<int> &nodeNum, set<pair<int, int>> &bridges)
{
    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect.at(i).size(); j++)
        {
            if (lowNum[i] > nodeNum[vect.at(i).at(j)])
            {
                bridges.insert({i, vect.at(i).at(j)});
                bridges.insert({vect.at(i).at(j), i});
            }
            else if (lowNum[vect.at(i).at(j)] > nodeNum.at(i))
            {
                bridges.insert({i, vect.at(i).at(j)});
                bridges.insert({vect.at(i).at(j), i});
            }
        }
    }
    return false;
}

int dfs(vector<vector<int>> &vect, vector<int> &lowNum, vector<int> &nodeNum, int &nextNode, int currNode, vector<bool> &visited, int parent)
{
    visited[currNode] = true;
    nodeNum[currNode] = nextNode;
    lowNum[currNode] = nextNode;
    nextNode++;

    for (int i = 0; i < vect[currNode].size(); i++)
    {
        if (vect[currNode][i] == parent)
        {
            continue;
        }
        if (!visited[vect[currNode][i]])
        {

            int low = dfs(vect, lowNum, nodeNum, nextNode, vect[currNode][i], visited, currNode);
            if (low < lowNum[currNode])
            {
                lowNum[currNode] = low;
            }
        }
        else
        {

            if (nodeNum[vect[currNode][i]] < lowNum[currNode])
            {
                lowNum[currNode] = lowNum[vect[currNode][i]];
            }
        }
    }

    return lowNum[currNode];
}

void soln()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;
    vector<vector<int>> vect(n);
    int a = 0;
    int b = 0;

    int nextNode = 0; // we assign this at each step of dfs to the actual nodes
    int currNode = 0; // the node we're currently performing dfs on
    int shouldBeZero = 0;
    int bridgeExists = false;
    set<pair<int, int>> bridges;

    vector<int> lowNum(n);
    vector<int> nodeNum(n); // nodeNum stores the dfs nextNodes or node numbers for each actual node
    vector<bool> visited(n);

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        vect[a].push_back(b);
        vect[b].push_back(a);
    }

    shouldBeZero = dfs(vect, lowNum, nodeNum, nextNode, vect[0][0], visited, -1);
    bridgeExists = bridgeFS(vect, lowNum, nodeNum, bridges);

    // bfs
    queue<int> q;
    q.push(0);
    int temp = 0;
    vector<bool> bfsVisited(n);
    int output = 0;

    
    for (int startNode = 0; startNode < n; ++startNode)
    {
        if (!bfsVisited[startNode])
        {
            q.push(startNode);
            bfsVisited[startNode] = true;
            int componentSize = 1;

            while (!q.empty())
            {
                temp = q.front();
                q.pop();
                

                for (int i = 0; i < vect[temp].size(); i++)
                {
                    if (!bfsVisited[vect[temp][i]] && bridges.find(make_pair(temp, vect[temp][i])) == bridges.end())
                    {
                        q.push(vect[temp][i]);
                        bfsVisited[vect[temp][i]] = true;
                        componentSize++;
                    }
                }
            }

            output = max(output, componentSize);
        }
    }

    // while (!q.empty())
    // {
    //     temp = q.front();
    //     q.pop();

    //     for (int i = 0; i < vect[temp].size(); i++)
    //     {

    //         if (!bfsVisited[vect[temp][i]])
    //         {
    //             bfsVisited[vect[temp][i]] = true;

    //             if (find(bridges.begin(), bridges.end(), make_pair(vect[temp][i], temp)) == bridges.end())
    //             { // only put next node if edge connecting is not a bridge
    //                 q.push(vect[temp][i]);
    //                 output++;
    //             }
    //         }
    //     }
    // }

    cout << output << endl;
}

int main()
{
    soln();
}