#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX 100010

vector <int>adj[MAX];
int grau[MAX];

int main(){
    int n, m;
    cin>>n>>m;

    for(int i =0; i<m; i++){
        int a, b;
        cin>>a>>b;

        adj[a].push_back(b);
        grau[b] ++;
    }

    priority_queue <int, vector<int>, greater <int>> q;
    vector<int> r;
    for(int i =1; i<=n; i++){
        if(grau[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int u = q.top(); q.pop();
        r.push_back(u);
        for(auto v: adj[u]){
            grau[v]--;
            if(grau[v] == 0) q.push(v);
        }
    }

    if(r.size() == n)for(auto x: r) cout<<x<<" ";
    else cout<<"IMPOSSIBLE\n";

    return 0;
}