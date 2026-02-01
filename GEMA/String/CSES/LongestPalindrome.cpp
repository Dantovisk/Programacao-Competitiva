#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


array<vi, 2> manacher(const string& s) {
	int n = sz(s);
	array<vi,2> p = {vi(n+1), vi(n)};
	rep(z,0,2) for (int i=0,l=0,r=0; i < n; i++) {
		int t = r-i+!z;
		if (i<r) p[z][i] = min(t, p[z][l+t]);
		int L = i-p[z][i], R = i+p[z][i]-!z;
		while (L>=1 && R+1<n && s[L-1] == s[R+1])
			p[z][i]++, L--, R++;
		if (R>r) l=L, r=R;
	}
	return p;
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    string a;
    cin>>a;


    array<vi, 2> pal = manacher(a);

    int res = max(*max_element(all(pal[0])), *max_element(all(pal[1])));

    // for(auto k: pal[0]) cout<<k<<" ";
    // cout<<"\n";
    rep(i, 0, sz(a)){
        if(pal[1][i] == res){
            cout<<a.substr(i-res, 1+2*res)<<"\n";
            return 0;
        }
    }

    rep(i, 0, sz(a)){
        if(pal[0][i] == res){
            cout<<a.substr(i-res, 2*res)<<"\n";
            return 0;
        }
    }

}
