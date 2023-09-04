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

int bS(std::vector<int> &vect, int target)
{
    int left = 0;
    int right = vect.size() - 1;
    int mid;

    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (vect[mid] == target)
        {
            return mid;
        }

        if (vect[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (left < vect.size())
        return left;

    return left - 1;
}

void soln()
{
    vector<int> L;
    int n = 0;
    cin >> n;

    vector<int> aux(n);

    for(int i = 0; i < n; i++)
        cin >> aux[i];

    L.clear();
    L.push_back(-1);
    L.push_back(aux[0]);

    for (int i = 0; i < aux.size(); i++)
    {
        if (aux[i] > L.back())
        {
            L.push_back(aux[i]);
        }
        else
        {
            L[bS(L, aux[i])] = aux[i];
        }
    }

    cout << L.size() - 1 << endl;
}

int main()
{
    soln();
}