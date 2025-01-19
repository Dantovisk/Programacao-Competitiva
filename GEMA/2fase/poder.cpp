#include <bits/stdc++.h>
#define pii pair<long long int,long long int>

using namespace std;

long long int n, m;
priority_queue <pair<long long int, pii>, vector<pair<long long int, pii>>, greater<pair<long long int, pii>>> pq;

int main(){
    cin>>n>>m;

    vector <vector<long long int>> dp(n+1, vector<long long int>(m+1, 0));
    vector <vector<long long int>> v(n+1, vector<long long int>(m+1, 0));
    //vector <vector<long long int>> vis(n+1, vector<long long int>(m+1, 0));
    long long int vis[n+1][m+1];

    for(long long int i=0; i < n; i++){
        for(long long int j=0; j < m; j++){
            cin>>v[i][j];
        }
    }
    //ok

    for(long long int i=0; i < n; i++){
        for(long long int j=0; j < m; j++){
            dp[i][j] = v[i][j];
            memset(vis, 0, sizeof(vis));

            vis[i][j] = 1;
            //pq.push({v[i][j], {i, j}});

            long long int dir2[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
            for(auto d: dir2){
                long long int x1 = d[0] + i, y1 = d[1] + j;
                if(x1>=0 && y1>=0 && x1<n && y1<m && !vis[x1][y1]){
                    pq.push({v[x1][y1], {x1, y1}});
                    vis[x1][y1] = 1;
                }
            }

            while(!pq.empty()){
                //long long int pow = pq.top().first;
                long long int x = pq.top().second.first;
                long long int y = pq.top().second.second;
                pq.pop();

                if(v[x][y] <= dp[i][j]){
                    dp[i][j] += v[x][y];
                    
;               } else continue;

                long long int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
                for(auto d: dir){
                    long long int x1 = d[0] + x, y1 = d[1] + y;
                    if(x1>=0 && y1>=0 && x1<n && y1<m && !vis[x1][y1]){
                        pq.push({v[x1][y1], {x1, y1}});
                        vis[x1][y1] = 1;
                    }
                }
            }
        }
    }

    for(long long int i=0; i < n; i++){
        for(long long int j=0; j < m; j++){
            cout<<dp[i][j]<< " ";
        }
        cout<<"\n";
    }
    

    return 0;
}