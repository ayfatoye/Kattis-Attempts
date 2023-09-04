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
    int low = 1;
    int up = 50001, n = 0;
    string fuck = "";
    int shit = 0;
    vector<int> divs;
    vector<int> out;
    bool thisCounts = true;

    while (cin >> n)
    {
        if (n == 0)
            return;

        low = 1; up = 50001; shit = 0; divs.clear(); thisCounts = true; out.clear();

        for (int i = 0; i < n; i++)
        {
            cin >> fuck;

            if (fuck == "less")
            {
                cin >> fuck;
                cin >> shit;

                if (shit < up)
                    up = shit-1;
            }

            else if (fuck == "greater")
            {
                cin >> fuck;
                cin >> shit;

                if (shit > low)
                    low = shit+1;
            }

            else
            {
                cin >> fuck;
                cin >> shit;

                divs.push_back(shit);
            }
        }

        if(up == 50001){
            cout << "infinite\n";
            continue;
        }
        out.clear();
        
        for(int i = low; i <= up; i++){
            thisCounts = true;
            for(int j = 0; j < divs.size(); j++){
                if(i % divs[j] != 0){
                    thisCounts = false;
                    break;
                }
            }
            if(thisCounts){
                out.push_back(i);
            }
        }

        if(out.size() == 0)
            cout << "none\n";

        else{
            for(int i : out){
                cout << i << " ";
            }
        }        
    }
}

int main()
{
    soln();
}