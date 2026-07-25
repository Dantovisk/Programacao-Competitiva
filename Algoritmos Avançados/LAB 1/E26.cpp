#include <bits/stdc++.h>
using namespace std;

// Calcula o MMC usando restos de divisão sucessivamente
long long calcMMC(long long a, long long b){
    while(b != 0){
        long long aux = b;
        b = a%b;
        a = aux;
    }
    return a;
}

void solve(){
    long long a, b;
    cin>>a>>b;

    long long mdc = gcd(a, b);
    long long mmc = (a*b)/mdc;
    
    cout<<mdc<<" "<<mmc<<"\n";
}

int main() {
    int t;
    cin>>t;

    while(t--) solve();
}