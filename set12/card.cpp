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

unordered_map<char, int> mapy;

class Card
{
public:
    int suit;
    int rank;

    Card(string c)
    {
        if (isdigit(c[0]))
        {
            rank = stoi(string(1, c[0]));
        }
        else
        {
            rank = mapy[c[0]];
        }
        suit = stoi(string(1, c[1]));
    }
};

string intToBinaryString(int n)
{
    string binaryString = "";

    for (int i = 3; i >= 0; i--)
    {
        if (n & (1 << i))
        {
            binaryString += "1";
        }
        else
        {
            binaryString += "0";
        }
    }

    return binaryString;
}

bool card_comp(Card &c1, Card &c2)
{
    if (c1.suit == c2.suit)
    {
        return c1.rank < c2.rank;
    }
    else
    {
        c1.suit < c2.suit;
    }
}

int find_index(const std::vector<int> &vector, int element)
{
    for (int i = 0; i < vector.size(); i++)
    {
        if (vector[i] == element)
        {
            return i;
        }
    }
    return -1;
}

void soln()
{
    mapy['h'] = 1;
    mapy['c'] = 2;
    mapy['s'] = 3;
    mapy['d'] = 4;
    mapy['T'] = 10;
    mapy['J'] = 11;
    mapy['Q'] = 12;
    mapy['K'] = 13;
    mapy['A'] = 14;

    int n = 0;
    cin >> n;

    vector<Card> original(n);

    string temp = "";

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        Card c(temp);
        original.push_back(c);
    }

    string i_bin = "";
    vector<Card> tempGoal;
    int currR = 0;

    vector<int> positions = {1, 2, 3, 4}; // h, c, s, d
    for (int i = 0; i < 16; i++)
    {
        i_bin = intToBinaryString(i);
        tempGoal = original;

        for (int j = 0; j < n; j++)
        {
            currR = find_index(positions, tempGoal[j].suit);
            if (i_bin[currR] == '1')
            {
                tempGoal[j].rank *= -1;
            }
            // if(tempGoal[j].suit == 1){
            tempGoal[j].suit = currR;
            // }
        }
        sort(tempGoal.begin(), tempGoal.end(), card_comp);
        dbg(tempGoal);
    }

    while (next_permutation(positions.begin(), positions.end()))
    {
        // mapy['h'] = find_index(positions, 1);
        // mapy['c'] = find_index(positions, 2);
        // mapy['s'] = find_index(positions, 3);
        // mapy['d'] = find_index(positions, 4);

        for (int i = 0; i < 16; i++)
        {
            i_bin = intToBinaryString(i);
            tempGoal = original;

            for (int j = 0; j < n; j++)
            {
                currR = find_index(positions, tempGoal[j].suit);
                if (i_bin[currR] == '1')
                {
                    tempGoal[j].rank *= -1;
                }
                // if(tempGoal[j].suit == 1){
                tempGoal[j].suit = currR;
                // }
            }
            sort(tempGoal.begin(), tempGoal.end(), card_comp);
            // dbg(tempGoal);
        }
    }
}

int main()
{
    soln();
}