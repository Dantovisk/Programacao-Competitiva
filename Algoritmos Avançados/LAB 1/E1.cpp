#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(){
    int n; cin>>n;

    map<string, int> mp; // Armazena disciplinas e seus respectivos prazos

    int sum = 0;
    rep(i, 0, n){
        string a; int b;
        cin>>a>>b;

        mp[a] = b;
    }

    int d; cin>>d;
    string task;
    cin>>task;

    // Busca o prazo da tarefa; se não existir, define valor alto (impossível)
    sum = (mp.find(task) != mp.end() ? mp[task]: 1e9+7);

    // Compara o prazo com a data de entrega (d) e a tolerância de 5 dias
    if(sum <= d){
        cout<<"Yessss\n";
    } else if(sum <= d+5){
        cout<<"Late\n";
    }else{
        cout<<"Do your own homework!\n";
    }

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin>>t;

    rep(i, 0, t){
        cout<<"Case "<<i+1<<": ";
        solve();
    }

}