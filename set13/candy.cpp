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

int gcd(int a, int b) { // the euclid theorem
    a = std::abs(a);
    b = std::abs(b);

    if (a < b) {
        std::swap(a, b);
    }

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

vector<int> EE(int a, int b){ // extended euclid
    a = std::abs(a);
    b = std::abs(b);

    if (a < b) {
        std::swap(a, b);
    }
    vector<int> output(3);
    if(b == 0){
        output[0] = 1; // x prime
        output[1] = 0; // y prime
        output[2] = a; // d
        return output;
    }
    else{
        vector<int> temp = EE(b, (a % b));
        output[0] = temp[1];
        output[1] = temp[0] - (a/b)*(temp[1]);
        output[2] = temp[2];

        return output;       

    }
}

void soln()
{
    int n = 0;
    cin >> n;

    int k = 0;
    int c = 0;

    vector<int> output(3);

    for (int i = 0; i < n; i++)
    {
        output.clear();
        output.resize(3);
        cin >> k >> c;
        if(gcd(k, c) != 1){
            cout << "IMPOSSIBLE\n"; 
            continue;
        }
        else {
            output = EE(k, c);
            int result = output[1];
            int n = -1;
            while(result < 0){
                result = output[1] - k*n;
                n--;
            }
            // cout << result << " " <<output[0] << endl;
            cout << result << endl;
        }
    }
}

int main()
{
    soln();
}