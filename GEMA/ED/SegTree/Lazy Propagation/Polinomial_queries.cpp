#include <bits/stdc++.h>
#define MAXN 200010
#define ll long long

using namespace std;

//eh uma segtree de soma
ll tree[MAXN*4];
int v[MAXN];
ll lazy[MAXN*4];
ll passo[MAXN * 4];

void build(int no, int l, int r){
    if(l==r){
        tree[no] = v[l];
        return;
    }

    int mid = (l+r)/2;

    build(2*no, l, mid);
    build(2*no + 1, mid+1, r);

    tree[no] = tree[no*2] + tree[2*no + 1];
}

void unlazy(int no, int l, int r){
    //o no pai usara a soma da pa para obter seu valor
    if(lazy[no]==0) return;

    tree[no] += (((2LL*lazy[no] + passo[no]*(r-l)) * (1LL + r- l ))/2LL);

    if(l!=r){
        int mid = (l+r)/2;
        lazy[no*2] += lazy[no];
        lazy[no*2 + 1] += lazy[no] + (ll)(mid-l + 1)*passo[no];
        
        passo[no*2] += passo[no];
        passo[no*2 + 1] += passo[no];
    }

    lazy[no] = 0;
    passo[no] = 0;
}

ll query(int no, int i, int j, int l, int r){
    unlazy(no, i, j);

    if(i>r || j<l) return 0;
    if (i >= l && j <= r) return tree[no];

    int mid = (i+j)/2;
    return query(no*2, i, mid, l, r) + query(2*no+1, mid+1, j, l, r);
}

void update(int no, int i, int j, int l, int r){
    unlazy(no, i, j);
    if(i>r || j<l) return;

    if(i>= l && j<=r){
        lazy[no] += (i-l)+1;
        passo[no] ++;
        unlazy(no, i, j);
        return;
    }

    int mid = (i+j)/2;

    update(no*2, i, mid, l, r);
    update(2*no + 1, mid+1, j, l, r);

    tree[no] = tree[no*2] + tree[no*2+1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        cin>>v[i];
    }

    build(1, 1, n);

    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;

        if(a==1){
            update(1, 1, n, b, c);
        }else if(a==2){
            cout<< query(1, 1, n, b, c)<<"\n";
        }
    }

}