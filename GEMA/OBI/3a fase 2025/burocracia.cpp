#include <bits/stdc++.h> // Não funciona por algum motivo essa desgraça
#define MAXN 100010

using namespace std;
int par[MAXN][20];
vector<int> adj[MAXN];
int v[2*MAXN], lazy[8*MAXN];
int tin[MAXN], tout[MAXN];

int temp = 1;

void unlazy(int no, int l, int r){
    if(lazy[no] == 0) return;
    if(l == r) {
        v[l] = lazy[no];
        lazy[no] = 0;
        return;
    }

    lazy[2*no] = lazy[no];
    lazy[2*no+1] = lazy[no];
    lazy[no] = 0;
}

void update(int no, int i, int j, int l, int r, int val){
    if(j < l || i > r) return;
    unlazy(no, i, j);

    if(j <= r && i >= l){
        lazy[no] = val;
        unlazy(no, i, j);
        return;
    }  
    int mid = (i+j)/2;
    update(no*2, i, mid, l, r, val);
    update(no*2+1, mid+1, j, l, r, val);
}

int query(int no, int i, int j, int id){
    unlazy(no, i, j);
    if(i > id || j < id) return -1;
    if(i==j) return v[i];
    int mid = (i+j)/2;

    return max(query(2*no, i, mid, id), query(2*no+1, mid+1, j, id));
}

void dfs(int u){
    v[temp] = par[u][0]; 
    tin[u] = temp++;
    for(auto v: adj[u]){
        dfs(v);
    }
    v[temp] = par[u][0]; 
    tout[u] = temp++;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //memset(par, -1, sizeof(par));
    int n; cin>>n;

    for(int i =2; i<=n; i++){
        cin>>par[i][0];
        adj[par[i][0]].push_back(i);
    }

    for(int i=1; i<19; i++){
        for(int j=1; j<=n; j++){
            par[j][i] = par[par[j][i-1]][i-1];
        }
    }
    dfs(1);
    // for(int i = 2; i<=n; i++){
    //     cout<<"Pai["<<i<<"] = "<<par[i][0]<<" =? "<<query(1, 1, 2*n, tin[i])<<"\n";
    // }

    int q; cin>>q;

    while(q--){
        int a, b, c;
        cin>>a>>b;

        if(a==1){
            cin>>c;
            int p = query(1, 1, 2*n, tin[b]);
            //cout<<"o pai de "<<b<<" é "<<p<<"\n";
            c--;
            if(c==0) {
                cout<<p<<"\n";
                continue;
            }
            for(int i = 18; i >=0; i--){
                if(c >= (1<<i)){
                    c-= (1<<i);
                    p = par[p][i];
                }
            }
            cout<<p<<"\n";

        }else{
            if(tin[b] + 1 == tout[b]) continue;
            update(1, 1, 2*n, tin[b]+1, tout[b]-1, b);
        }
    }
    return 0;
}