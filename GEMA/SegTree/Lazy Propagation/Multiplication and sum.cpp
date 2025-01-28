#include <bits/stdc++.h>    //Codeforces - Multiplication and sum
using namespace std;        

#define int long long int
#define MAXN 100010

const int mod = 1e9 + 7;

int tree[4*MAXN];
int lazy[4*MAXN];

void build(int no, int l, int r){
    if(l==r){
        tree[no] = 1;
        return;
    }

    int mid = (l+r)/2;

    build(2*no, l, mid);
    build(2*no + 1, mid + 1, r);
    tree[no] = tree[no*2] + tree[no*2 + 1];
}

void unlazy(int no, int l, int r){
    if(lazy[no] == 1) return;

    tree[no] *= lazy[no];
    tree[no] %= mod;

    if(r != l){
        lazy [2*no] *= lazy[no];
        lazy [2*no + 1] *= lazy[no];
        lazy [2*no] %= mod;
        lazy [2*no + 1] %= mod;
    }

    lazy[no] = 1;
}

void update(int no, int i, int j, int l, int r, int val){
    unlazy(no, i, j);
    if(i > r || j < l) return;
    if(i >= l && j <= r){
        lazy[no] *= val;
        lazy[no] %= mod;
        unlazy(no, i, j);
        return;
    }

    int mid = (i+j)/2;

    update(2*no, i, mid, l, r, val);
    update(2*no + 1, mid+1, j, l, r, val);

    tree[no] = tree[no*2] + tree[no*2 + 1];
    tree[no] %= mod;
}

int query(int no, int i, int j, int l, int r){
    unlazy(no, i, j);
    
    if(i > r || j < l) return 0;
    if(i >= l && j <= r){
        return tree[no];
    }
    int mid = (i + j) / 2;

    return (query(2*no, i, mid, l, r) + query(2*no + 1, mid + 1, j, l, r)) % mod;
}

int32_t main(){
    int n, m;
    cin>>n>>m;

    for(int i=0; i <= 4*n; i++) lazy[i] = 1;

    build(1, 1, n);

    for(int i=0; i<m; i++){
        int a, b, c, d;
        cin>>a>>b>>c;

        if(a==2){
            cout<<query(1, 1, n, b + 1, c)<<"\n";
        } 
        else if(a==1){
            cin>>d;
            update(1, 1, n, b + 1, c, d);
        }
    }


    return 0;
}