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

#include <iostream>
#include <vector>

using namespace std;

long long merge(vector<int> &arr, int left, int mid, int right)
{
    int i = left;
    int l = mid;
    int k = 0;
    long long count = 0;
    vector<int> temp(right - left);

    while (l < right and i < mid)
    {
        if (arr[i] <= arr[l])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[l++];
            count += mid - i; // Count the number of swaps.
        }
    }

    while (i < mid)
    {
        temp[k++] = arr[i++];
    }

    while (l < right)
    {
        temp[k++] = arr[l++];
    }

    for (i = left; i < right; ++i)
    {
        arr[i] = temp[i - left];
    }

    return count;
}

long long mergeSort(vector<int> &arr, int left, int right)
{
    long long count = 0;

    if (right - left > 1)
    {
        int mid = left + (right - left) / 2;
        count += mergeSort(arr, left, mid);
        count += mergeSort(arr, mid, right);
        count += merge(arr, left, mid, right);
    }

    return count;
}


void soln()
{
    int n = 0;
    cin >> n;
    vector<int> visited(n + 1);
    vector<int> vect(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> vect[i];
    }
    // dbg(vect);
    ll numSwaps = mergeSort(vect, 0, vect.size());
    // dbg(vect);
    // dbg(numSwaps);
    cout << numSwaps << endl;

    // performing merge sort
}

int main()
{
    soln();
}