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
    string str = "";
    string s = "";
    string s2 = "";
    string nL = "";
    stringstream ss;
    unordered_map<string, string> dict;
    vector<string> output;

    while (getline(cin, str))
    {
        // cin >> nL;
        ss.clear();
        ss.str(str);
        while (ss >> s)
        {
            // ss >> s;
            s2 = s;
            transform(s2.begin(), s2.end(), s2.begin(), [](unsigned char c)
                      { return std::tolower(c); });

            if (dict.find(s2) != dict.end())
            {
                output.push_back(" . ");
            }
            else
            {
                output.push_back(" ");
                output.push_back(s);
                output.push_back(" ");
                dict[s2] = s2;
            }
        }
        output.push_back("\n");
    }
    // while(getline(cin, str)){
    //     cin >> s;
    //     s2 = str;

    // }

    for (int i = 0; i < output.size(); i++)
        cout << output.at(i);
}

int main()
{
    soln();
}