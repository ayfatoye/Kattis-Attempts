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
vector<unordered_map<int, int>> vect;
vector<int> parent;
vector<bool> visited;
vector<int> flows;

void readjustEdges(int upFlow)
{
    int curr = 1;

    while (curr != 0)
    {
        vect[curr][parent[curr]] += upFlow;
        vect[parent[curr]][curr] -= upFlow;
        curr = parent[curr];
        // parent = parent[curr];
    }
}

int maxFlow(int n)
{
    // vect.resize(n);
    // parent.resize(n);
    // visited.resize(n);
    // flows.resize(n);
    bool sinkFound = true;
    int result = 0;

    int curr = 0; // item just popped in bfs while loop

    while (sinkFound)
    {
        sinkFound = false;
        parent.clear();
        parent.resize(n);
        visited.clear();
        visited.resize(n);
        flows.clear();
        flows.resize(n);

        queue<int> q;
        q.push(0);
        parent[0] = -1;
        flows[0] = INT_MAX;
        visited[0] = true;

        while (!q.empty() && !sinkFound)
        {
            curr = q.front();
            q.pop();

            for (auto &pair : vect[curr])
            {
                if (visited[pair.first] == false)
                {
                    // visited[pair.first] = true;

                    if (pair.second != 0)
                    {
                        q.push(pair.first);
                        parent[pair.first] = curr;
                        flows[pair.first] = min(pair.second, flows[curr]);
                        visited[pair.first] = true;

                        if (pair.first == 1)
                        {
                            sinkFound = true;
                        }
                    }
                }
            }
        }

        if (sinkFound)
        {
            result += flows[1];

            readjustEdges(flows[1]);
        }
        else
        {
            break;
        }
    }

    return result;
}

void soln()
{
    int n = 0, m = 0, s = 0, v = 0;

    while (cin >> n >> m >> s >> v)
    {
        parent.clear();
        visited.clear();
        flows.clear();
        vect.clear();
      
        double safeDist = s * v;
        safeDist *= safeDist;

        // vector<unordered_map<int, int>> vect(n + m + 2);
        vect.resize(n + m + 2);
        parent.resize(n + m + 2);
        visited.resize(n + m + 2);
        flows.resize(n + m + 2);
        vector<pair<double, double>> gL(n); // gopher locations
        vector<pair<double, double>> hL(m); // hole locations

        pair<double, double> temp;

        for (int i = 0; i < n; i++)
        {
            cin >> temp.first;
            cin >> temp.second;
            gL[i] = temp;
            vect[0][i + 2] = 1;
            vect[i + 2][0] = 0;
        }

        for (int i = 0; i < m; i++)
        {
            cin >> temp.first;
            cin >> temp.second;
            hL[i] = temp;
            vect[i + n + 2][1] = 1;
            vect[1][i + n + 2] = 0;
        }

        double currDist = 0.0;

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {
                currDist = 0.0;
                currDist += ((hL[j].first - gL[i].first) * (hL[j].first - gL[i].first));
                currDist += ((hL[j].second - gL[i].second) * (hL[j].second - gL[i].second));

                if (currDist <= safeDist)
                {
                    vect[i + 2][j + n + 2] = 1;
                    vect[j + n + 2][i + 2] = 0;
                }
            }
        }

        int result = maxFlow(n + m + 2);
        // dbg(n - result);
        cout << n - result << endl;
    }
}

int main()
{
    soln();
}
