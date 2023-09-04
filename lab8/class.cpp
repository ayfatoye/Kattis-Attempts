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
    int sections = 0;
    cin >> sections;
    vector<int> vect(sections);

    for (int i = 0; i < sections; i++)
    {
        cin >> vect[i];
    }

    int num = accumulate(vect.begin(), vect.end(), 0);

    if (num % 3 != 0)
    {
        cout << -1 << endl;
        return;
    }

    int currA = num / 3;
    int origI = -2;
    
    //    int currSeat = 0;

    //    string result = "";
    //    bool second = false;

    for (int i = 0; i < vect.size(); i++)
    {
        currA -= vect[i];

        if(currA == 0){
            if(origI == -2){
                origI = i;
                currA = num/3;
            }
            else{
                cout << origI + 1 << " " << i + 1<< endl;
                return;
            }
                        
        }

        else if (currA < 0)
        {
            cout << -1 << endl;
            return;
        }
        
    }
}

int main()
{
    soln();
}