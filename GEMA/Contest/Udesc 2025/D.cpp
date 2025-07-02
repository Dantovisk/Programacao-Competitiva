#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

int n, m;

int solve(vector<vector<int>>& vec, int a, int b){
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int res = 0;
    int exc = 0;

    for(int i = 30; i>=0; i--){
        queue<pair<int,int>> q;

        bool achou = false;
        vector<vector<int>> vis (n+1, vector<int>(m+1, 0));

        q.push({a, b});
        vis[a][b] = 1;
        while(!q.empty()){
            auto [u, v] = q.front();
            q.pop();
            
            if(u == n && v == m){
                achou = true; break;
            }

            for(auto d: dir){
                int nu = u + d[0], nv = v + d[1];
                if(nu <1 || nv <1 || nu>n || nv>m) continue;
                if(vis[nu][nv]) continue;

                if((1<<i) & (vec[nu][nv])) continue;
                if( exc & (vec[nu][nv])) continue;

                q.push({nu, nv});
                vis[nu][nv] = 1;
            }
        }

        if(!achou) res += (1<<i);
        else exc += (1<<i);
    }
    return res;

}

int32_t main(){
    cin>>n>>m;

    int x, y;
    cin>>x>>y;

    vector<vector<int>> v (n+2, vector<int>(m+2, 0));
    for(int i =1; i<=n; i++){
        for(int j =1; j<=m; j++){
            cin>>v[i][j];
        }
    }

    cout<<solve(v, 1, 1)<<" ";
    cout<<solve(v, x, y)<<"\n";
    

}