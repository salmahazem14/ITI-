#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int curr) {
    visited[curr] = true;

    for (int nxt : graph[curr]) {
        if (!visited[nxt])
            dfs(nxt);
    }
}

//int main() {
//    int n, edges;
//
//    cout << "Enter the number of nodes: ";
//    cin >> n;
//
//    n++;
//
//    graph.resize(n);
//    visited.assign(n, false);
//
//    cout << "Enter the number of edges: ";
//    cin >> edges;
//
//    for (int i = 0; i < edges; i++) {
//        int u, v;
//        cout << "Enter the edge (u v): ";
//        cin >> u >> v;
//        graph[u].push_back(v);
//        graph[v].push_back(u);
//    }
//
//    int components = 0;
//
//    for (int i = 1; i < n; i++) {  
//        if (!visited[i]) {
//            dfs(i);
//            components++;
//        }
//    }
//
//    cout << "Number of connected components: " << components << endl;
//
//    return 0;
//}
