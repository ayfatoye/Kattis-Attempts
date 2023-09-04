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

using namespace std;

unordered_map<char, int> mapy;

class Card
{
public:
    int suit;
    int rank;
    int origSuit;

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
        suit = mapy[c[1]]; // Use mapy to get suit value
        origSuit = mapy[c[1]];
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
        return c1.suit < c2.suit;
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

void print_cards(vector<Card> &cards)
{
    for (Card &c : cards)
    {
        cout << c.rank;
        if (c.origSuit == 1)
        {
            cout << "h ";
        }
        else if (c.origSuit == 2)
        {
            cout << "c ";
        }
        else if (c.origSuit == 3)
        {
            cout << "s ";
        }
        else if (c.origSuit == 4)
        {
            cout << "d ";
        }
    }
    cout << endl;
}

int dyno(vector<Card> &s, vector<Card> &t)
{
    int s_size = s.size() + 1;
    int t_size = t.size() + 1;
    vector<vector<int>> dp(s_size, vector<int>(t_size));

    for (int j = 0; j < t_size; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 0; i < s_size; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 1; i < s_size; i++)
    {
        for (int j = 1; j < t_size; j++)
        {
            if (s[i - 1].origSuit == t[j - 1].origSuit && abs(s[i - 1].rank) == abs(t[j - 1].rank))
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[s.size()][t.size()];
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

    vector<Card> original; 

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
    int maxMoves = 0;

    vector<int> positions = {1, 2, 3, 4}; // h, c, s, d
    for (int i = 0; i < 16; i++)
    {
        // maxMoves = 0;
        i_bin = intToBinaryString(i);
        tempGoal = original;

        for (int j = 0; j < n; j++)
        {
            currR = find_index(positions, tempGoal[j].suit);
            if (i_bin[currR] == '1')
            {
                tempGoal[j].rank *= -1;
            }
            tempGoal[j].suit = currR;
        }
        sort(tempGoal.begin(), tempGoal.end(), card_comp);
        // print_cards(tempGoal);
        // if(dyno(original, tempGoal) > maxMoves)
            // dbg(maxMoves);
        maxMoves = max(maxMoves, dyno(original, tempGoal));
    }

    while (next_permutation(positions.begin(), positions.end()))
    {
        for (int i = 0; i < 16; i++)
        {
            // maxMoves = 0;
            i_bin = intToBinaryString(i);
            tempGoal = original;

            for (int j = 0; j < n; j++)
            {
                currR = find_index(positions, tempGoal[j].suit);
                if (i_bin[currR] == '1')
                {
                    tempGoal[j].rank *= -1;
                }
                tempGoal[j].suit = currR;
            }
            sort(tempGoal.begin(), tempGoal.end(), card_comp);
            // print_cards(tempGoal);
            // if(dyno(original, tempGoal) > maxMoves)
                // dbg(maxMoves);
            maxMoves = max(maxMoves, dyno(original, tempGoal));
        }
    }

    // dbg(maxMoves);
    cout << n - maxMoves << endl;
}

int main()
{
    soln();
}
