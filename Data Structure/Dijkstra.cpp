#include <vector>
#include<queue>
#include <iostream>
using namespace std;

const long long INF = 1e18;

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, long long>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        adj[a].push_back({ b, c });
    }

    vector <long long> dist(n + 1, INF);
    dist[1] = 0;

    priority_queue <pair <long long, int> , vector<pair<long long, int>>,
        greater<pair<long long, int>>> pq;

    pq.push({ 0, 1 });

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        long long d = top.first;
        int u = top.second;

        if (d != dist[u]) continue;

        for (auto& p : adj[u]) {
            int v = p.first;
            long long w = p.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({ dist[v], v });
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}
