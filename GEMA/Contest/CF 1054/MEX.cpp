#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int n, k; cin>>n>>k;

        map<int, int> v;
        for(int i =0; i<n; i++){
            int a; cin>>a;
            v[a]++;
        }
        int res = 0;
        int cont = k;
        for(auto [x, qt]: v){
            if(x < k) cont--;
            if(x == k) res+= qt;
        }
        cout<<max(res, cont)<<"\n";
    }



    return 0;
}