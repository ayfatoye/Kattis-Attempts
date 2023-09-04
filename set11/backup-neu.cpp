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

void soln()
{
    int w = 0, h = 0;
    cin >> w >> h;
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
    vect.resize(2 * h * w + 2);

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (isdigit(tooD[i][j]))
            {
                vect[i * w + j][i * w + j + w * h] = tooD[i][j] - '0';
            }
            else
            {
                vect[i * w + j][i * w + j + w * h] = INT32_MAX;
                if (tooD[i][j] == 'A')
                {
                    vect[(2 * h * w + 2) - 2][i * w + j] = INT32_MAX;
                }
                else if (tooD[i][j] == 'B')
                {
                    vect[i * w + j + w * h][(2 * h * w + 2) - 1] = INT32_MAX;
                }
            }
            if (j + 1 < w)
            {
                vect[i * w + j + w * h][i * w + j + 1] = INT32_MAX;
            }
            if (j - 1 >= 0)
            {
                vect[i * w + j + w * h][i * w + j - 1] = INT32_MAX;
            }
            if (i + 1 < h)
            {
                vect[i * w + j + w * h][(i + 1) * w + j] = INT32_MAX;
            }
            if (i - 1 >= 0)
            {
                vect[i * w + j + w * h][(i - 1) * w + j] = INT32_MAX;
            }
        }
    }

    // cout << ("here202:\n");
    // printMap(vect);

    cout << maxFlow(2 * h * w + 2) << endl;
}

int main()
{
    soln();
}