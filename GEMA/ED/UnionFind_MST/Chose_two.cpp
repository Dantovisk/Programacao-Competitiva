#include <bits/stdc++.h>    //Chose two and eat one
#define tiii tuple<int,int,int>
#define MAXN 510
using namespace std;

int v[510];

int setSize[MAXN];
int parent[MAXN];

priority_queue <tiii, vector<tiii>> pq;

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

//exponenciacao modular
int modpow(int x, int n, int m) {
    if (n == 0) return 1%m;
    long long u = modpow(x,n/2,m);
    u = (u*u)%m;
    if (n%2 == 1) u = (u*x)%m;
    return u;
}

int main(){
    int n, m;
    cin>>n >> m;

    for(int i=1; i<=n; i++){
        cin>>v[i];
    }

    init(n);
    long long resp = 0;

    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            int val = (modpow(v[i],v[j],m) + modpow(v[j],v[i],m))%m;
            pq.push({val, i, j});

        }
    }

    while(!pq.empty()){
        int a, b, c;
        auto x = pq.top();
        pq.pop();

        c =get<0>(x);
        a =get<1>(x);
        b =get<2>(x);

        if(find(a) != find(b)){
            merge(a, b);
            resp += c;
        }
    }

    cout<<resp;
}