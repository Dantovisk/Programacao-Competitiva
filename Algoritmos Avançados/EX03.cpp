#include <bits/stdc++.h>
#define tiii tuple<string, string,int>

using namespace std;

void solve(){
    int n, m;
    cin>>n>>m;

    vector<vector<tiii>> v(n);

    for(int i = 0; i<m; i++){
        int id, tipo;
        string ini, fim;
        cin>>id>>ini>>fim>>tipo;

        v[(--tipo)].push_back({fim, ini, id});
    }

    for(int i = 0; i<n; i++){
        sort(v[i].begin(), v[i].end());

        vector<int> resp;
        string atual =  "00:00";
        cout<<i+1<<": ";
        for(auto [fim, ini, id]: v[i]){
            if(atual <= ini){
                atual = fim;
                resp.push_back(id);
            }
        }

        cout<<resp.size()<<(resp.size() > 0 ? " = " : "");
        for(int j = 0; j< resp.size(); j++){
            cout<<resp[j];
            if(j < resp.size()-1) cout<<", ";
        }

        if(i < n-1) cout<<" | ";
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin>>q;
    while(q--){
        solve();
    }

    return 0;
}