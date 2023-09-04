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

void soln()
{
    int h = 0, w = 0;
    cin >> w >> h;

    vector<vector<char>> tooD(h, vector<char>(w));
    vector<vector<char>> visited(h, vector<char>(w));

    string temp = "";
    pair<int, int> start;
    pair<int, int> curr;

    for (int i = 0; i < h; i++)
    {
        cin >> temp;
        for (int j = 0; j < w; j++)
        {
            tooD[i][j] = temp[j];
            if (temp[j] == 'P')
            {
                start.first = i;
                start.second = j;
            }
        }
    }

    // bfs
    queue<pair<int, int>> q;
    q.push(start);
    int cnt = 0;

    while (!q.empty())
    {
        curr = q.front();
        q.pop();

        if (visited[curr.first][curr.second])
            continue;

        visited[curr.first][curr.second] = true;

        if (tooD[curr.first][curr.second] == 'G')
            cnt++;

        if (curr.first - 1 >= 0 && tooD[curr.first - 1][curr.second] == 'T')
        {
            continue;
        }
        if (curr.first + 1 < h && tooD[curr.first + 1][curr.second] == 'T')
        {
            continue;
        }
        if (curr.second - 1 >= 0 && tooD[curr.first][curr.second - 1] == 'T')
        {
            continue;
        }
        if (curr.second + 1 < w && tooD[curr.first][curr.second + 1] == 'T')
        {
            continue;
        }

        if (curr.first - 1 >= 0 && !visited[curr.first - 1][curr.second] && tooD[curr.first - 1][curr.second] != '#')
        {
            q.push({curr.first - 1, curr.second});
        }

        if (curr.first + 1 < h && !visited[curr.first + 1][curr.second] && tooD[curr.first + 1][curr.second] != '#')
        {
            q.push({curr.first + 1, curr.second});
        }

        if (curr.second + 1 < w && !visited[curr.first][curr.second + 1] && tooD[curr.first][curr.second + 1] != '#')
        {
            q.push({curr.first, curr.second + 1});
        }

        if (curr.second - 1 >= 0 && !visited[curr.first][curr.second - 1] && tooD[curr.first][curr.second - 1] != '#')
        {
            q.push({curr.first, curr.second - 1});
        }
    }

    cout << cnt << endl;
}

int main()
{
    soln();
}