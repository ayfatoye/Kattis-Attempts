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

int cnt = 0;

int pFactors(int currNum)
{
    cnt++;
    int newNum = 0;
    // int tryThis = 2;
    while (currNum % 2 == 0)
    {
        newNum += 2;
        // dbg(newNum);
        currNum /= 2;
    }
    // cout << "41" << endl;

    for (int i = 3; i <= sqrt(currNum); i += 2)
    {
        while (currNum % i == 0)
        { // true if equal to zero
            newNum += i;
            // dbg(newNum);
            currNum /=  i;
        }
    }

    if(currNum > 2){
        // cout << "she said yes\n";
        newNum += currNum;
        // return currNum;
    }


    // supposedly logn:
    // while(tryThis > 1){
    //     if(currNum % tryThis == 0){
    //         // cout << tryThis << " ";
    //         newNum += tryThis;
    //         currNum /= tryThis;
    //     }
    //     else{
    //         tryThis++;
    //     }
    // }

    return newNum;
}

void solveThisShit(int n){
    cnt = 0;
    int temp = n;
    int temp2 = pFactors(n);

    while(temp != temp2){
        temp = temp2;
        temp2 = pFactors(temp2);
    }

    // if(temp == temp2){
    //     cout << n << " " << cnt << endl;
    // }
    // else{
    //     temp = temp2;
    // }
    cout << temp << " " << cnt << endl;

    
}

void soln()
{
    int n = 0;
    int temp = 0;
    

    while (cin >> n)
    {
        if (n == 4)
            return;

        if(n == 2){
            cout << "2 1\n";
            continue;
        }

        solveThisShit(n);  
    }


    // testing:
    // cin >> n;
    // cout << pFactors(n) << endl;
}

int main()
{
    soln();
}