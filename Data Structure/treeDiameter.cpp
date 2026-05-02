#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<int> visited;
int farNode;
int maxDepth;

void dfs(int curr, int depth) {
    visited[curr] = 1;

    if (depth > maxDepth) {
        maxDepth = depth;
        farNode = curr;
    }

    for (int nxt : graph[curr]) {
        if (!visited[nxt]) {
            dfs(nxt, depth + 1);
        }
    }
}

int bfs(int start) {
    vector<int> distance(graph.size(), -1);
    queue<int> q;

    distance[start] = 0;
    q.push(start);

    int maxDist = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int nxt : graph[curr]) {
            if (distance[nxt] == -1) {
                distance[nxt] = distance[curr] + 1;
                maxDist = max(maxDist, distance[nxt]);
                q.push(nxt);
            }
        }
    }

    return maxDist;
}

int main() {
    int n;
    cin >> n;

    graph.assign(n + 1, {});
    visited.assign(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    maxDepth = -1;
    dfs(1, 0);

    int diameter = bfs(farNode);

    cout << diameter << endl;
    return 0;
}
