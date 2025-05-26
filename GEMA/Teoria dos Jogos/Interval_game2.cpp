#include <bits/stdc++.h> //Atcoder
#define ll long long

using namespace std;

vector<pair<int,int>> v;

map <pair<int, int>, int> nims;


int nimbers(int l, int r){
    if(l >= r) return 0;
    if(nims.find({l, r}) != nims.end()) return nims[{l,r}];
    
    set<int> states;
    for(auto x: v){
        auto [i,j] = x;
        if(i >= l && j<=r){
            states.insert(nimbers(l, i)^nimbers(j, r));
        }
    }

    int grundy = 0;
    while(states.find(grundy)!= states.end()) grundy++;
    nims[{l,r}] = grundy;

    //out<<l<<" "<<r<<" = "<<grundy<<"\n";

    return grundy;
}



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;

    while(t--){
        int n; cin>>n;
        v.clear();

        for(int i =0; i<n; i++){
            int a, b;
            cin>>a>>b;

            v.push_back({a, b});
        }

        if(nimbers(1, 100)) cout<<"Alice\n";
        else cout<<"Bob\n";
        nims.clear();
    }
    



    return 0;
}