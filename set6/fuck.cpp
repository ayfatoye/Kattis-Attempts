#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
string str;
cin >> str;
int n = str.length();
vector<pair<int, int>> diffs(n+1);
diffs[0] = make_pair(0, -1); // initialize with dummy values
int sum = 0;
for (int i = 0; i < n; i++) {
    if (str[i] == 'R') sum++;
    else sum--;
    diffs[i+1] = make_pair(sum, i);
}

sort(diffs.begin(), diffs.end()); // sort by R-B difference

int min_abs_diff = n+1;
int best_start = -1;
int best_end = -1;
for (int i = 1; i <= n; i++) {
    int abs_diff = abs(diffs[i].first - diffs[i-1].first);
    if (abs_diff < min_abs_diff) {
        min_abs_diff = abs_diff;
        best_start = min(diffs[i].second, diffs[i-1].second) + 1; // add 1 to convert from 0-based to 1-based indexing
        best_end = max(diffs[i].second, diffs[i-1].second);
    }
}

cout << best_start << " " << best_end+1 << endl; // add 1 to convert back to 0-based indexing

return 0;

}
