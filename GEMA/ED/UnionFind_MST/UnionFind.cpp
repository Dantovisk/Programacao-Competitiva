#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int setSize[MAXN];
int parent[MAXN];

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
    int n; cin>>n;
    init(n);


    return 0;
}