#include <bits/stdc++.h>
#define MAXN 100010
//#define int long long int

using namespace std;

//armazena os valores de 1 e 0
int v[MAXN];

//ocorrencia de zeros
int tree[4*MAXN];

void build(int no, int l, int r){
    if(l==r){
        tree[no] = v[l];
        return;
    }

    int mid = (l+r)/2;

    build(2*no, l, mid);
    build(2*no+1, mid+1, r);
    tree[no] = tree[2*no] + tree[2*no +1];
}

void update(int no, int l, int r, int id){
    if(l>id || r<id) return;
    if(l==r){
        tree[no] = !(tree[no]);
        return;
    }

    int mid = (l+r)/2;

    update(2*no, l, mid, id);
    update(2*no+1, mid+1, r, id);

    tree[no] = tree[no*2] + tree[2*no+1];
}

void query(int no, int l, int r, int saldo){
    if(l==r) {
        cout<<l-1<<"\n";
        return;
    }

    int mid = (l+r)/2;

    if(saldo >= tree[no*2]) query(2*no + 1, mid+1, r, saldo - tree[no*2]);
    else query(2*no, l, mid, saldo);
}

int main(){
    int n, m;
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        cin>>v[i];
    }

    build(1, 1, n);


    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        if(a==1){
            update(1, 1, n, b+1);
        }
        else if(a==2){
            query(1, 1, n, b);
        }
        
        
    }


    return 0;
}