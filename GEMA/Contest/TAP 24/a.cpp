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

const int maxn = 2e5+4;
const int inf = 1e9+3;

#define S3(x, y, z) { if(x && x == y && x == z) return x;}


int n;

int dep[9];
int dp[19683+10]; // 3^9

vector<vi> dbgst;

int win(vi &st) {
    rep(i, 0, 3) {
        S3(st[3*i], st[3*i+1], st[3*i+2])
        S3(st[i], st[i+3], st[i+6]);
    }
    S3(st[0], st[4], st[8]);
    S3(st[2], st[4], st[6]);
    return 0;
}

int dfs(vi &st) {
    int dpid = 0;
    for(int x: st) {
        dpid = 3*dpid + x;
    }

    if(dp[dpid] != -1) return dp[dpid];

    int w = win(st);
    if(w) return dp[dpid] = w;

    int cp = 0, used = 0;
    rep(i, 0, 9) {
        if(st[i]) {
            cp ^= 1;
            used |= 1 << i;
        }
    }
    cp++;

    int fl0 = 0, tem = 0;
    rep(i, 0, 9) if(st[i] == 0) {
        if((dep[i] & used) == dep[i]) {
            vi st2 = st;
            st2[i] = cp;

            tem = 1;

            int sla = dfs(st2);
            if(sla == cp) return dp[dpid] = cp;
            if(sla == 0) fl0 = 1;
        }
    }

    if(fl0 || !tem) return dp[dpid] = 0;
    else return dp[dpid] = (cp == 1 ? 2 : 1);
}

void solve(){
    cin >> n;
    rep(i, 0, n) {
        int pai, f;
        cin >> pai >> f;
        pai--; f--;

        dep[f] |= 1 << pai; 
    }

    memset(dp, 0xff, sizeof(dp));

    vi st(9, 0);
    int r = dfs(st);

    int i = 0;
    for(auto st: dbgst) {
        int dpid = 0;
        for(auto x: st) dpid = 3*dpid + x;

        cerr << "st " << i << " " << dp[dpid] << endl;
        i += 1;
    }
    if(r == 0) cout << "E\n";
    else if(r == 1) cout << "X\n";
    else cout << "O\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
 
    // cin>>t;
//            0,1,2,3,4,5,6,7,8
    /*dbgst.pb({0,0,0,0,0,0,1,0,0});
    dbgst.pb({0,0,2,0,0,0,1,0,0});
    dbgst.pb({1,0,2,0,0,0,1,0,0});
    dbgst.pb({1,0,2,2,0,0,1,0,0});
    dbgst.pb({1,0,2,2,0,0,1,0,1});*/
    //dbgst.pb({0,0,0,0,0,0,0,0,0});
    while(t--) solve();
}