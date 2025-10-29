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

// SegTree
//
// Recursiva com Lazy Propagation
// Query: soma do range [a, b]
// Update: soma x em cada elemento do range [a, b]
// Pode usar a seguinte funcao para indexar os nohs:
// f(l, r) = (l+r)|(l!=r), usando 2N de memoria
//
// Complexidades:
// build - O(n)
// query - O(log(n))
// update - O(log(n))

const int MAX = 2e5+3;
const int inf = 1e9+7;

int ve[MAX];

namespace seg {
	int uns[4*MAX]; //quantos reatores já foram pra 1
    ll explo[4*MAX]; //quantas explosoes já tiveram 
    int rest[4*MAX]; //qual é o minimo restante pra explodir

    ll lazyexp[4*MAX]; // aumenta o numero de explosoes nos reatores 1
    int lazyrest[4*MAX]; // diminui o valor restante no intervalo
	int n, *v; //v é o max do reator

	int build(int p=1, int l=0, int r=n-1) {
		lazyexp[p] = 0;
        lazyrest[p] = 0;
        explo[p] = 0;
		if (l == r) {
            if(v[l] == 1){
                uns[p] = 1;
                rest[p] = inf;
            }
            else{
                uns[p] = 0;
                rest[p] = v[l];
            }
            return rest[p];
        }
		int m = (l+r)/2;
		rest[p] = min(build(2*p, l, m), build(2*p+1, m+1, r));
        uns[p] = uns[2*p+1]+uns[2*p];
        return rest[p];
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
        if(lazyexp[p] > 0){
            explo[p] += lazyexp[p] * uns[p];
            if (l != r) {   // CONSIDERAR AQUI
                if (uns[2*p] > 0) lazyexp[2*p] += lazyexp[p];
                if (uns[2*p+1] > 0)lazyexp[2*p+1] += lazyexp[p];
            }
            lazyexp[p] = 0;
        }
        if(lazyrest[p] > 0){
            if(uns[p] < (r-l+1)) rest[p] -= lazyrest[p];
            if (l != r) {
                int m = (l+r)/2;
                // Só propaga 'rest' para filhos que têm reatores ativos
                if (uns[2*p] < (m-l+1)) lazyrest[2*p] += lazyrest[p];
                if (uns[2*p+1] < (r-m)) lazyrest[2*p+1] += lazyrest[p];
            }
            lazyrest[p] = 0;
        }
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return explo[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	void update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
        prop(p, l, r);

        if (b < l or r < a) return;
		if (a <= l and r <= b) {
            //tudo 1 -> aplica lazy apenas
            if(uns[p] == (r-l+1)){
                lazyexp[p]++;
                prop(p, l, r);
                return;
            }
        
            // ninguém com rest > 1 vai ventar
            if(x < rest[p]){
                if(uns[p] < (r-l+1)) lazyrest[p] += x;

                //aplica lazyexp nos reatores iguais a 1
                if(uns[p] > 0) lazyexp[p] += 1;

                prop(p, l, r);
                return;
            }

		}

        if(l==r){
            rest[p] -= x;

            if(rest[p] <= 0){
                explo[p]++;
                rest[p] = max(1, (v[l] >> min(explo[p], 30LL)));

                if(rest[p] == 1) {
                    uns[p] = 1;
                    rest[p] = inf;
                }
            }
            
            return;
        }
        
		int m = (l+r)/2;
		update(a, b, x, 2*p, l, m);
		update(a, b, x, 2*p+1, m+1, r);
        uns[p] = uns[2*p] + uns[2*p + 1];
        explo[p] = explo[2*p] + explo[2*p + 1];
        rest[p] = min(rest[2*p], rest[2*p + 1]);
	}
};

int main() {
	// cin.tie(0)->sync_with_stdio(0);
	// cin.exceptions(cin.failbit);

    int n, q;
    cin>>n>>q;

    rep(i, 0, n){
        cin>>ve[i];
    }

    seg::build(n, ve);

    rep(i, 0, q){
        int t, l, r, x;

        cin>>t>>l>>r;

        if(t == 1){
            cin>>x;
            seg::update(l-1, r-1, x);
        }else{
            cout<<seg::query(l-1, r-1)<<"\n";
        }
    }

}