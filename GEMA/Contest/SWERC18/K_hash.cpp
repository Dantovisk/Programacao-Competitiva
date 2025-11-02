#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// [l, r] usando a tecnica 
const int inf = 1e6+7;

typedef uint64_t ull;
struct H {
	ull x; H(ull x=0) : x(x) {}
	H operator+(H o) { return x + o.x + (x + o.x < x); }
	H operator-(H o) { return *this + ~o.x; }
	H operator*(H o) { auto m = (__uint128_t)x * o.x;
		return H((ull)m) + (ull)(m >> 64); }
	ull get() const { return x + !~x; }
	bool operator==(H o) const { return get() == o.get(); }
	bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)1e11+3; // (order ~ 3e9; random also ok)

struct HashInterval {
	vector<H> ha, pw;
	HashInterval(string& str) : ha(sz(str)+1), pw(ha) {
		pw[0] = 1;
		rep(i,0,sz(str))
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	H hashInterval(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    
    int n; cin>>n;
    string a;
    cin>>a;

    HashInterval hash =  HashInterval(a);
    
    //start, sz
    vector <vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int i = 0; i<n; i++){
        dp[i][i] = 1;
        // cout<<dp[i][i]<<"\n";

        // cout<<(char)hash.hashInterval(i, i+1).x<<"\n";
    }

    for(int sz = 2; sz<=n; sz++){
        for(int i = 0; i<n-sz+1; i++){
            int u = inf;

            int j = i+sz-1;

            //concatenação
            for(int k = i; k<j; k++){
                if(hash.hashInterval(i, k+1) == hash.hashInterval(k+1, j+1)) {
                    if(dp[i][k] < u){
                        dp[i][j] = dp[i][k];
                        u = dp[i][j];

                        // cout<<i<<" - "<<k<<" = "<<k+1<<" - "<<j<<", -> "<<dp[i][j]<<"\n";
                    }
                }else if(u > dp[i][k] + dp[k+1][j]){
                    dp[i][j] = dp[i][k] + dp[k+1][j];
                    u = dp[i][j];
                }
            }

            for(int v = 1; v <= sz/2; v++){
                if(sz % v) continue;
                if(dp[i][i+v-1] >= u) continue;

                bool mogou = false;
                H ha = hash.hashInterval(i, i+v);
                for(int xd = i+v; xd < i+sz; xd+=v){
                    if(!(hash.hashInterval(xd, xd+v) == ha)){
                        mogou = true;
                        break;
                    }
                }
                if(mogou) continue;

                // cout<<"Foi! "<<i<<" "<<j<<"\n";

                dp[i][j] = dp[i][i+v-1];
                u = dp[i][j];
                break;
            }

        }
    }

    // cout<<dp[0][n-1]<<"\n";
    cout<<dp[0][n-1]<<"\n";
}