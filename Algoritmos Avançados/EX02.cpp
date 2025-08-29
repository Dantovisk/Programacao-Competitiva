#include <bits/stdc++.h>

using namespace std;



void solve(){
    int n; cin>>n;
    vector<pair<double, int>> v;
    vector<string> dias(n); // Retorna o dia pelo id

    double total = 0.0;

    for(int i =0; i<n; i++){
        string dia;
        double val;
        cin>>dia>>val;
        dias[i] = dia;
        v.emplace_back(val, i);
        total +=  val;
    }

    sort(v.rbegin(), v.rend());

    vector <int> ids;
    int cont = 0;
    double acum = 0;
    for(int i =0; i<n && acum <= total; i++){
        acum +=  v[i].first;
        cont++;
        total -= v[i].first;
        ids.push_back(v[i].second);
    }
    sort(ids.begin(), ids.end());

    cout<<fixed<<setprecision(2);
    cout<<cont<<" "<<(cont > 1? "dias " : "dia ")<<"(";
    for(int i = 0; i< ids.size(); i++){
        cout<<dias[ids[i]];
        if(i < ids.size() - 1) cout<<", ";
    }
    double percent = 100.0*((double)cont / double(n));
    cout<<") | soma="<<acum<<" | "<<percent<<"% dos dias totais\n";
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