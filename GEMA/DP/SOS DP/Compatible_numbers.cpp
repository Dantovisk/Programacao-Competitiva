#include <bits/stdc++.h>

using namespace std;

const int M = 24;

typedef int ll;

// soma de sub-conjunto
vector<ll> sos_dp(vector<ll> f) {
	int N = __builtin_ctz(f.size());
	assert((1<<N) == f.size());

	for (int i = 0; i < N; i++) for (int mask = 0; mask < (1<<N); mask++)
		if (mask>>i&1) f[mask] = max(f[mask], f[mask^(1<<i)]);
	return f;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;

    vector<ll> v((1<<M), -1);
    vector<int> q(n);

    for(int i = 0; i<n; i++){
        cin>>q[i];
        v[q[i]] = q[i];
    }

    vector<ll> sos = sos_dp(v);
    int tudo = (1<<M)-1;

    for(auto x: q){
        int comp = tudo^x;

        cout<<sos[comp]<<" ";
    }
}