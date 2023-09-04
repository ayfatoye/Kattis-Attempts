#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

const int INF = 1e9;

void floyd_warshall(vector<vector<int>>& distances, int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (distances[i][k] < INF && distances[k][j] < INF) {
                    distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
                }
            }
        }
    }
}

bool all_reachable(const vector<vector<int>>& distances, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && distances[i][j] == INF) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m, case_number = 1;
    while (cin >> n >> m) {
        vector<vector<int>> distances(n, vector<int>(n, INF));
        vector<tuple<int, int, int>> edges;

        for (int i = 0; i < n; i++) {
            distances[i][i] = 0;
        }

        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            distances[u][v] = w;
            edges.emplace_back(u, v, w);
        }

        floyd_warshall(distances, n);

        bool found = false;
        for (const auto& [u, v, w] : edges) {
            if (distances[u][v] != INF && distances[v][u] == INF) {
                swap(distances[u][v], distances[v][u]);
                floyd_warshall(distances, n);

                if (all_reachable(distances, n)) {
                    cout << "Case " << case_number << ": " << u << ' ' << v << endl;
                    found = true;
                    break;
                }

                swap(distances[u][v], distances[v][u]);
            }
        }

        if (!found) {
            cout << "Case " << case_number << ": -1" << endl;
        }

        case_number++;
    }

    return 0;
}
