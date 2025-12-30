#include <bits/stdc++.h>
using namespace std;

//não gostei desse problema;
//talvez eu tente resolver depois

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define ff first
#define ss second
#define pb push_back

void solve(){
    int n, q;
    cin>>n>>q;
    string a; cin>>a;

    int pre = 0, pos = 0, ambos = 0, pares = 0;
    bool safe = true, farm = false;

    int ct = 0;
    int sum = 0;

    for(int i = a.size()-1; i >= 0; i--){
        if(a[i] == '?'){
            if(!safe) pre++;
            else if(farm) {
                pares++;
                farm = false;
            }
            else farm = true;

            safe = true;
            ct++;
        } 
        else if (a[i] == 'I'){
            if(!safe) sum -= 1;
            else sum ++;

            safe = true;
            farm = false;
        }
        else{
            if(a[i] == 'V') sum += 5;
            else sum += 10;
            safe = false;
            farm = false;
        }
    }

    cout<<sum<<" "<<pre<<" "<<pares<<"\n";


    rep(i, 0, q){
        int X, V, I;
        cin>>X>>V>>I;

        int efetiv = max(min({pares, ct-I, X+V, I}), 0);

        int curr = sum;
        int falta = ct;

        // ja tira os pre
        int gasto = min({falta, pre, I}); 
        falta -= gasto;
        I -= gasto;
        curr -= gasto;

        

        //pares
        gasto = min({efetiv, V, I}); 
        falta -= 2*gasto;
        I -= gasto;
        V-= gasto;
        curr += gasto*4;

        

        gasto = min({efetiv, X, I}); 
        falta -= 2*gasto;
        I -= gasto;
        X -= gasto;
        curr += gasto*9;

        


        //tira os q sobraro
        gasto = min({falta, I}); 
        falta -= gasto;
        I -= gasto;
        curr += gasto;

        

        gasto = min({falta, V}); 
        falta -= gasto;
        curr += gasto*5;

        

        gasto = min({falta, X}); 
        falta -= gasto;
        curr += gasto*10;

        

        cout<<curr<<"\n";
    }

}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}