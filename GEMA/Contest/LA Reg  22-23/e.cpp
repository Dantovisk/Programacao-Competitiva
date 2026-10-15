#include<bits/stdc++.h>
using namespace std ; 
#define ll long long
#define rep(i, a, b) for(int i = a; i<(b); ++i)
#define pb push_back
#define meio ((i+j)>>1)
#define pii pair<int,int> 
#define ff first 
#define ss second 
 
const int maxn = 2e5 + 5 ; 
const int maxl = 22 ; 
 
/*
1 x N 
tiles 1x1, 1x2, ... 1xn
n de cada 

guarda qt a esq e qt a dir tenho livre 
faz subtraindo ignorando o já usado 
começa usando o maior tile possivel pro menor 
usa sempre no lado com menor tamanho livre (?)

*/

int used[maxn] ; 

void solve(){

	int n, k, e ; cin >> n >> k >> e ; 

	int esq = e, dir = n - (e + k) ;

	int resp = esq + dir ; 

    set<int> s;
	for(int i = 0 ; i <= min(esq, 20) ; i++){
		for(int j = 0 ; j <= min(dir, 20) ; j++){
            int x = esq - i, y = dir - j;
            s.clear();
            int r = esq + dir;

            s.insert(k);
            if(i) {
                if(!s.count(i)) {
                    s.insert(i);
                    r -=i;
                }
            }
            if(j){
                if(!s.count(j)) {
                    s.insert(j);
                    r -=j;
                }
            }
            if(x){
                for(int aux = x; aux > 0; aux--){
                    if(!s.count(aux)) {
                        s.insert(aux);
                        r -=aux;
                        break;
                    }
                }
            }
            if(y){
                for(int aux = y; aux > 0; aux--){
                    if(!s.count(aux)) {
                        s.insert(aux);
                        r -=aux;
                        break;
                    }
                }
            }
            resp = min(resp, r);
		}
	}

	cout << resp << "\n" ; 

}

int32_t main(){
    
	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	int t ; t = 1 ; // cin >> t ; 

	while(t--) solve() ; 

}