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

/**
 * Author: Lukas Polacek
 * Date: 2009-10-30
 * License: CC0
 * Source: folklore/TopCoder
 * Description: Computes partial sums a[0] + a[1] + ... + a[pos - 1], and updates single elements a[i],
 * taking the difference between the old and new value.
 * Time: Both operations are $O(\log N)$.
 */
struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll neww) { // a[pos] = neww
		for (; pos < sz(s); pos |= pos + 1) s[pos] = max(s[pos], neww);
	}
	ll query(int pos) { // max of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res = max(s[pos-1], res);
		return res;
	}
};

int divs(int a, int b){
    int ct = 0;

    while(a >= b && a%b==0){
        a/=b;
        ct++;
    }
    return ct;
}

void solve(){
    int n, m; cin>>n>>m;

    FT ft = FT(m+1);


    for(int i = 2; i<=n; i++){
        //pega o maior multiplo de i e vai descendo
        for(int j = (m-n+i)/i * i; j>= i; j -= i){
            int off = j-i;
            int score = ft.query(off+1) + divs(j, i);

            ft.update(off, score);
        }
    }

    cout<<ft.query(m-n+1)<<"\n";
    
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; cin>>t;

    while(t--)solve();
}