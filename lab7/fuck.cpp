#include <bits/stdc++.h>
using namespace std;
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define WHITE   "\033[1;37m"
#define NC      "\033[0m"
#define dbg(x) cerr<<RED<<#x<<" = "<<x<<NC<<endl
typedef long long ll;
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::pair<T1, T2>& pair) {
    return out << '(' << pair.first << ", " << pair.second << ')';
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec) {
    if(vec.empty()) return out << "[]";
    out << '[';
    for(size_t i = 0; i < vec.size()-1; i++) out << vec.at(i) << ", ";
    return out << vec.back() << ']';
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<vector<pair<int,int>>> adj_list(n+1);
	unordered_map<int,int> map;

	for(int i = 1; i <= n; i++) {
		int m; cin >> m;
		while(m--) {
			int d; cin >> d;
			if(map.find(d) == map.end()) {
				map[d] = i;
			} else {
				adj_list[i].push_back(make_pair(d, map[d]));
				adj_list[map[d]].push_back(make_pair(d, i));
			}
		}
	}
    dbg(adj_list);

	queue<int> q;
	vector<bool> visited(n+1);
	vector<int> output;
	int vertex = 1;
	visited[vertex] = true;
	q.push(vertex);

	while(!q.empty()) {
		vertex = q.front(); q.pop();
		for(int i = 0; i < adj_list[vertex].size(); i++) {
			int other = adj_list[vertex][i].second;
			int relate = adj_list[vertex][i].first;
			if(!visited[other]) {
				visited[other] = true;
				output.push_back(vertex);
				output.push_back(other);
				output.push_back(relate);
                dbg(other);
				q.push(other);
                dbg(q.front());
			}
		}
	}

	if(output.size() != 3 * (n - 1)) {
		cout << "impossible" << endl;
	} else {
		for(int i = 0; i < output.size(); i += 3) {
			cout << output[i] << " " << output[i+1] << " " << output[i+2] << endl;
		}
	}
}