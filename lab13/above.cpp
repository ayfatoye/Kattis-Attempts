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
    int c = 0;
    cin >> c;
    int t = 0;
    vector<int> vect;
    double avg = 0;
    int numGreater = 0;
    double output = 0.0;

    cout << std::fixed << std::setprecision(3);

    for (int k = 0; k < c; k++)
    {
        cin >> t;
        vect.clear();
        vect.resize(t);
        for(int i = 0; i < t; i++){
            cin >> vect[i];
        }
        // dbg(vect);
        avg = (accumulate(vect.begin(), vect.end(), 0)) / t;
        // dbg(avg);
        numGreater = count_if(vect.begin(), vect.end(), [&] (int n) {return n > avg;});
        // dbg(numGreater);
        output = (static_cast<double>(numGreater) / static_cast<double>(t)) * 100;
        cout << output <<"%"<< endl;
    }
}

int main()
{
    soln();
}