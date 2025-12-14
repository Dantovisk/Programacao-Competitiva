#include <bits/stdc++.h> 
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


typedef unsigned long long ull;
ull MOD = 2;

ull modmul(ull a, ull b, ull M = MOD) {
	ll ret = a * b - M * ull(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod = MOD) {
	ull ans = 1;
	for (; e; b = modmul(b, b, mod), e /= 2)
		if (e & 1) ans = modmul(ans, b, mod);
	return ans;
}

ull inv(ull a, ull mod = MOD){
    return modpow(a, mod-2, mod);
}

void solve(){
    ull n, c, mod; cin>>n>>c>>mod;

    MOD = mod;

    //probabilidades de palindromos de tamanho i
    vector<ull> P(n+1, 0);
    for(int i = 1; i<= n; i++){
        ull aux = modpow(c, i/2, mod);
        P[i] = inv(aux, mod);
    }

    //soma da probabilidade dos caras de tamanho par x sua quantidade
    ull resp = 0;
    
    for(int i = 1; i<= n; i++){
        ull aux = modmul(P[i], (n-i+1), mod);
        resp = (resp + aux)%mod;
    }

    resp = modmul(resp, resp, mod);

    // Falta corrigir os termos concentricos
    // Certo - errado = P(L) - P(L)*P(l) = P(L)(1 - P(l))
    ull erropar = 0, erroimpar = 0;

    for(int i = 1; i<= n; i++){
        ull pl = P[i];

        ull corr = 0;

        ull erro = (1 + mod - pl) % mod;

        if(i % 2){
            corr = modmul(2, erroimpar);
            erroimpar = (erroimpar+erro)%mod;
        }
        else{
            corr = modmul(2, erropar);
            erropar = (erropar+erro)%mod;
        }
        corr = (corr + erro)%mod;

        corr = modmul(pl, corr);

        resp = (resp + modmul(corr, n-i+1)) % mod;
    }


    cout<<resp<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;

    while(n--) solve();
}