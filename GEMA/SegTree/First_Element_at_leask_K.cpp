#include <bits/stdc++.h>
#define MAXN 100010
//#define int long long int

using namespace std;

//armazena os valores da arvore
int v[MAXN];

//segtree de maximo
int tree[4*MAXN];

void build(int no, int l, int r){
    if(l==r){
        tree[no] = v[l];
        return;
    }

    int mid = (l+r)/2;

    build(2*no, l, mid);
    build(2*no+1, mid+1, r);

    tree[no] = max(tree[2*no], tree[2*no +1]);
}

void update(int no, int l, int r, int id, int val){
    if(l>id || r<id) return;
    if(l==r){
        tree[no] = val;
        return;
    }

    int mid = (l+r)/2;

    update(2*no, l, mid, id, val);
    update(2*no+1, mid+1, r, id, val);

    tree[no] = max(tree[no*2], tree[2*no+1]);
}

int query(int no, int l, int r, int val){
    if(tree[no] < val) return 0; //pois vai subtrair 1
    if(l==r) {
        return l;
    }

    int mid = (l+r)/2;

    if(val <= tree[no*2]) return query(no*2, l, mid, val);

    return query(no*2 + 1, mid+1, r, val);
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
            int c; cin>>c;
            update(1, 1, n, b+1, c);
        }
        else if(a==2){
            cout<<query(1, 1, n, b)-1<<"\n";
        }
        
        
    }


    return 0;
}