#include <bits/stdc++.h>
#define ll long long

using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin>>q; 


    while(q--){
        int n; cin>>n;

        int cont = 0;
        bool foi = true;
        int mx = 1;
        int u = 0;
        while(mx < n) {
            mx <<=1;
            u++;
        }
        for(int i = u; i> 0; i--){
            int k = (1<<i) - 1;

            while(n >= k){
                // cout <<n<<" - "<<k<<" = ";
                n-= k;
                // cout<<n<<"\n";
                cont += (1<<(i-1));

                // cout<<"cont: "<<cont<<"\n";

                foi = true;
            }
            if(foi) {n--;}

        }
        cout<<cont<<"\n";

    }
    
}