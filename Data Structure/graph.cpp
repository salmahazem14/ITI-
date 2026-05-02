//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//    int n;
//    cout << "Enter the number of nodes" << endl;
//    cin >> n;
//    vector<vector<int>> graph(n + 1);
//    int edges;
//
//    cout << "enter the edges" << endl;
//    cin >> edges;
//
//    for (int i = 0; i < edges; i++)
//    {
//        int u, v;
//        cout << "Enter the nodes that has an edge" << endl;
//        cin >> u >> v;
//        graph[u].push_back(v);
//        graph[v].push_back(u);
//    }
//
//    for (int i = 0; i < graph.size(); i++)
//    {
//        for (int j = 0; j < graph[i].size(); j++) {
//            cout << graph[i][j];
//        }
//    }
//    return 0;
//}