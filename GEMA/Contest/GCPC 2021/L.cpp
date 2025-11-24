#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define int long long 
#define pb push_back

const int inf = 1e6+1;
const int MAXN = 1e5+5;
int n, m;

vi divs[MAXN];
vector<string> v;
vector<string> a;


void build(vector<vi>& nxt, char c){
    for(int i =0; i<n; i++){
        for(int j = 0; j <m; j++){
            if(v[i][j] == c){
                for(int x = j; x>=0; x--){
                    if(nxt[i][x] != inf) break;
                    nxt[i][x] = j-x+1;
                }
            }
        }
    }
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    cin>>n>>m;

    a.resize(n);
    rep(i, 0, n) cin>>a[i];

    if(n > m){
        v.resize(m);
        rep(i, 0, m) v[i] = "";

        for(int i = 0; i<n; i++){
            for(int j = 0; j< m; j++){
                v[j].push_back(a[i][j]);
            }
        }

        swap(n, m);

        //traspose
    } else{
        v = a;
    }

    vector<vector<vi>> nxt (5, vector<vi>(n+1, vi(m+1, inf)));

    
    build(nxt[0], 'W');
    build(nxt[1], 'A');
    build(nxt[2], 'L');
    build(nxt[3], 'D');
    build(nxt[4], 'O');

    int best = inf;

    // for(auto k : nxt[0]){
    //     for (auto vs: k) cout<<vs<<" ";
    //     cout<<"\n";
    // }

    rep(i, 0, n){
        rep(j, 0, m){
            vi mins(5, inf);
            for(int k = i; k < n; k++){
                rep(x, 0, 5){
                    mins[x] = min(mins[x], nxt[x][k][j]);
                }


                int curr = *max_element(all(mins));

                best = min(best, (k-i+1)*curr);
            }



        }

    }


    if(best == inf) cout<<"impossible\n";
    else cout<<best<<"\n";
}