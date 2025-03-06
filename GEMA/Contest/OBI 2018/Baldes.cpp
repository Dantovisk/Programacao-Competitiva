#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;
#define int long long int
#define tii tuple<int,int,int> 

//segtree de min
int bmin[4*MAXN];

//segtree de max
int bmax[4*MAXN];

//diferença maxima entre os baldes
int tree[4*MAXN];
//tree[no] =
//max( tree à esq, tree à dir, diff max entre dir e esq)

int v[MAXN];
const int inf = 1e7;

void build(int no, int l, int r){
    if(l==r){
        tree[no] = 0;
        bmax[no] = v[l];
        bmin[no] = v[l];
        return;
    }

    int mid = (l+r)/2;

    build(no*2, l, mid);
    build(no*2 + 1, mid+1, r);

    bmax[no] = max(bmax[no*2], bmax[2*no + 1]);
    bmin[no] = min(bmin[no*2], bmin[2*no + 1]);

    tree[no] = max({tree[no*2], tree[2*no+1], 
        bmax[2*no]-bmin[2*no+1], bmax[2*no + 1]-bmin[2*no]});
}

void update(int no, int i, int j, int id, int val){
    if(i>id || j<id) return;
    if(i==j){
        bmax[no] = max(bmax[no], val);
        bmin[no] = min(bmin[no], val);
        return;
    }

    int mid = (i+j)/2;

    update(no*2, i, mid, id, val);
    update(no*2 + 1, mid+1, j, id, val);

    bmax[no] = max(bmax[no*2], bmax[2*no + 1]);
    bmin[no] = min(bmin[no*2], bmin[2*no + 1]);

    tree[no] = max({tree[no*2], tree[2*no+1], 
        bmax[2*no]-bmin[2*no+1], bmax[2*no + 1]-bmin[2*no]});
}

//tree, min, max
tii query(int no, int i, int j, int l, int r){
    if(i>r || j<l) return {0,inf,0};
    if(i >= l && j <= r){
        return {tree[no], bmin[no], bmax[no]};
    }
        

    int mid = (i+j)/2;

    auto [a,b,c] = query(2*no, i, mid, l, r);
    auto [d,e,f] = query(2*no + 1, mid+1, j, l, r);
    
    return {max({a, d, c-e, f-b}), min(b, e), max(c, f)};
    
}

int32_t main(){
    int n, m; cin>>n>>m;
    
    for(int i = 1; i<=n; i++){
        cin>>v[i];
    }

    build(1, 1, n);

    for(int i=0; i<m; i++){
        int a, b, c; cin>>a>>b>>c;

        if(a==1){
            update(1, 1, n, c, b);
        } else{
            auto [d, e, f] = query(1, 1, n, b, c);
            cout<<d<<"\n";
        }
    }

    return 0;
}