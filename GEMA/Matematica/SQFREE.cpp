#include <bits/stdc++.h> // Spoj - Square-free integers
#define ll long long      
#define dd double        
using namespace std;

const int MAX = 1e7+1;

int mobius[MAX+7];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    mobius[1] = -1;
    for(int i =1; i<MAX; i++){
        if(mobius[i]){
            mobius[i] = -mobius[i];
            for(int j = 2*i; j < MAX; j+=i) mobius[j] += mobius[i];
        }
    }

    int t; cin>>t;

    while(t--){
        ll n; cin>>n;

        ll resp = 0;
        for(ll i = 1; i*i <=n; i++){
            // cout<<n<<" / "<<mobius[i]<<" -> ";
            if(mobius[i])
                resp += ((ll)mobius[i] * n )/(i * i);
        }
        cout<<resp<<"\n";
    }

}