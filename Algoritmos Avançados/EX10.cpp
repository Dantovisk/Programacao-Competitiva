#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

// Multiplicação modular
//Como n <= 10^12  precisamos de int128
ll modmul(ll a, ll b, ll mod){
    return ((__int128_t)a * b)%((__int128_t)mod);
}

//Função de exponenciação modular
ll modexp(ll base, ll exp, ll mod){
    if(exp == 0) return 1;
    if(exp == 1) return (base % mod);

    ll k = modexp(base, exp/2LL, mod);
    k = modmul(k, k, mod);

    if(exp%2) return modmul(k, base, mod);
    return k;
}

//Inverso modular pelo teorema de fermat
ll invmod(ll a, ll mod){
    return modexp(a, mod-2, mod);
}

// Implementação de miller rabin
// Adaptada da implementação do kactl
// OVERKILL DEMAISSSS :O

// bool isPrime(ll n) {
// 	if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
// 	ll A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
// 	    s = __builtin_ctzll(n-1), d = n >> s;
// 	for (ll a : A) {   
// 		ll p = modexp(a%n, d, n), i = s;
// 		while (p != 1 && p != n - 1 && a % n && i--)
// 			p = modmul(p, p, n);
// 		if (p != n-1 && i != s) return 0;
// 	}
// 	return 1;
// }

// O(sqrt(N)) passa de boa
bool isPrime(ll n){
    for(ll i = 2; i*i<= n; i++){
        if(n%i == 0) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, t; cin>>n>>t;

    // Sabemos que tem primo pra caramba
    // Só ir testando os numeros ímpares após n que acha rapidinho
    for(ll cand = n + 1LL + (n%2LL); cand < n + 10000LL; cand += 2){
        // Achou o próximo primo, só testar
        if(isPrime(cand)){
            cout<<invmod(t, cand)<<"\n";
            break;
        }
    }

    return 0;
}