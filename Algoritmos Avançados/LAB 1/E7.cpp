#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;

    vector<pair<int, int>> v;

    for(int i = 0; i<n; i++){
        int a, b;
        cin>>a>>b;
        v.push_back({a, b});
    }

    // A moral desse problema é só ordenar por tempo de duração
    // O tempo de inicio nao importa
    sort(v.begin(), v.end());
    long long res = 0, currTime = 0;
    for(auto [dur, prazo] : v){
        currTime += dur;
        res += prazo - currTime;
    }   
    cout<<res<<"\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t = 1; 
    // cin>>t;

    for(int i =0; i<t; i++){
        solve();
    }

}