#include <bits/stdc++.h>    //Codeforces - Addition and minimum
using namespace std;        

#define int long long int
#define MAXN 100010

const int inf = 1e16 + 123;

int tree[4*MAXN];
int lazy[4*MAXN];

void unlazy(int no, int l, int r){
    if(lazy[no] == 0) return;

    tree[no] += lazy[no];

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

    tree[no] = min(tree[no*2], tree[no*2 + 1]);
}

int query(int no, int i, int j, int l, int r){
    unlazy(no, i, j);
    
    if(i > r || j < l) return inf;
    if(i >= l && j <= r){
        return tree[no];
    }
    int mid = (i + j) / 2;

    return min(query(2*no, i, mid, l, r), query(2*no + 1, mid + 1, j, l, r));
}

int32_t main(){
    int n, m;
    cin>>n>>m;

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