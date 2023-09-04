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

void soln()
{
    string str = "";
    vector<vector<char>> input(10, vector<char>(10));

    for (int i = 0; i < 10; i++)
    {
        cin >> str;
        for (int j = 0; j < 10; j++)
        {
            input[i][j] = str[j];
        }
    }

    set<char> pplFound;

    // finding how many people I can see from the left side of the room
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (input[i][j] == '#')
            {
                break;
            }
            else if (input[i][j] != '.')
            {
                pplFound.insert(input[i][j]);
                break;
            }
        }
    }

    // finding how many people I can see from the top side of the room
    for (int j = 0; j < 10; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            if (input[i][j] == '#')
            {
                break;
            }
            else if (input[i][j] != '.')
            {
                pplFound.insert(input[i][j]);
                break;
            }
        }
    }

    // finding how many people I can see from the right side of the room
    for (int i = 0; i < 10; i++)
    {
        for (int j = 9; j >= 0; j--)
        {
            if (input[i][j] == '#')
            {
                break;
            }
            else if (input[i][j] != '.')
            {
                pplFound.insert(input[i][j]);
                break;
            }
        }
    }

    // finding how many people I can see from the bottom side of the room
    for (int j = 0; j < 10; j++)
    {
        for (int i = 9; i >= 0; i--)
        {
            if (input[i][j] == '#')
            {
                break;
            }
            else if (input[i][j] != '.')
            {
                pplFound.insert(input[i][j]);
                break;
            }
        }
    }

    cout << pplFound.size() << endl;
}

int main()
{
    soln();
}