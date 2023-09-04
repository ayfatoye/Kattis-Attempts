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

template <typename T> //printing out queues
std::ostream& operator<<(std::ostream& out, std::queue<T> q) {
    if(q.empty()) return out << "[]";
    out << '[';
    while(!q.empty()){out << q.front() << ", "; q.pop();}
    return out << ']';
}

void soln()
{
    int n = 0, m = 0;
    cin >> n >> m;

    vector<vector<int>> vect(n + 1);
    queue<int> q;
    vector<bool> visited(n + 1);

    int a = 0, b = 0;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        vect[a].push_back(b);
        vect[b].push_back(a);
    }

    // doing bfs
    if(vect[0].size() == 0){
        cout << "0" << endl;
        return;
    }

    q.push(0);
    int curr = 0;
    vector<int> hidein;
    vector<int> depth(n + 1);
    depth[0] = 0;

    // int _currDepth = 0;

    visited[0] = true;

    while(!q.empty() && depth[curr] < 4){
        curr = q.front();
        // hidein.push_back(curr);
        q.pop();

        for(int i = 0; i < vect[curr].size(); i++){
            if(!visited[vect[curr][i]]){
                visited[vect[curr][i]] = true;
                q.push(vect[curr][i]);
                depth[vect[curr][i]] = depth[curr] + 1;
                if(depth[vect[curr][i]] <= 3){
                    hidein.push_back(vect[curr][i]);
                }
            }
        }
       
    }

    cout << hidein.size() << endl;
    for(int& num : hidein){
        cout << num << " ";
    }
    cout << endl;

}

int main()
{
    soln();
}