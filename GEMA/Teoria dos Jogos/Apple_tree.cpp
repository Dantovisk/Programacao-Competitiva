#include <bits/stdc++.h>
#define MAXN 100010
#define NCOR 20000010
#define ll long long
using namespace std;

int par[MAXN], apple[MAXN];
int n;
vector<int> adj[MAXN];
bool azul[MAXN]; 
int xorv = 0;
int ctazul[NCOR], ctverm[NCOR];
ll quantazuis = 0;

void dfs(int u){

    for(auto v: adj[u]){
        dfs(v);
    }

    if(adj[u].size() == 0 || (adj[u].size() > 0 && !azul[adj[u][0]])){
        azul[u] = true;
        ctazul[apple[u]] ++;
        xorv ^= apple[u];
        quantazuis ++;
    } else{
        ctverm[apple[u]] ++;
    }
}

int main(){
    cin>>n;
    for(int i =1; i<=n; i++) cin>>apple[i];
    for(int i =2; i<=n; i++) {
        cin>>par[i];
        adj[par[i]].push_back(i);
    }

    dfs(1);
    int maxv = *max_element(apple+1, apple+n+1);

    ll resp = 0;
    if(xorv == 0){ //o segundo mano ja ta ganhando, nao muda a xor
        //trocando azuis entre si
        resp += (quantazuis*(quantazuis-1))/2;

        //trocando vermelhos entre si
        ll ver = n-quantazuis;
        resp += ver*(ver-1)/2;

        //trocando azuis e vermelhos enguais
        for(int i =1; i<= maxv; i++){
            resp+= 1LL * ctazul[i] * ctverm[i];
        }
    }
    else{ //o segundo mano ta perdendo :(, tenta mudar xor pra 0
        //trocando azuis e vermelhos pra dar 0;
        for(int i =1; i<= maxv; i++){
            int a = xorv ^ i;
            resp+= 1LL * ctazul[i] * ctverm[a];
        }
        
    }

    cout<<resp<<"\n";

    return 0;
}