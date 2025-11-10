#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 510;
int n, m; 
vi mask;

int adj[MAX][MAX];
int dist[MAX][MAX];



int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    cin>>n>>m;
    mask.resize(n);

    rep(i, 0, n) {
        cin>>mask[i];
        dist[i][i] = mask[i];
    }

    rep(i, 0, m){
        int a, b;
        cin>>a>>b;
        a--; b--;
        // adj[a][b] = 1;

        dist[a][b] = mask[a]&mask[b];
        dist[b][a] = mask[a]&mask[b];
    }


    rep(k, 0, n){
        rep(i, 0, n){
            rep(j, 0, n){
                // if(adj[i][k] == 0 || adj[k][j] == 0) continue;
                int newmask = (dist[i][k] & dist[k][j]);
                dist[i][j] |= newmask;
            }
        }
    }

    rep(i, 0, n){
        rep(j, 0, n){
            cout<<((dist[i][j] > 0) ? 1 : 0);
        }
        cout<<"\n";
    }
}