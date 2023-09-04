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

class node
{
public:
    bool isin;
    node *ch[26];
    int counter;

    node()
    {
        isin = false;
        for (int i = 0; i < 26; i++)
            ch[i] = NULL;

        counter = 0;
    }

    void add(string &s, int ind = -1)
    {
        counter++;
        if (ind + 1 < s.size())
        {
            if (ch[s[ind + 1] - 'A'] == NULL)
            {
                ch[s[ind + 1] - 'A'] = new node();
            }
            ch[s[ind + 1] - 'A']->add(s, ind + 1);
        }
        else
        {
            isin = true;
            return;
        }
    }

    int find(string &s, int ind = -1)
    {
        if (ind + 1 == s.size())
            return counter;

        else
        {
            if (ch[s[ind + 1] - 'A'] == NULL)
            {
                return 0;
            }
            return ch[s[ind + 1] - 'A']->find(s, ind + 1);
        }
    }

    bool findWord(string &s, int ind = -1)
    {
        if (ind + 1 == s.size())
            return true;

        if (ch[s[ind + 1] - 'A'] == NULL)
            return false;

        return ch[s[ind + 1] - 'A']->findWord(s, ind + 1);
    }
};

set<string> foundWords;
node Trie;
vector<vector<bool>> visited(4, vector<bool>(4));
unordered_map<string, int> dict;

void solveBoggle(vector<vector<char>> &tooD, string &s, pair<int, int> currP)
{
    s += tooD[currP.first][currP.second];
    visited[currP.first][currP.second] = true;

    if (s.length() >= 1)
    {
        // cout << "fuck my life, line 101\n";
    }
    // if(s.length() > 8){
    if (!Trie.findWord(s))
    {
        // cout << "fuck my life, line 105\n";
        s.pop_back();
        visited[currP.first][currP.second] = false;
        return;
    }
    else if (dict.find(s) != dict.end())
    {
        foundWords.insert(s);
    }

    int row[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int col[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int newRow = 0;
    int newCol = 0;

    for (int i = 0; i < 8; i++)
    {
        newRow = currP.first + row[i];
        newCol = currP.second + col[i];

        if (newRow >= 0 && newRow < tooD.size() && newCol >= 0 && newCol < tooD[0].size() && !visited[newRow][newCol])
        {
            solveBoggle(tooD, s, {newRow, newCol});
        }
    }

    s.pop_back();
    visited[currP.first][currP.second] = false;
}

void solve(vector<vector<char>> &tooD, pair<int, int> currP)
{
    string s = "";
    solveBoggle(tooD, s, currP);
    // for(string s : foundWords){

    // }
    // cout << foundWords.size() << endl;
}

void soln()
{
    int n = 0;
    cin >> n;
    string maxString = "";
    int maxPoints = 0;
    // unordered_map<string, int> dict;
    string str = "";

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        Trie.add(str);
        dict[str] = 1;

        if (str.length() < 3)
        {
            dict[str] = 0;
        }
        else if (str.length() == 5)
        {
            dict[str] = 2;
        }
        else if (str.length() == 6)
        {
            dict[str] = 3;
        }
        else if (str.length() == 7)
        {
            dict[str] = 5;
        }
        else if (str.length() == 8)
        {
            dict[str] = 11;
        }
    }
    // cin >> str; // empty string
    int t = 0;

    cin >> t;
    for (int k = 0; k < t; k++)
    {
        maxString = "a";
        maxPoints = 0;
        // building current board
        vector<vector<char>> tooD(4, vector<char>(4));
        for (int i = 0; i < 4; i++)
        {
            cin >> str;
            for (int j = 0; j < 4; j++)
            {
                tooD[i][j] = str[j];
            }
        }
        // dbg(tooD);
        foundWords.clear();
        // call solve(tooD)
        string s = "";
        for (int a = 0; a < 4; a++)
        {

            for (int b = 0; b < 4; b++)
            {
                solve(tooD, {a, b});
            }
        }
        // for(string s : foundWords){
        //     cout << s << " : " << dict[s];
        // }
        // cout << endl;
        // dbg(foundWords.size());
        for(string s : foundWords){
            if(s.length() > maxString.length()){
                maxString = s;
            }
            maxPoints += (dict[s]);
        }
        cout << maxPoints << " " << maxString << " " << foundWords.size() << endl;
        // cout << foundWords.size() << endl;

        // cin the empty line
        // cin >> str;
    }
}

int main()
{
    soln();
}