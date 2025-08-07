#include <bits/stdc++.h> // TLE
#define MAXN 100010      
#define pii pair<int,int>
using namespace std;

int v[MAXN], cont[MAXN], prox[MAXN], last[MAXN];

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin>>n>>q;
    for(int i =0; i<n; i++){
        cin>>v[i];
    }

    int sq = 1; //tamanho do bucket
    while(sq * sq < n) sq++;

    for(int i =0; i<n; i++){
        int bucket = i/sq;
        int k = i;

        while(k < (bucket+1)*sq && k < n){
            cont[i]++;
            last[i] = k;
            k += v[k];
            prox[i] = k;
        }
    }


    for(int u =0; u<q; u++){
        int t, a, b;
        cin>>t>>a;
        a--;
        if(t == 1){
            
            int k = a;
            int r = 0, lst = a;
            while(k < n){
                lst = last[k];
                r += cont[k];
                k = prox[k];
            }
            cout<<lst+1<<" "<<r<<"\n";
        }
        else{
            cin>>b;
            v[a] = b;
            cont[a] = 0;

            int bucket = a/sq;
            int k = a;

            if(a + v[a] >= min((bucket+1)*sq, n)){
                cont[a]++;
                last[a] = k;
                k += v[k];
                prox[a] = k;
            }
            // while(k < (bucket+1)*sq){
            //     cont[a]++;
            //     last[a] = k;
            //     k += v[k];
            //     prox[a] = k;
            // }

            for(int i = a; i >= bucket * sq; i--){
                if(i + v[i] >= min((bucket+1)*sq, n) ) continue;

                cont [i] =  cont[i + v[i]] + 1;
                last[i] = last[i+ v[i]];
                prox[i] = prox[i + v[i]];
            }

        }
        // cout<<"foi "<<i<<"\n";
    }
    
    return 0;
}