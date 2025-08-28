#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define MAXN 200010

vector<pii> adj [MAXN];

const int maxt = 960;
int cost[30], val[30];
int n, M, p;

// min de tempo para obter a felicidade 
// passando pelos pontos da mask e terminando em i
int dp[1100'000][22];
int acum[1100'000];

int dist[22][MAXN];

const int inf = 1e8 + 69;

void dijkstra(int r){
    int s = r;
    if(r == 0) r = n;

    // mask, tempo, u
    priority_queue <pii, vector<pii>,greater<pii>> pq;
    pq.push({0, r});

    for(int i = 1; i<=n; i++){
        dist[s][i] = inf;
    }
    dist[s][r] = 0;

    while(!pq.empty()){
        auto [k, u] = pq.top();
        pq.pop();

        if(dist[s][u] < k) continue;

        for(auto [v, w] : adj[u]){
            if(dist[s][u] + w >= dist[s][v]) continue;
            dist[s][v] = dist[s][u] + w;
            pq.push({dist[s][v], v});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>M>>p;

    for(int i =0; i<M; i++){
        int a, b, w;
        cin>>a>>b>>w;

        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    for(int i =0; i<=p; i++)
        dijkstra(i);



    for(int i =1; i<=p; i++)
        cin>>val[i];
    for(int i =1; i<=p; i++)
        cin>>cost[i];

    int maxr = 0;

    for(int m = 1; m<= ((1<<p)-1); m++){
        for(int i = 1; i<=p; i++){
            dp[m][i] = inf;

            if(!((1<<(i-1)) & m)) continue;
            acum[m] += val[i]; 
        }
        
    }

    for (int st = 1; st <= p; st++){
        int mask = (1<<(st-1));
        dp[mask][st] = dist[0][st] + cost[st];

        if(dp[mask][st] <= maxt) {
            maxr = max(maxr, acum[mask]);
        }

        // cout<<"cost("<<st<<") = "<<dp[mask][st]<<"\n";
    }
    
    for(int m = 1; m<= ((1<<p)-1); m++){
        for(int i = 1; i<= p; i++){
            // cout<<"Estou em "<<m<<" ultimo "<<i<<" = "<<dp[m][i]<<" - "<<acum[m]<<"\n";
            if(!((1<<(i-1)) & m)) continue; // nao passou por i 
            for(int j = 1; j<=p; j++){
                if(((1<<(j-1)) & m)) continue; // ja passou por j 
                int nm = (1<<(j-1)| m);
                int nt = dp[m][i] + dist[i][j] + cost[j];

                dp[nm][j] = min(dp[nm][j], nt);

                // cout<<m<<" "<<nm<<" "<<i<<" "<<j<<" "<<dp[nm][j]<<"\n";
                if(nt <= maxt) {
                    
                    maxr = max(maxr, acum[nm]);
                }
                    
            }
        }
    }
    
    cout<<maxr<<"\n";

}