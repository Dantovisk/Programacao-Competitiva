#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// Encontra x e y, tal que xa + yb = gcd(a, b)
// Veja que se 'a' e 'b' são coprimos, x retorna o
// Inverso modular de a mod b

// Retorna gcd(a, b)
ll euclides(ll a, ll b, ll &x, ll &y){
    if(!b){ // Chegou no caso base
        x = 1;
        y = 0;
        return a;
    }
    //encontra a resposta para o resto da divisão de a/b
    ll d = euclides(b, a%b, y, x);
    y -= (a/b) * x;
    
    return d;
}

void solve(){
    ll a, mod;
    cin>>a>>mod;

    ll x, y;

    // Inverso modular só existe se os números são coprimos
    ll mmc = euclides(a, mod, x, y);
    if(mmc != 1){
        cout<<"-1\n";
        return;
    }

    // soma mod caso o número venha negativo
    cout<<(x+mod)%mod<<"\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0); // para facilitar a visualização

    int t;
    cin>>t;

    while(t--) solve();
}