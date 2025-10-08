#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5+7;

typedef long long ll;

// soma de sub-conjunto
vector<ll> sos_dp(vector<ll> f) {
	int N = __builtin_ctz(f.size());
	assert((1<<N) == f.size());

	for (int i = 0; i < N; i++) for (int mask = 0; mask < (1<<N); mask++)
		if (mask>>i&1) f[mask] += f[mask^(1<<i)];
	return f;
}

// soma de super-conjunto
vector<ll> sos_dp_inv(vector<ll> f) {
	int N = __builtin_ctz(f.size());
	assert((1<<N) == f.size());

	for (int i = 0; i < N; i++) for (int mask = 0; mask < (1<<N); mask++)
		if (mask>>i&1) f[mask] -= f[mask^(1<<i)];
	return f;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    int k; cin>>k;

    vector<ll> v(1<<k);

    for(int i=0; i<n; i++){
        string a; cin>>a;
        int curr=0;
        for(int j = 0; j<k; j++){
            curr <<=1;
            curr +=(a[j]-'0');
        }
        v[curr]++;
    }

    vector<ll> sos = sos_dp(v);

    vector<ll> comb(1<<k);

    for(int i=0; i<(1<<k); i++){
        comb[i] = sos[i] * (sos[i] - 1) * (sos[i] - 2);
        comb[i] /= 6LL;
    }

    vector<ll> sosinv = sos_dp_inv(comb);

    int q; cin>>q;
    for(int i=0; i<q; i++){
        string a; cin>>a;
        int curr=0;
        for(int j = 0; j<k; j++){
            curr <<=1;
            curr +=(a[j]-'0');
        }
        cout<<sosinv[curr]<<"\n";
    }
}