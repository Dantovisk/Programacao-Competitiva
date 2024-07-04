//como fala que a raridade é 2^n basta deixar os mais altos sem restricao
#include <bits/stdc++.h>
using namespace std;

bool excluido [100010];
set <int> resp;

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);

    int a, b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        adj[max(a,b)].push_back(min(a,b));
    }

    for(int i=n; i>0; i--){
        if(!excluido[i]){
            resp.insert(i);
            for(int x: adj[i]) excluido[x] = true;
        }
    }

    cout<<resp.size()<<endl;
    for(int x: resp) cout<<x<<" ";
    return 0;
}