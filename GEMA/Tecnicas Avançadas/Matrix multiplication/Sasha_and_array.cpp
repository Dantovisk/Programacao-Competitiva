#include <bits/stdc++.h>    //Sasha and Array- CF
using namespace std;        

#define ll long long
#define MAXN 100010

const ll mod = 1e9 + 7;

//trees de soma
//int tree[4*MAXN]; //guarda os indices 
int tree1[4*MAXN];  // guarda a somas dos f(i)
int tree2[4*MAXN];  // guarda a soma dos f(i-1)
ll lazy[4*MAXN];

int v[MAXN];

using matrix = array<array<ll, 2>, 2>;

matrix base = {{{1,1},{1,0}}};

inline matrix mul(const matrix &a, const matrix &b) {
    matrix res = {};

    ll x1 = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % mod;
    ll x2 = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % mod;
    ll x3 = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % mod;
    ll x4 = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % mod;

    res[0][0] = x1;
    res[0][1] = x2;
    res[1][0] = x3;
    res[1][1] = x4;

    return res;
}

//retorna:
/*
f(i+1)  f(i)
f(i)    f(i-1)  
*/
matrix mexp(ll k){
    if(k == 0) return {{{1, 0}, {0, 1}}};
    if(k == 1) return base;

    matrix res = mexp(k/2);
    res = mul(res, res);

    if(k%2) return mul(res, base);
    return res;
}

//retorna o f(k)
int fib(int k){
    matrix res = mexp(k);
    return res[0][1];

    return 0;
}

void unlazy(int no, int l, int r){
    if(lazy[no] == 0) return;

    //cout<<l<<" - "<<r<<": "<<tree2[no]<<" "<<tree1[no]<<" vai virar:\n";
    matrix a = mexp(lazy[no]);
    matrix b = {{{tree1[no], 0}, {tree2[no], 0}}};

    matrix res = mul(a, b);
    tree1[no] = res[0][0];
    tree2[no] = res[1][0];

    //cout<<l<<" - "<<r<<": "<<tree2[no]<<" "<<tree1[no]<<"\n";

    if(r != l){
        lazy [2*no] += lazy[no];
        lazy [2*no + 1] += lazy[no];
    }

    lazy[no] = 0;
}

void update(int no, int i, int j, int l, int r, int val){
    unlazy(no, i, j);
    if(i > r || j < l) return;
    if(i >= l && j <= r){
        lazy[no] += val;
        unlazy(no, i, j);
        return;
    }

    int mid = (i+j)/2;

    update(2*no, i, mid, l, r, val);
    update(2*no + 1, mid+1, j, l, r, val);

    tree1[no] = (tree1[2*no+1] + tree1[2*no]) % mod;
    tree2[no] = (tree2[2*no+1] + tree2[2*no]) % mod;
}
void build(int no, int l, int r){
    if(l == r){
        matrix mat = mexp(v[l]);
        tree1[no] = mat[0][1];
        tree2[no] = mat[1][1];
        return ;
    }
    int mid = (l+r)/2;

    build(2*no, l, mid);
    build(2*no+1, mid+1, r);
    
    tree1[no] = (tree1[2*no+1] + tree1[2*no]) % mod;
    tree2[no] = (tree2[2*no+1] + tree2[2*no]) % mod;
}

int query(int no, int i, int j, int l, int r){
    //cout<<"to em ["<<i<<","<<j<<"]\n";
    unlazy(no, i, j);
    if(i > r || j < l) return 0;
    if(i>= l && j <= r) return tree1[no];

    int mid = (i+j)/2;
    
    return (query(2*no, i, mid, l, r)  +
    query(2*no+1, mid+1, j, l, r)) % mod;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;
    for(int i = 1; i <=n; i++){
        cin>>v[i];
    }
    build(1, 1, n);


    for(int i=0; i<m; i++){
        int a, b, c, x;
        cin>>a>>b>>c;

        if(a == 1){
            cin>>x;
            update(1, 1, n, b, c, x);
        }else{
            cout<<query(1, 1, n, b, c)<<"\n";
        }

    }

    return 0;
}