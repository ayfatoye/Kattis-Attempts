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

class node
{
public:
    bool isin;
    node *ch[26];

    node()
    {
        isin = false;
        for (int i = 0; i < 26; i++)
            ch[i] = NULL;
    }

    void add(string s)
    {
        if (s.length() == 0)
        {
            isin = true;
            return;
        }
        char c = s[0];
        if (ch[c - 'a'] == NULL)
        {
            ch[c - 'a'] = new node();
        }
        string s2 = s.substr(1);
        ch[c - 'a']->add(s2);
    }
};

// another implementation of the trie:

// class node
// {
// public:
//     bool isin;
//     node *ch[26];
//     int counter;

//     node()
//     {
//         isin = false;
//         for (int i = 0; i < 26; i++)
//             ch[i] = NULL;

//         counter = 0;
//     }

//     void add(string& s, int ind = -1)
//     {
//         counter++;
//         if(ind + 1 < s.size()){
//             if(ch[s[ind + 1] - 'a'] == NULL){
//                 ch[s[ind + 1] - 'a'] = new node();
//             }
//             ch[s[ind + 1] - 'a']->add(s, ind + 1);
//         }
//         else{
//             isin = true;
//             return;
//         }

        
//         // if (ind == s.size() - 1)
//         // {
//         //     isin = true;
//         //     return;
//         // }
//         // char c = s[0];
//         // if (ch[c - 'a'] == NULL)
//         // {
//         //     ch[c - 'a'] = new node();
//         // }
//         // string s2 = s.substr(1);
//         // ch[c - 'a']->add(s2);
//     }

//     int find(string& s, int ind = -1){
//         if(ind+1 == s.size())
//             return counter;
        
//         else {
//             if(ch[s[ind+1] - 'a'] == NULL){
//                 return 0;
//             }
//             return ch[s[ind+1] - 'a']->find(s, ind+1);
//         }
//     }
// };

int main()
{

}