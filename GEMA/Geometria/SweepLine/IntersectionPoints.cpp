#include <bits/stdc++.h> //Intersection Points - CSES
using namespace std;

#define ll long long
#define sz(x) (x).size()
#define all(x) (x).begin(), (x).end()
const int MAXN = 1e6;

// kactl
struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
};

int main(){
    int n; cin>>n;

    // Eventos:
    // 1 -> começo de um segmento horizontal
    // 2 -> segmento vertical
    // 3 -> fim de um segmento horizontal
    vector <array<int, 4>> v;
    for(int i =0; i<n; i++){
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        
        if(x1 == x2){ //reta vertical
            v.push_back({x1, 2, y1, y2});
        } else{
            v.push_back({x1, 1, y1, 1});
            v.push_back({x2, 3, y1, 1});
        }
    }
    sort(all(v));

    FT bit = FT(MAXN*2+2);
    ll resp = 0;

    for(auto [x, t, y1, y2] : v){
        //Normalizar os intervalo para ser apenas positivo
        y1 += MAXN;
        y2 += MAXN;
        if(t==1){
            bit.update(y1, 1);
        } else if(t==2){ //pega a quantidade de horizontais ativos no intervalo
            resp += bit.query(y2+1) - bit.query(y1); 
        } else{
            bit.update(y1, -1);
        }
    }

    cout<<resp<<"\n";
}