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

template <typename T> //printing out queues
std::ostream& operator<<(std::ostream& out, std::queue<T> q) {
    if(q.empty()) return out << "[]";
    out << '[';
    while(!q.empty()){out << q.front() << ", "; q.pop();}
    return out << ']';
}

void soln()
{
    int n, m;
    cin >> n >> m;
    vector<int> debt(n);
    for (int i = 0; i < n; i++)
    {
        cin >> debt[i];
    }
    // cout << "here37\n";
    vector<vector<int>> vect;
    vector<vector<int>> input(n);
    int a = 0;
    int b = 0;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        // cout << "here45\n";
        input[a].push_back(b);
        input[b].push_back(a);
        // cout << "here49\n";
    }

    // cout << "here52\n";

    // doing bfs
    queue<int> q;
    vector<int> visited(n);
    int temp = -1;

    for (int i = 0; i < n; i++)
    {
        // cout << "fuck61\n";
        if (visited[i])
            continue;

        q.push(i);
        visited[i] = true;
        vector<int> tempVect;
        // int k = 0;

        while (!q.empty())
        {
            // k++;
            // dbg(q);
            temp = q.front();
            tempVect.push_back(temp);
            q.pop();

            for (int j = 0; j < input[temp].size(); j++)
            {
                if (!visited[input[temp][j]])
                {
                    q.push(input[temp][j]);
                    visited[input[temp][j]] = true;
                }
            }
        }

        vect.push_back(tempVect);
        // cout<< "fuck84\n";

    }

    int currSum = 0;

    for(int i = 0; i < vect.size(); i++){

        currSum = 0;

        for(int j = 0; j < vect[i].size(); j++)
            currSum += debt[vect[i][j]];

        if(currSum != 0){
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

    cout << "POSSIBLE\n";
}

int main()
{
    soln();
}