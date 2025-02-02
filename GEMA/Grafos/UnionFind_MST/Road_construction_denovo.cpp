#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;

int parent[MAXN], grSize[MAXN];
int maxSize = 1, cont;

int find(int a){
    if(parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);

    if(grSize[a] < grSize[b]) swap(a,b);

    grSize[a] += grSize[b];
    parent[b] = a;

    maxSize = max(maxSize, grSize[a]);
}

int main(){
    int n, m;
    cin>>n>>m;

    cont = n;

    for(int i=0; i<=n; i++){
        parent[i] = i;
        grSize[i] = 1;
    }

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        if(find(a) != find(b)){
            merge(a, b);
            cont--;
        }
        cout<<cont<<" "<<maxSize<<"\n";
    }

}