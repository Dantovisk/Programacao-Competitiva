#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define ff first
#define ss second
#define pb push_back


void solve1(){
    int n, m;
    cin>>n>>m;

    vector<vi> adj(n+1);
    vi vis(n+1, -1);

    rep(i, 0, m){
        int a, b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vis[1] = 0;
    queue<int> q;
    q.push(1);

    while(!q.empty()){
        auto u = q.front();
        q.pop();

        for(auto v: adj[u]){
            if(vis[v] != -1) continue;

            vis[v] = (vis[u]+1)%3;
            q.push(v);
        }
    }

    string uai = "rgb";
    rep(i, 1, n+1) cout<<uai[vis[i]];
    cout<<"\n";
}

void solve2(){
    int q; cin>>q;

    rep(i, 0, q){
        int n; cin>>n;
        string a; cin>>a;

        int r, g, b;
        r = g = b = 0;

        for(auto c: a){
            if(c == 'r') r = 1;
            if(c == 'g') g = 1;
            if(c == 'b') b = 1;
        }

        if(r + g + b == 1){
            cout<<"1\n";
        }
        else if(b == 0){
            for(int i = 0; i< n; i++){
                if(a[i] == 'g') {
                    cout<<i+1<<"\n";
                    break;
                }
            }
        }
        else if(g == 0){
            for(int i = 0; i< n; i++){
                if(a[i] == 'r') {
                    cout<<i+1<<"\n";
                    break;
                }
            }
        }
        else if(r == 0){
            for(int i = 0; i< n; i++){
                if(a[i] == 'b') {
                    cout<<i+1<<"\n";
                    break;
                }
            }
        }
        else{
            for(int i = 0; i< n; i++){
                if(a[i] == 'r') {
                    cout<<i+1<<"\n";
                    break;
                }
            }
        }
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    string tipo; int t = 1; 
    cin>>tipo>>t;

    if(tipo == "first") while(t--)solve1();
    else while(t--)solve2();
}