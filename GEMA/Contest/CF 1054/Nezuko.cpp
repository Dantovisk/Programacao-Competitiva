#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        ll h, n; cin>>h>>n;

        ll l = 0, r = 1e9+3, mid;

        while(l < r){
            // bool da = true;
            mid = (l+r)/ 2;

            ll sobrou = mid;
            ll ht = h;

            if (mid >= n){
                ht += mid-(n-1);
                sobrou = n-1;
            }

            ll mod = n%(sobrou+1);
            ll div = n/(sobrou+1);
            
            ll t1 = div;
            ll t2 = div+1;

            ll custo = (((t1+1LL)*t1)/2LL * (sobrou+1LL-mod));
            custo += (((t2+1LL)*t2)/2LL)*mod;

            ht += sobrou;
            if(custo < ht) {
                r = mid;
            }else{
                l = mid+1;
            }
        }

        cout<<l+n<<"\n";

    }



    return 0;
}