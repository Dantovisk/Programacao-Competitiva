#include <bits/stdc++.h> // questãozinha mal escrita :<

using namespace std;

map<string, long long> mp;

int main(){
    int maxPig = 0;
    vector<pair<string, int>> q;


    int n; cin>>n;

    for(int i =0; i<n; i++){
        string sp; int p;
        cin>>sp>>p;
        if(sp == "pig") maxPig = max(maxPig, p);

        else q.push_back({sp, p});
    }

    for(auto[sp, p]: q){
        if(p < maxPig) mp[sp] += p;//= max(p, mp[sp]);
    }

    long long res = maxPig;
    for(auto[sp, p]: mp){
        res += p;
    }
    cout<<res<<"\n";

    return 0;
}