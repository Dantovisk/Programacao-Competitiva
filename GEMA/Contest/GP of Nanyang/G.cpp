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

const int maxn = 1e6+4;
const int inf = 1e9+3;
int dp[5][maxn];
int last[maxn];

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
    //[a, b)
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

void solve(){
    int n; 
    cin>>n;
    rep(i, 0, n+2){
        last[i] = -1;
        rep(j, 0, 5) dp[j][i] = 0;
    }

    vi v(n+1, 0), v1(n+1, 0), v2(n+1, 0);
    rep(i, 1, n+1) {
        cin>>v[i];
    }

    rep(i, 0, n+1){
        v1[i] = v[i];
        if(!v[i]) v1[i] = inf;
        v2[i] = -v[i];
    }

    rep(i, 1, n+1) {
        last[i] = last[i-1];
        if(v[i] != 0) last[i] = v[i];
    }

    RMQ<int> mn(v1), mx(v2);
    rep(i, 0, 5) dp[i][0] = 1;

    for(int i = 1;i<= n; i++){

        //preenchendo de 1 a 4
        // cout<<"to em "<<i<<endl;
        for(int j = 1; j <= 4; j++){
            if(i - j < 0) break;
            // tem q ser tudo 0 OU do numero q vou colocar
            int da = 1;
            rep(df, 0, j){
                if(v[i-df] != 0 and v[i-df] != j){
                    da = 0;
                    break;
                }
            }
            if(!da) continue;
            // cout<<"pra j = "<<j<<", da!"<<endl;

            rep(k, 0, 5){
                if(k == j) continue;
                dp[j][i] = max(dp[j][i], dp[k][i-j]);
            }
        }
        // cout<<"feito"<<endl;

        //preenchendo com um numero maior q 4
        int k = last[i];
        // cout<<"k="<<k<<endl;

        if(k < 5) continue;
        if(i-k < 0) continue;
        int lb = mn.query(i-k+1, i+1);
        int ub = -mx.query(i-k+1, i+1);

        if(ub != lb) continue;
        if(last[i-k] != k){
            dp[0][i] = max(dp[0][i], dp[0][i-k]);
        }

        rep(j, 1, 5){
            dp[0][i] = max(dp[0][i], dp[j][i-k]);
        }
        // cout<<"deu tbm"<<endl;

        
    }


    int r = 0;
    rep(i,0,5){
        r = max(r, dp[i][n]);
    }
    if(!r){
        cout<<"No\n";
    }else{
        vi res;
        cout<<"Yes\n";
        int id = n;
        int lk = -1;
        while(id > 0){
            rep(i, 0, 5){
                if(dp[i][id]){
                    int k = (i == 0? last[id] : i);
                    if(k == lk) continue;
                    rep(i, 0, k) res.push_back(k);
                    id-=k;
                    lk = k;
                    break;
                }
            }
        }
        reverse(all(res));
        for(auto x: res) cout<<x<<" ";
        cout<<"\n";
    }


}

int main() {
	// cin.tie(0)->sync_with_stdio(0);
	// cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}