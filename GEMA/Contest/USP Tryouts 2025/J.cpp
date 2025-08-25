#include <bits/stdc++.h>
#define MAXN 1000010
#define int long long
#define ll long long
const int mod = 1e9+7;

using namespace std;

vector<int> adj[MAXN];

#define pii pair<int,int>

int tin[MAXN];
int vis[MAXN], vis2[MAXN];
int v1[MAXN], v2[MAXN];

int bfs(int start, int end){
    queue <pair<int, int>> q;
    q.push({start, 2});

    vis[start] = 1;
    tin[start] = 2;

    while(!q.empty()){
        auto [u, t] = q.front();
        q.pop();

        int sum = 0;
        if(t == tin[u]){
            if(v1[u]) continue;
            v1[u] = 1; 
            sum = vis[u];
        }
        else{
            if(v2[u]) continue;
            v2[u] = 1; 
            sum = vis2[u];
        }

        //cout<<u<<" : "<<t<<"s - Sum: "<<sum<<"\n";

        int nt = t+1;
        for(auto v: adj[u]){
    
            if(nt == tin[v]){
                vis[v] += sum;
                vis[v] %= mod;
                q.push({v, nt});
            }
            else if(nt == 1 + tin[v]){
                vis2[v]+= sum;
                vis2[v] %= mod;
                q.push({v, nt});
            }
            else if(tin[v] == 0){
                tin[v] = nt;
                vis[v] = sum;
                q.push({v, nt});
            }
        }
    }

    return vis2[end];
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, s, t;
    cin>>n>>m>>s>>t;

    for(int i =0; i<m; i++){
        int a, b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout<<bfs(s, t)<<"\n";

}