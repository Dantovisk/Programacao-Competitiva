#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;

        vector<int> v;
        for(int i =0; i<n; i++){
            int a; cin>>a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        int res = 0;
        for(int i =0; i<n; i+= 2){
            res = max(res,v[i+1] - v[i]);
        }
        cout<<res<<"\n";
    }



    return 0;
}