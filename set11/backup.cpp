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

// void soln()
// {
    
//     int n = 0, m = 0, s = 0, v = 0;
//     string _n = "";
//     // bool lastLineProcessed = false;

//     while (getline(cin, _n))
//     {
//         // n = stoi(_n);
//         parent.clear();
//         visited.clear();
//         flows.clear();
//         vect.clear();
//         stringstream ss(_n);

//         dbg(_n);
//         ss >> n >> m >> s >> v;
//         dbg(n); dbg(m); dbg(s); dbg(v);
//         // cin >> m >> s >> v;

//         double safeDist = s * v;
//         safeDist *= safeDist;

//         // vector<unordered_map<int, int>> vect(n + m + 2);
//         vect.resize(n + m + 2);
//         parent.resize(n + m + 2);
//         visited.resize(n + m + 2);
//         flows.resize(n + m + 2);
//         vector<pair<double, double>> gL(n); // gopher locations
//         vector<pair<double, double>> hL(m); // hole locations

//         pair<double, double> temp;

//         for (int i = 0; i < n; i++)
//         {
//             // cin >> temp.first;
//             // cin >> temp.second;
//             getline(cin, _n);
//             dbg(n);
//             ss.clear();
//             ss.str(_n);
//             ss >> temp.first >> temp.second;
//             gL[i] = temp;
//             dbg(temp);
//             vect[0][i + 2] = 1;
//             vect[i + 2][0] = 0;
//         }

//         for (int i = 0; i < m-1; i++)
//         {
//             // cin >> temp.first;
//             // cin >> temp.second;
//             getline(cin, _n);
//             dbg(n);
//             ss.clear();
//             ss.str(_n);
//             ss >> temp.first >> temp.second;
//             hL[i] = temp;
//             dbg(temp);
//             vect[i + n + 2][1] = 1;
//             vect[1][i + n + 2] = 0;
//         }

//         double currDist = 0.0;
//         cout << "fuck me 179\n"; 
//         for (int i = 0; i < n; i++)
//         {

//             for (int j = 0; j < m; j++)
//             {
//                 currDist = 0.0;
//                 currDist += ((hL[j].first - gL[i].first) * (hL[j].first - gL[i].first));
//                 currDist += ((hL[j].second - gL[i].second) * (hL[j].second - gL[i].second));

//                 if (currDist <= safeDist)
//                 {
//                     vect[i + 2][j + n + 2] = 1;
//                     vect[j + n + 2][i + 2] = 0;
//                 }
//             }
//         }

//         int result = maxFlow(n + m + 2);
//         dbg(n - result);
//         // _n = "";
//         n = 0; m = 0; s = 0; v = 0;
//         // ss.clear();
//         // cout << n - result << endl;
//         // lastLineProcessed = true;
//     }


// }

void soln()
{
    
    int n = 0, m = 0, s = 0, v = 0;
    string _n = "";
    // bool lastLineProcessed = false;

    while (cin >> n >> m >> s >> v)
    {
        
        parent.clear();
        visited.clear();
        flows.clear();
        vect.clear();
      

    
        dbg(n); dbg(m); dbg(s); dbg(v);
        

        double safeDist = s * v;
        safeDist *= safeDist;

        
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
            dbg(n);
            gL[i] = temp;
            dbg(temp);
            vect[0][i + 2] = 1;
            vect[i + 2][0] = 0;
        }

        for (int i = 0; i < m; i++)
        {
            cin >> temp.first;
            cin >> temp.second;
          
            dbg(n);
     
            hL[i] = temp;
            dbg(temp);
            vect[i + n + 2][1] = 1;
            vect[1][i + n + 2] = 0;
        }

        double currDist = 0.0;
        cout << "fuck me 179\n"; 
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
        dbg(n - result);
        n = 0; m = 0; s = 0; v = 0;
      
    }


}


int main()
{
    soln();
}

// vect.clear();
//     int size = 0;
//     int edges = 0;
//     cin >> size;
//     vect.resize(size);
//     cin >> edges;
//     int a = 0, b = 0, c = 0;
//     while(edges--){
//         cin >> a >> b >> c;
//         vect[a][b] = c;
//     }
//     dbg(maxFlow(5));


// int w = 0, h = 0;
//     cin >> w >> h;
//     vector<vector<string>> tooD(h, vector<string>(w));
//     string temp;

//     for (int i = 0; i < h; i++)
//     {
//         cin >> temp;
//         // dbg(temp);
//         for (int j = 0; j < w; j++)
//         {
//             tooD[i][j] = temp[j];
//         }
//     }

//     dbg(tooD);
//     vect.resize(2 * h * w + 2);

//     for (int i = 0; i < h; i++)
//     {

//         for (int j = 0; j < w; j++)
//         {

//             if (isdigit(tooD[i][j][0]))
//             { // checking if tile is a number
//                 dbg(tooD[i][j][0]);
//                 vect[i * h + j][i * h + j + w * h] = stoi(tooD[i][j]);
//             }
//             else
//             {
//                 vect[i * h + j][i * h + j + w * h] = INT32_MAX;
//                 if (tooD[i][j] == "A" /*|| tooD[i][j] == 'A'*/)
//                 {
//                     dbg(tooD[i][j][0]);
//                     vect[(2 * h * w + 2) - 2][i * h + j] = INT32_MAX;
//                     vect[i * h + j + w*h][(2 * h * w + 2) - 2] = INT32_MAX;
//                 }
//                 else if (tooD[i][j] == "B")
//                 {
//                     dbg(tooD[i][j][0]);
//                     dbg(i);
//                     dbg(j);
//                     vect[i * h + j + w * h][(2 * h * w + 2) - 1] = INT32_MAX;
//                     vect[(2 * h * w + 2) - 1][i * h + j] = INT32_MAX;
//                     // vect[(2 * h * w + 2) - 1][i * h + j + w*h] = 0;
//                 }
//             }
//             if (j + 1 < w)
//             {
//                 vect[i * h + j + w * h][i * h + j + 1] = INT32_MAX;
//             }
//             if (j - 1 >= 0)
//             {
//                 vect[i * h + j + w * h][i * h + j - 1] = INT32_MAX;
//             }
//             if (i + 1 < h)
//             {
//                 vect[i * h + j + w * h][i * h + j + w] = INT32_MAX;
//             }
//             if (i - 1 >= 0)
//             {
//                 vect[i * h + j + w * h][i * h + j - w] = INT32_MAX;
//             }
//         }
//     }
//     cout << ("here202:\n");
//     printMap(vect);

//     cout << maxFlow(2 * h * w + 2) << endl;

//////////////////////////////////////////////////////////////

    // vect.clear();
    // int size = 0;
    // int edges = 0;
    // cin >> size >> edges;

    // vect.resize(size);
    // // cin >> edges;
    // int a = 0, b = 0, c = 0;
    // while (edges--)
    // {
    //     cin >> a >> b >> c;
    //     vect[a][b] = c;
    // }
    // printMap(vect);
    // cout << maxFlow(5) << endl;

    /// back up with string and seg fault
//     vector<unordered_map<int, int>> vect;
// vector<int> parent;
// vector<bool> visited;
// vector<int> flows;

// void readjustEdges(int upFlow, int n)
// {
//     int curr = n - 1;

//     while (curr != n - 2)
//     {
//         vect[curr][parent[curr]] += upFlow;
//         vect[parent[curr]][curr] -= upFlow;
//         curr = parent[curr];
//         // parent = parent[curr];
//     }
// }

// void printMap(vector<unordered_map<int, int>> mapy)
// {
//     cerr << BLUE;
//     for (int i = 0; i < mapy.size(); i++)
//     {
//         cout << i << ":\n";
//         for (auto &stuff : mapy[i])
//         {
//             cerr << i << " -> " << stuff.first << "(" << stuff.second << ")\n";
//         }
//     }
//     cerr << NC;
// }

// int maxFlow(int n)
// {
//     // function to build rebuttal edges
//     for (int i = 0; i < vect.size(); i++)
//     {
//         for (auto &stuff : vect[i])
//         {
//             if (vect[stuff.first].find(i) == vect[stuff.first].end())
//             {
//                 vect[stuff.first][i] = 0;
//             }
//         }
//     }
//     // cout << ("here70:\n");
//     // printMap(vect);

//     bool sinkFound = true;
//     int result = 0;

//     int curr = 0; // item just popped in bfs while loop

//     while (sinkFound)
//     {
//         sinkFound = false;
//         parent.clear();
//         parent.resize(n);
//         visited.clear();
//         visited.resize(n);
//         flows.clear();
//         flows.resize(n);

//         queue<int> q;
//         q.push(n - 2);
//         parent[n - 2] = -1;
//         flows[n - 2] = INT32_MAX;
//         visited[n - 2] = true;

//         while (!q.empty() && !sinkFound)
//         {
//             curr = q.front();
//             q.pop();

//             for (auto &pair : vect[curr])
//             {
//                 if (visited[pair.first] == false)
//                 {
//                     // visited[pair.first] = true;

//                     if (pair.second != 0)
//                     {
//                         q.push(pair.first);
//                         parent[pair.first] = curr;
//                         flows[pair.first] = min(pair.second, flows[curr]);
//                         visited[pair.first] = true;

//                         if (pair.first == n - 1)
//                         {
//                             sinkFound = true;
//                         }
//                     }
//                 }
//             }
//         }

//         if (sinkFound)
//         {
//             result += flows[n - 1];

//             readjustEdges(flows[n - 1], n);
//         }
//         else
//         {
//             break;
//         }
//     }

//     return result;
// }

// void soln()
// {
//     int w = 0, h = 0;
//     cin >> w >> h;
//     vector<vector<char>> tooD(h, vector<char>(w));
//     string temp;

//     for (int i = 0; i < h; i++)
//     {
//         cin >> temp;
//         // dbg(temp);
//         for (int j = 0; j < w; j++)
//         {
//             tooD[i][j] = temp[j];
//         }
//     }

//     // dbg(tooD);
//     vect.resize(2 * h * w + 2);

//     for (int i = 0; i < h; i++)
//     {

//         for (int j = 0; j < w; j++)
//         {

//             if (isdigit(tooD[i][j][0]))
//             { // checking if tile is a number
//                 // dbg(tooD[i][j][0]);
//                 vect[i * h + j][i * h + j + w * h] = stoi(tooD[i][j]);
//             }
//             else
//             {
//                 vect[i * h + j][i * h + j + w * h] = INT32_MAX;
//                 if (tooD[i][j] == "A" /*|| tooD[i][j] == 'A'*/)
//                 {
//                     // dbg(tooD[i][j][0]);
//                     vect[(2 * h * w + 2) - 2][i * h + j] = INT32_MAX;
//                     // vect[i * h + j + w * h][(2 * h * w + 2) - 2] = INT32_MAX;
//                 }
//                 else if (tooD[i][j] == "B")
//                 {
//                     // dbg(tooD[i][j][0]);
//                     // dbg(i);
//                     // dbg(j);
//                     vect[i * h + j + w * h][(2 * h * w + 2) - 1] = INT32_MAX;
//                     // vect[(2 * h * w + 2) - 1][i * h + j] = INT32_MAX;
//                     // vect[(2 * h * w + 2) - 1][i * h + j + w*h] = 0;
//                 }
//             }
//             if (j + 1 < w)
//             {
//                 vect[i * h + j + w * h][i * h + j + 1] = INT32_MAX;
//             }
//             if (j - 1 >= 0)
//             {
//                 vect[i * h + j + w * h][i * h + j - 1] = INT32_MAX;
//             }
//             if (i + 1 < h)
//             {
//                 vect[i * h + j + w * h][i * h + j + w] = INT32_MAX;
//             }
//             if (i - 1 >= 0)
//             {
//                 vect[i * h + j + w * h][i * h + j - w] = INT32_MAX;
//             }
//         }
//     }
//     // cout << ("here202:\n");
//     // printMap(vect);

//     cout << maxFlow(2 * h * w + 2) << endl;

// }

// int main()
// {
//     soln();
// }