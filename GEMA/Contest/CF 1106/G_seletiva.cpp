#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// #pragma GCC optimize ("Ofast")

const int maxn = 4e6+8;

int qt[15];
int dp[maxn];
int dp2[maxn][2];

map<string, int> id;
string perm;

vector<int> adj[maxn];

int main() {
	// cin.tie(0)->sync_with_stdio(0);
	// cin.exceptions(cin.failbit);

    int n;
    cin>>n;
    
    rep(i, 0, n) perm.push_back('0'+i);

    int cont = 0;

    do{
        id[perm] = cont;
        cont++;
    }while(next_permutation(all(perm)));

    //resetei
    perm.clear();
    rep(i, 0, n) perm.push_back('0'+i);

    if(n < 10){
        do{
            int curr = id[perm];
    
            rep(i, 1, n){
                int l = i-1, r = i;
                while(l >= 0 and r < n){
                    swap(perm[l], perm[r]);
                    int nxt = id[perm];
                    adj[curr].push_back(nxt);
                    l--;
                    r++;
                }
                l = i-1; r = i;
                while(l >= 0 and r < n){
                    swap(perm[l], perm[r]);
                    l--;
                    r++;
                }
    
                if(i+1 >= n) continue;
                l = i-1; r = i+1;
                while(l >= 0 and r < n){
                    swap(perm[l], perm[r]);
                    int nxt = id[perm];
                    adj[curr].push_back(nxt);
                    l--;
                    r++;
                }
                l = i-1; r = i+1;
                while(l >= 0 and r < n){
                    swap(perm[l], perm[r]);
                    l--;
                    r++;
                }
            }
        }while(next_permutation(all(perm)));
    
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        
        
        queue<int> q;
        q.push(0);
    
        while(!q.empty()){
            int u = q.front();
            q.pop();
            qt[dp[u]] ++;
    
            for(auto v: adj[u]){
                if(dp[v] == -1){
                    q.push(v);
                    dp[v] = dp[u] + 1;
                }
            }
        }
        string sla;
        rep(i, 0, n){
            int x; cin>>x;
            x--;
            sla.push_back('0'+x);
        }
    
        cout<<dp[id[sla]]<<"\n";
        
        // cout<<*max_element(all(dp))<<"\n";
        // ll sum = 0;
        // rep(i, 0, n){
        //     cout<<i<<": "<<qt[i]<<"\n";
        //     sum += qt[i];
        // }
        // cout<<sum<<"\n";
        return 0;
    }
    

    // cout<<"indo!\n";
    memset(dp2, -1, sizeof(dp2));
    string sla;
    rep(i, 0, n){
        int x; cin>>x;
        x--;
        sla.push_back('0'+x);
    }

    rep(xd, 0, 2){
        queue <string> q;
        if(xd == 0) {
            dp2[0][0] = 0;
            q.push(perm);
        }
        else {
            dp2[id[sla]][1] = 0;
            q.push(sla);
        }

        while(!q.empty()){
            auto u = q.front();
            q.pop();
            // cout<<"to em "<<u<<"\n";
    
            int curr = id[u];
        
            rep(i, 1, n){
                int l = i-1, r = i;
                while(l >= 0 and r < n){
                    swap(u[l], u[r]);
                    l--;
                    r++;
                    int nxt = id[u];
                    if(dp2[nxt][xd] == -1){
                        dp2[nxt][xd] = dp2[curr][xd] + 1;
                        if(dp2[nxt][xd] < 4){
                            q.push(u);
                        }
                    }
                }
                l = i-1; r = i;
                while(l >= 0 and r < n){
                    swap(u[l], u[r]);
                    l--;
                    r++;
                }
    
                if(i+1 >= n) continue;
                l = i-1; r = i+1;
                while(l >= 0 and r < n){
                    swap(u[l], u[r]);
                    l--;
                    r++;
                    int nxt = id[u];
                    if(dp2[nxt][xd] == -1){
                        dp2[nxt][xd] = dp2[curr][xd] + 1;
                        if(dp2[nxt][xd] < 4){
                            q.push(u);
                        }
                    }
                }
                l = i-1; r = i+1;
                while(l >= 0 and r < n){
                    swap(u[l], u[r]);
                    l--;
                    r++;
                }
            }
        }
    }

    int res = 9;
    int fac = 1;

    rep(i, 2, 11) fac *= i;

    if(dp2[0][1] != -1) res = min(res, dp2[0][1]);

    rep(i, 0, fac){
        
        if(dp2[i][0] != -1 and dp2[i][1] != -1) 
            res = min(res, dp2[i][0] + dp2[i][1]);
    }

    cout<<res<<"\n";
}