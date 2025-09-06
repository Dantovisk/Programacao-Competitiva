#include <bits/stdc++.h> // Inversion Probability - CSES
#define ll long long     // A saída desse problema é inexplicável 
#define dd double        // WA só de apresentação, mas não me importo em arrumar
using namespace std;

int v[110];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;

    for(int i =1; i<=n; i++) cin>>v[i];

    // garante que vamos usar "round half to even"
    fesetround(FE_TONEAREST);

    double res = 0;
    for(int i =n-1; i>0; i--){
        double base = 1.0/(dd)v[i];

        for(int j = i+1; j<=n; j++){
            double at = 0;
            for(int k =1 ; k< v[i]; k++){
                at += min(k, v[j]);
            }
            res += base * (at/((dd)v[j]));
        }
    }
    cout<<fixed<<setprecision(12);
    cout<<res<<"\n";

    double alfa = round(res*1e6);
    double rounded = nearbyint(alfa); // half-to-even
    res = rounded / 1e6;

    cout<<fixed<<setprecision(6);
    cout<<res<<"\n";

    return 0;
}