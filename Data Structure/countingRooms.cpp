using namespace std;
#include<vector>
#include<string>
#include <iostream>

int n, m;
vector<string> grid;
vector<vector<bool>> visited;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool valid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y) {
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (valid(nx, ny) && !visited[nx][ny] && grid[nx][ny] == '.') {
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int rooms = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] == '.') {
                rooms++;
                dfs(i, j);
            }
        }
    }

    cout << rooms << endl;
    return 0;
}
