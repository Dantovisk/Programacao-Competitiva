#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5+7;

typedef long long ll;
int v[MAX];

// soma de sub-conjunto
vector<ll> sos_dp(vector<ll> f) {
	int N = __builtin_ctz(f.size());
	assert((1<<N) == f.size());

	for (int i = 0; i < N; i++) for (int mask = 0; mask < (1<<N); mask++)
		if (mask>>i&1) f[mask] += f[mask^(1<<i)];
	return f;
}

// soma de super-conjunto
vector<ll> sos_dp2(vector<ll> f) {
	int N = __builtin_ctz(f.size());
	assert((1<<N) == f.size());

	for (int i = 0; i < N; i++) for (int mask = 0; mask < (1<<N); mask++)
		if (~mask>>i&1) f[mask] += f[mask^(1<<i)];
	return f;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;

    int k = 20;
    int maxn = (1<<k);

    vector<ll> dp1(maxn, 0);
    vector<ll> dp2(maxn, 0);

    for(int i =0; i<n; i++){
        cin>>v[i];
        dp1[v[i]] ++;
        dp2[v[i]] ++;
    }


    dp1 = sos_dp(dp1);
    dp2 = sos_dp2(dp2);

    int tudo = ((1<<k)-1);
    for(int i =0; i<n; i++){

        int comp = (tudo^v[i]);

        cout<<dp1[v[i]]<<" "<<dp2[v[i]]<<" "<<(n-dp1[comp])<<"\n";
    }

}