#include <bits/stdc++.h>    //reduzindo detalhes de um mapa - OBI 2011
#define MAXN 100010
#define tiii tuple <int, int, int>
using namespace std;

int setSize[MAXN];
int parent[MAXN];

priority_queue <tiii, vector<tiii>, greater<tiii>> pq;

void init(int n){
    for(int i=1; i<=n; i++){
        setSize[i] = 1;
        parent[i] = i;
    }
}

int find(int a){
    if(parent[a] == a) return a;
    return parent[a] = find(parent[a]); //otimizaçao para todos os no caminho do find itens apontarem para o representante
}

void merge(int a, int b){
    a = find(a);
    b = find(b);

    if(setSize[a] < setSize[b]) swap(a,b);

    setSize[a] += setSize[b];
    parent[b] = a;
}

int main(){
    int n, m; 
    cin>>n>>m;
    init(n);

    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        pq.push({c,a,b});
    }

    int resp = 0;
    for(int i=0; i<m; i++){
        int a, b, c;
        auto x = pq.top();
        pq.pop();

        c =get<0>(x);
        a =get<1>(x);
        b =get<2>(x);

        if(find(a) != find(b)){
            merge(a, b);
            resp +=c;
        }
    }
    cout<<resp;

    return 0;
}