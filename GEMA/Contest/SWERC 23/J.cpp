#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5+3;

vector<int> adj[MAX];


int cont = 0;


void dfs(int u=0, int p=-1){
    stack<pair<int, int>> q;
    q.push({0, -1});

    while(!q.empty()){
        auto [u, p] = q.top();
        q.pop();

        int k = 0;
        for(auto v: adj[u]){
            if(v == p) continue;
            q.push({v, u});
            k++;
        }
        
        if(k==0) cont++;
        if(u==0 && k==1) cont++;
    }   
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p;
    cin>>n>>p;

    if(n==1){
        cout<<"0\n";
    }

    for(int i =1; i<n; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();

    int mod = p%cont;

    int a = p/cont, b = p/cont;
    if(mod) {a++; mod--;}
    if(mod) {b++; mod--;}
    cout<<a+b<<"\n";  
    
}