#include <bits/stdc++.h> //CSES
#define MAXN 100010
using namespace std;

vector<int> adj[MAXN];
int k[MAXN]; //grau de entrada do vertice
queue <int> q;
vector<int> resp;

int main(){
    int n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        k[b]++;
    }

    for(int i=1; i<=n; i++){
        if(k[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int v = q.front();
        resp.push_back(v);
        q.pop();
        for(int x: adj[v]){
            k[x]--;
            if(k[x] == 0) q.push(x);
        }
    }

    if((int)resp.size() != n) cout<<"IMPOSSIBLE\n";
    else{
        for(auto x: resp) cout<<x<<" ";
    }

    return 0;
}