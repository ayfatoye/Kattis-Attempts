#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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


unordered_map<string, vector<string>> graph;
unordered_map<string, int> inDeg;
vector<string> programs;
void parseMe()
{
    string line = "";
   
        std::getline(std::cin, line);
        size_t colonPos = line.find(':');
        if (colonPos != std::string::npos)
        {
            std::string node = line.substr(0, colonPos);
            std::stringstream ss(line.substr(colonPos + 1));
            std::string token;
            while (std::getline(ss, token, ' '))
            {
                
                    graph[node].push_back(token);
                    programs.push_back(node);
                    inDeg[token]++;

                
            }
        }
   
}

void soln()
{
    int n = 0;
    cin >> n;
    string str = "";
    

    for (int i = 0; i < n; i++)
    {
        parseMe();
    }
    string start = "";
    cin >> start;

    // doing topological sort
    queue<string> q;
    dbg(programs);

    for (int i = 0; i < programs.size(); i++)
    {
        if (inDeg[programs[i]] == 0)
        {
            q.push(programs[i]);
        }
    }

    string temp = "";

    vector<string> result;

    while (!q.empty())
    {
        temp = q.front();
        result.push_back(temp);

        q.pop();
    
        for (int i = 0; i < graph[temp].size(); i++)
        {
            inDeg[graph[temp][i]]--;
            if (inDeg[graph[temp][i]] == 0)
            {
                q.push(graph[temp][i]);
            }
        }
    }
    dbg(result);
}

int main()
{
    soln();
}