#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(100010);
queue<int> q;
bool vis[100010];
int parent[100010];
int n, m;

void bfs(int start) {
    vis[start] = true;
    q.push(start);

    while (!q.empty()) {
        int a = q.front();
        q.pop();

        //aqui encontrou o ponto de destino
        if (a == n) {
            vector<int> path;
            for (int v = n; v != 0; v = parent[v]) {
                path.push_back(v);
            }
            reverse(path.begin(), path.end());
            cout << path.size() << endl;
            for (int v : path) {
                cout << v << " ";
            }
            cout << endl;
            return;
        }

        for (int x : adj[a]) {
            if (!vis[x]) {
                vis[x] = true;
                parent[x] = a;
                q.push(x);
            }
        }
    }

    // Se o destino nao for encontrado
    cout << "IMPOSSIBLE" << endl;
}

int main() {
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //memset(parent, 0, sizeof(parent));
    bfs(1);

    return 0;
}