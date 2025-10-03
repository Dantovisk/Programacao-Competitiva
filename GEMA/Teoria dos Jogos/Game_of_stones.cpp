#include <bits/stdc++.h> //Codeforces
#define ll long long

using namespace std;

vector<int> v;

map <pair<int, ll>, int> nims;

// a é o restante de pedras na pilha
int nimbers(int a, ll mask){
    if(nims.find({a, mask}) != nims.end()){
        return nims[{a, mask}];
    }

    set<int> states;

    for(int i = a; i>0; i--){
        if((1LL<<(i-1))& mask) continue;
        states.insert(nimbers(a-i, (1LL<<(i-1)) | mask));
    }

    int grundy = 0;
    while(states.find(grundy) != states.end()) grundy++;

    nims[{a, mask}] = grundy;
    return grundy;
}



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    
    int sum = 0;
    for(int i =0; i<n; i++){
        int a; cin>>a;
        sum ^= nimbers(a, 0LL);
    }

    if(sum) cout<<"NO\n";
    else cout<<"YES\n";


    return 0;
}