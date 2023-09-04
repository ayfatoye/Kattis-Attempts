#include <bits/stdc++.h>
using namespace std;
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define WHITE "\033[1;37m"
#define NC "\033[0m"
#define dbg(x) cerr << RED << #x << " = " << x << NC << endl
#define dbgB(x) cerr << BLUE << #x << " = " << x << NC << endl
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

int bS(std::vector<int>& vect, int target) {
    int left = 0;
    int right = vect.size() - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (vect[mid] == target) {
            return mid;
        }

        if (vect[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if(left < vect.size())
        return left;
    
    return left - 1;
}
// int bS(vector<int>& vect, int target) {
//     int left = 0;
//     int right = vect.size() - 1;
//     int mid;

//     while (left <= right) {
//         mid = left + (right - left) / 2;

//         if (vect[mid] == target) {
//             return mid;
//         }

//         if (vect[mid] < target) {
//             left = mid + 1;
//         } else {
//             right = mid - 1;
//         }
//     }

//     return left;
// }

vector<int> prince;
vector<int> princess;
int currCase = 1;
unordered_map<int, int> mapy;
vector<int> aux;
vector<int> L;

void LCS(vector<int>& a, vector<int>& b){
    // unordered_map<int, int> mapy;
    // vector<int> aux;
    mapy.clear();
    aux.clear();
    aux.push_back(-1);

    for(int i = 1; i < b.size(); i++){
        mapy[b[i]] = i;
    }

    for(int i = 1; i < a.size(); i++){
        
        // if(mapy.find(a[i]) == mapy.end()){
        //     aux[i] = -1;
        // }
        // else{
        //     aux[i] = mapy[a[i]];
        // }
        if(mapy.find(a[i]) != mapy.end()){
            // cout << "here\n";
            aux.push_back(mapy[a[i]]);
        }
    }

    // dbg(aux);

    // now perform LIS on aux and the resulting longest increasing subsequence on aux will be 
    //  the indicies of the lcs in b.

    // vector<int> L;
    L.clear();
    L.push_back(-1);
    L.push_back(aux[1]);

    for(int i = 1; i < aux.size(); i++){
        if(aux[i] > L.back()){
            L.push_back(aux[i]);
        }
        else{
            L[bS(L, aux[i])] = aux[i];
        }
    }

    // at this point I have L, it tells me that for L[i], there is a sequence of size i, where
        // L[i] is the largest number in the sequence.

    // dbg(L);
    // dbg(L.size() - 1);
    cout << "Case " << currCase << ": " << L.size() - 1 << endl;
    currCase++;


}

void soln()
{
    int t = 0, n = 0, p = 0, q = 0;
    cin >> t;

    while (t--)
    {
        cin >> n >> p >> q;
        prince.clear();
        princess.clear();
        prince.resize(p + 2);
        princess.resize(q + 2);

        for (int i = 1; i <= p + 1; i++)
            cin >> prince[i];

        for (int i = 1; i <= q + 1; i++)
            cin >> princess[i];

        // dbgB(prince);
        // dbgB(princess);

        LCS(prince, princess);
    }
}

int main()
{
    soln();
}