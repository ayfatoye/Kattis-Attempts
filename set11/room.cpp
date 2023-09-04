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

void readjustEdges(int upFlow, int n)
{
    int curr = n - 1;

    while (curr != n - 2)
    {
        vect[curr][parent[curr]] += upFlow;
        vect[parent[curr]][curr] -= upFlow;
        curr = parent[curr];
        // parent = parent[curr];
    }
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

int maxFlow(int n)
{
    // function to build rebuttal edges
    for (int i = 0; i < vect.size(); i++)
    {
        for (auto &stuff : vect[i])
        {
            if (vect[stuff.first].find(i) == vect[stuff.first].end())
            {
                vect[stuff.first][i] = 0;
            }
        }
    }
    // cout << ("here70:\n");
    // printMap(vect);

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
        q.push(n - 2);
        parent[n - 2] = -1;
        flows[n - 2] = INT32_MAX;
        visited[n - 2] = true;

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

                        if (pair.first == n - 1)
                        {
                            sinkFound = true;
                        }
                    }
                }
            }
        }

        if (sinkFound)
        {
            result += flows[n - 1];

            readjustEdges(flows[n - 1], n);
        }
        else
        {
            break;
        }
    }

    return result;
}

int nodeNumInput(int i, int j, int k, int w, int h)
{
    return i * w + j + k * (2 * w * h);
}

int nodeNumOutput(int i, int j, int k, int w, int h)
{
    return i * w + j + w * h + k * (2 * w * h);
}

void soln()
{
    int w = 0, h = 0, t = 0;
    cin >> h >> w >> t;
    vector<vector<char>> tooD(h, vector<char>(w));
    string temp;

    for (int i = 0; i < h; i++)
    {
        cin >> temp;
        // dbg(temp);
        for (int j = 0; j < w; j++)
        {
            tooD[i][j] = temp[j];
        }
    }

    // dbg(tooD);
    vect.resize(2 * h * w * (t + 1) + 2);

    for (int i = 0; i < h; i++)
    {

        for (int j = 0; j < w; j++)
        {
            for (int k = 0; k < t; k++)
            {

                if (tooD[i][j] == '#')
                {
                    continue;
                }
                vect[nodeNumInput(i, j, k, w, h)][nodeNumOutput(i, j, k, w, h)] = 1;
                vect[nodeNumOutput(i, j, k, w, h)][nodeNumInput(i, j, k + 1, w, h)] = 1; // for it staying the same

                if (j + 1 < w && tooD[i][j + 1] != '#')
                {
                    vect[nodeNumOutput(i, j, k, w, h)][nodeNumInput(i, j, k + 1, w, h) + 1] = 1;
                }
                if (j - 1 >= 0 && tooD[i][j - 1] != '#')
                {
                    vect[nodeNumOutput(i, j, k, w, h)][nodeNumInput(i, j, k + 1, w, h) - 1] = 1;
                }
                if (i + 1 < h && tooD[i + 1][j] != '#')
                {
                    vect[nodeNumOutput(i, j, k, w, h)][nodeNumInput(i + 1, j, k + 1, w, h)] = 1;
                }
                if (i - 1 >= 0 && tooD[i - 1][j] != '#')
                {
                    vect[nodeNumOutput(i, j, k, w, h)][nodeNumInput(i - 1, j, k + 1, w, h)] = 1;
                }
                if (tooD[i][j] == 'P' && k == 0)
                {
                    vect[2 * h * w * (t + 1)][nodeNumInput(i, j, k, w, h)] = 1;
                }
                else if (tooD[i][j] == 'E')
                {
                    vect[nodeNumOutput(i, j, k, w, h)][2 * h * w * (t + 1) + 1] = 1;
                }
            }
            if (tooD[i][j] == 'E')
            {
                vect[nodeNumOutput(i, j, t, w, h)][2 * h * w * (t + 1) + 1] = 1; // connecting the very last layer/time's exits to the sink
            }
        }
    }

    // printMap(vect);
    cout << maxFlow(2 * h * w * (t + 1) + 2) << endl;
}

int main()
{
    soln();
}