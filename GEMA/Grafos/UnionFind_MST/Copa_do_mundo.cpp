#include <bits/stdc++.h>    //Copa  do Mundo - OBI 2014
#define MAXN 100010
#define tiii tuple <int, int, int>
using namespace std;

int setSize[MAXN];
int parent[MAXN];

priority_queue <tiii, vector<tiii>, greater<tiii>> rodo;
priority_queue <tiii, vector<tiii>, greater<tiii>> ferro;

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


int main(){ //codigo feio mas a velocidade é a prioridade
    int n, f, r; 
    cin>>n>>f>>r;

    init(n);

    for(int i=0; i<f; i++){
        int a, b, c;
        cin>>a>>b>>c;
        ferro.push({c,a,b});
    }

    for(int i=0; i<r; i++){
        int a, b, c;
        cin>>a>>b>>c;
        rodo.push({c,a,b});
    }

    int resp = 0;
    for(int i=0; i<f; i++){
        int a, b, c;
        auto x = ferro.top();
        ferro.pop();

        c =get<0>(x);
        a =get<1>(x);
        b =get<2>(x);

        if(find(a) != find(b)){
            merge(a, b);
            resp +=c;
        }
    }

    for(int i=0; i<r; i++){
        int a, b, c;
        auto x = rodo.top();
        rodo.pop();

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