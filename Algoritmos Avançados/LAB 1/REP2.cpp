#include <bits/stdc++.h>
using namespace std;

//primo para imprimir a resposta %primo
const int mod = 1e9+7;

//tamanho max da entrada
const int maxn = 2e5+3;


// usa uma Fenwick Tree para manter quantos sequências com final
// menor que v2[i] já apareceram
struct FT {
	vector<int> soma;
	FT(int n) : soma(n) {}
	void update(int pos, int dif) { // a[pos] += dif
		for (; pos < soma.size(); pos |= pos + 1) {
            soma[pos] += dif;
            soma[pos] %= mod;
        }
	}
	int query(int pos) { // soma dos valores em [0, pos)
		int res = 0;
		for (; pos > 0; pos &= pos - 1) {
            res += soma[pos-1];
            res %= mod;
        }
		return res;
	}
};

void solve(){
    int n; cin>>n;

    vector<int> v(n), v2(n);
    
    // aparentemente as entradas podem ter números grandes ou negativos,
    // então vamos comprimir coordenadas para o intervalo [1, 2*10^5]
    set<int> vis;
    map<int, int> numbId; //mantém a coordenada comprimida do numero original
    
    for(int i = 0; i< n; i++){
        cin>>v[i];
        vis.insert(v[i]);
    }
    
    int currId = 0;
    for(auto x: vis){
        numbId[x] = ++currId;
    }

    for(int i = 0; i< n; i++){
        v2[i] = numbId[v[i]];
    }


    FT ft(maxn);
    //tem uma forma de começar com uma sequência nula :)
    ft.update(0, 1);

    for(int i = 0; i< n; i++){
        int currqt = ft.query(v2[i]);
        ft.update(v2[i], currqt);
    }

    // A soma de todas as sequências crescentes terminadas 
    // em todos os valores de 1 até 2*10^5.
    // nulo não é uma sequencia valida => subtrai 1
    cout<<(ft.query(maxn) - 1 + mod) % mod <<"\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t = 1;
    // cin>>t;

    for(int i = 0; i<t; i++){
        solve();
    }

}