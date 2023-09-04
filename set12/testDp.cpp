using namespace std;
#include <bits/stdc++.h>

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
            if (s[i - 1].suit == t[j - 1].suit && abs(s[i - 1].rank) == abs(t[j - 1].rank))
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

int main(){
    
}