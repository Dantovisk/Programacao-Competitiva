//Exercicio que utiliza conceitos de DAG
#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

int n, m;
vector <int> adj [MAXN], adjT [MAXN];
int vis[MAXN];

stack <int> st;
vector <int> compVert[MAXN];
int component [MAXN];
vector <int> compAdj[MAXN];
int compIndex = 0;

void dfs1(int u){
    vis[u] = 1;

    for(int x : adj[u]){
        if(!vis[x]) dfs1(x);
    }
    st.push(u);
}

void dfs2(int u){
    vis[u] = 1;
    component[u] = compIndex;
    compVert[compIndex].push_back(u);

    for(int x: adjT[u]){
        if(!vis[x]) dfs2(x);
    }
}

void kosaraju(){
    for(int i=1; i<=n; i++){
        if(!vis[i]) dfs1(i);
    }

    memset(vis, 0, sizeof(vis));

    while(!st.empty()){
        if(!vis[st.top()]){
            dfs2(st.top());
            compIndex++;
        }
        st.pop();
    }

    for(int i=1; i<=n; i++){
        for(int x: adj[i]){
            if(component[i] != component[x]){
                compAdj[component[i]].push_back(component[x]);
            }
        }
    }
}

int main(){
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adjT[b].push_back(a);
    }

    kosaraju();

    if(compIndex == 1) cout<< "YES\n";
    else{
        cout<<"NO\n";
   
        if(!compAdj[0].empty()){
            cout<<compVert[compAdj[0].front()].front()<<" "<<compVert[0].front();
        }
        else
        {
            cout<<compVert[0].front()<<" "<< compVert[1].front();
        }
                
    }

    return 0;
}
