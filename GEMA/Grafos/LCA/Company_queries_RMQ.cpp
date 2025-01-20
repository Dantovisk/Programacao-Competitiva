#include <bits/stdc++.h> // resolveremos com euler tour e sparse table
#define MAXN 200010

using namespace std;

vector <int> adj[MAXN];
int level[MAXN];
int tin[MAXN];

int vec[2*MAXN];
int table [2*MAXN][20];   // o elemento que possui menor nivel
int temp = 0;

//o problema se resumirá a RMQ no array
//Poderíamos resolver com segtree, mas sparse table
//É mais eficiente e simples nesse caso (não há alterações)

void dfs(int u, int p){
    vec[temp] = u;
    tin[u] = temp;
    temp++;

    for(auto v: adj[u]){
        if(v != p){
            level[v] = level[u] + 1;
            dfs(v, u);

            vec[temp] = u;
            temp++;
        }
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; 
    cin>>n>>q;

    for(int i=2; i<=n; i++){
        int a;
        cin>>a;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }

    memset(tin, -1, sizeof(tin));

    level[1] = 0;
    dfs(1, -1);

    for(int i=0; i<temp; i++){
        table[i][0] = vec[i];
    }

    for(int k=1; k<20; k++){
        for(int i=0; i + (1<<k) <= temp; i++){
            int l = table[i][k-1];
            int r = table[i + (1<<(k-1))][k-1];
            table[i][k] = (level[l]<level[r] ? l : r);
        }
    }

    for(int i=0; i<q; i++){
        int a, b;
        cin>>a>>b;

        a=tin[a];
        b=tin[b];

        if(a>b) swap(a,b);

        int k = log2(b-a+1);

        int l = table[a][k];
        int r = table[(b-(1<<k))+1][k];

        cout<<(level[l] < level [r]? l : r)<<"\n";
    }

    return 0;
}