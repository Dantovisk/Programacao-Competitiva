#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 1e6+8;

char meb[MAX];
void crivo(int lim = 1'000'005) {
	for (int i = 2; i <= lim; i++) meb[i] = 2;
	meb[1] = 1;
	for (int i = 2; i <= lim; i++) if (meb[i] == 2)
		for (int j = i; j <= lim; j += i) if (meb[j]) {
			if (meb[j] == 2) meb[j] = 1;
            
			meb[j] *= j/i%i ? -1 : 0;
		}
}

int cnt[MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    crivo();
    int n; cin>>n;

    vi v(n);
    rep(i, 0, n){
        cin>>v[i];
        cnt[v[i]]++;
    } 

    map<int, vi> divs;

    ll resp = 0;

    rep(i, 1, 1e6+1){
        if(meb[i] == 0) continue;
        ll k = 0;
        for(int j = i; j<= 1e6+1; j+=i){
            k += cnt[j];
        }

        ll u = (k)*(k-1)/2;

        resp += u*meb[i];
    }

    cout<<resp<<"\n";
}