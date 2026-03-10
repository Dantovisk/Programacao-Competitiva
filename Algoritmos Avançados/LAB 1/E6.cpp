#include <bits/stdc++.h>
using namespace std;

void solve(){
    int k; int n;
    cin>>n>>k;

    //motoboys disponiveis em cada instante
    multiset<int> aval;
    for(int i = 0; i<k; i++)
        aval.insert(0);

    vector<pair<int, int>> v;
    for(int i = 0; i<n; i++){
        int l, r;
        cin>>l>>r;

        v.push_back({r, l});
    }

    //ordena os pedidos por tempo de saída
    sort(v.begin(), v.end());
    int tempo = 0;
    int res = 0;
    for(auto [r, l] : v){
        //pega o motoboy disponível e habil para a tarefa
        //que fica disponivel mais tarde

        auto ptr = aval.upper_bound(l);
        if(ptr == aval.begin()) continue;
        ptr--;
        aval.erase(ptr);
        aval.insert(r);
        res++;
    }
    cout<<res<<"\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1; 
    cin>>t;

    for(int i =0; i<t; i++){
        solve();
    }
}