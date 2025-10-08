#include <bits/stdc++.h>

using namespace std;

const int M = 24;
const int MAX = 2e5+7;

typedef int ll;

// soma de sub-conjunto
vector<ll> sos_dp(vector<ll> f) {
	int N = __builtin_ctz(f.size());
	assert((1<<N) == f.size());

	for (int i = 0; i < N; i++) for (int mask = 0; mask < (1<<N); mask++)
		if (mask>>i&1) f[mask] += f[mask^(1<<i)];
	return f;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;

    vector<ll> v((1<<M), 0);

    for(int i = 0; i<n; i++){
        string a; cin>>a;
        int acum = 0;
        for(char c : a){
            acum |= (1<<(c-'a'));
        }
        v[acum] ++;
    }

    int xorsum = 0;

    vector<ll> sos = sos_dp(v);
    int tudo = (1<<M)-1;

    for(int i =0; i<(1<<M); i++){
        int comp = tudo^i;

        int res = n - sos[comp];
        xorsum ^=(res*res);
    }

    cout<<xorsum<<"\n";

}