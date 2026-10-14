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

const int maxn = 1e4+4;
const int inf = 1e9+3;

int g[110][110];
int dest[maxn];
int u[maxn];
int d[maxn];
int l[maxn];
int r[maxn];

int n; 
int hor(int a, int b){
    return (a-1)/n == (b-1)/n;
}
int vert(int a, int b){
    return abs(a-b) % n == 0;
}

void solve(){
    cin>>n;

    rep(i, 1, n+1){
        rep(j, 1, n+1){
            int pos = (i-1)*n + j;
            cin>>g[i][j];
            dest[g[i][j]] = pos;
        }
    }

    rep(i, 1, n+1){
        rep(j, 1, n+1){
            int pos = (i-1)*n + j;
            int dif = dest[pos] - pos;
            // cout<<"to em "<<pos<<"\n";

            //desce
            if(dif > 0 and (abs(dif) % n == 0)){
                // cout<<"d!\n";
                if(d[dest[pos]]){
                    cout<<"No\n";
                    return;
                }
                for(int k = pos; k<= dest[pos]; k+= n){
                    d[k] = 1;
                }
            }
            //vai p direita
            else if(dif > 0 and hor(pos, dest[pos])){
                // cout<<"r!\n";
                if(r[dest[pos]]){
                    cout<<"No\n";
                    return;
                }
                for(int k = pos; k<= dest[pos]; k++){
                    r[k] = 1;
                }
            }
            else if(abs(dif) > 0 and !hor(pos, dest[pos]) and !vert(pos, dest[pos])){
                cout<<"No\n";
                return;
            }
        }
    }

    for(int i = n; i> 0; i--){
        for(int j = n; j>0; j--){
            int pos = (i-1)*n + j;
            int dif = dest[pos] - pos;
            // cout<<"to em "<<pos<<"\n";

            //sobe
            if(dif < 0 and (abs(dif) % n == 0)){
                // cout<<"u!\n";
                if(u[dest[pos]]){
                    cout<<"No\n";
                    return;
                }
                for(int k = pos; k >= dest[pos]; k-= n){
                    u[k] = 1;
                }
            }
            //vai p esquerda
            else if(dif < 0 and hor(pos, dest[pos])){
                // cout<<"l!\n";
                if(l[dest[pos]]){
                    cout<<"No\n";
                    return;
                }
                for(int k = pos; k >= dest[pos]; k--){
                    l[k] = 1;
                }
            }
        }
    }

    rep(i, 1, n+1){
        rep(j, 1, n+1){
            int pos = (i-1)*n + j;
            if(u[pos] and d[pos]){
                cout<<"No\n";
                return;
            }
            if(l[pos] and r[pos]){
                cout<<"No\n";
                return;
            }
            if(pos == dest[pos] and 
                ((u[pos] or d[pos]) and (l[pos] or r[pos]))){
                cout<<"No\n";
                return;
            }
        }
    }

    cout<<"Yes\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    // cin>>t;

    while(t--) solve();
}