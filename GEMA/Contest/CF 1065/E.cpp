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


struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

void solve(){
    int n; cin>>n;
    vi vis(n+1, 0);   
    vi primes = {2, 3, 5, 7, 11, 13, 17};
    vi res;

    for(auto p: primes){
        for(int i = p; i <=n; i+= p){
            if(vis[i]) continue;

            vis[i] = 1;
            res.push_back(i);
        }
    }
    
    vi falt;
    rep(i, 1, n+1) if(!vis[i]) falt.push_back(i);

    int j = 0;
    for(int i = 0; i<res.size(); i++){
        cout<<res[i]<<" ";
        if(i <res.size()-1){
            cout<<res[++i]<<" ";
        }

        if(j < falt.size()){
            cout<<falt[j++]<<" ";
        }
    }
    cout<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; cin>>t;

    while(t--)solve();
}