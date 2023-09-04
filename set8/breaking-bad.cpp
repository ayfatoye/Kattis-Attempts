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
bool fuck = false;

void dfs(string currKey, string &next, map<string, string> &color, map<string, vector<string>> &input, map<string, bool> &visited)
{
    color[currKey] = next;
    if (next == "W")
    {
        next = "L";
    }
    else
    {
        next = "W";
    }
    visited[currKey] = true;
    for (int i = 0; i < input[currKey].size(); i++)
    {
        if (!visited[input[currKey][i]])
        {
            dfs(input[currKey][i], next, color, input, visited);
        }
        else
        {
            // dbg(currKey);  dbg(input[currKey]);
            //     dbg(color[input[currKey][i]]);
            //     dbg(color[currKey]);
            if (color[input[currKey][i]] == color[currKey])
            {
                // dbg(currKey);
                // dbg(input[currKey]);
                // dbg(color[input[currKey][i]]);
                // dbg(color[currKey]);
                fuck = true;
            }
        }
    }
}

// void soln(){
//    map<string, vector<string>> input;
//    map<string, string> color;
//    map<string, bool> visited;
//    int n = 0;
//    cin >> n;

//    string str;

//    for(int i = 0; i < n; i++){
//         cin >> str;
//         vector<string> vect;
//         input[str] = vect;
//         color[str] = "N";
//         visited[str] = false;
//    }
//    int m = 0;
//    cin >> m;
//    string a = ""; string b = "";

//    for(int i = 0; i < m; i++){
//         cin >> a >> b;
//         input[a].push_back(b);
//         input[b].push_back(a);
//    }

//    for(auto it = input.begin(); it != input.end(); it++){
//         string next = "W";
//         dfs(it->first, next, color, input, visited);
//    }

//    if(fuck){
//         cout << "impossible" << endl;
//    }
//    else{
//         vector<string> w;
//         vector<string> l;
//         for(auto it = color.begin(); it != color.end(); it++){
//             if(it->second == "W"){
//                 w.push_back(it->first);
//             }
//             else{
//                 l.push_back(it->first);
//             }
//         }

//         for(int i = 0; i < w.size(); i++){
//             cout << w[i] << " ";
//         }
//         cout << endl;

//         for(int i = 0; i < l.size(); i++){
//             cout << l[i] << " ";
//         }
//         cout << endl;
//    }

// }

void soln()
{
    map<string, vector<string>> input;
    map<string, string> color;
    map<string, bool> visited;
    string _co = "W";
    int n = 0;
    cin >> n;

    string str = "";

    vector<string> all_items;

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        vector<string> vect;
        all_items.push_back(str);
        input[str] = vect;
        color[str] = "N";
        visited[str] = false;
    }
    int m = 0;
    cin >> m;
    string a = "";
    string b = "";

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        input[a].push_back(b);
        input[b].push_back(a);
    }


    for (string x : all_items)
    {
        if (!visited[x]){
            string hi = "W";
            dfs(x, hi, color, input, visited);
        }
            
    }

    if (fuck)
    {
        cout << "impossible" << endl;
    }
    else
    {
        vector<string> w;
        vector<string> l;
        for (auto it = color.begin(); it != color.end(); it++)
        {
            if (it->second == "W")
            {
                w.push_back(it->first);
            }
            else if (it->second == "L")
            {
                l.push_back(it->first);
            }
        }

        for (int i = 0; i < w.size(); i++)
        {
            cout << w[i] << " ";
        }
        cout << endl;

        for (int i = 0; i < l.size(); i++)
        {
            cout << l[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    soln();
}