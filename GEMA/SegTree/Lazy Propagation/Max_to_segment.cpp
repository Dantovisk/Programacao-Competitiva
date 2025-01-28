#include <bits/stdc++.h>    //Codeforces
using namespace std;        //Applying MAX to Segment

#define int long long int
#define MAXN 100010

int tree[4*MAXN];
int lazy[4*MAXN];

void unlazy(int no, int l, int r){
    if(lazy[no] == 0) return;

    tree[no] = max(lazy[no], tree[no]);

    if(r > l){
        lazy [2*no] = max(lazy [2*no], lazy[no]);
        lazy [2*no + 1] = max(lazy [2*no + 1], lazy[no]);
    }

    lazy[no] = 0;
}

void update(int no, int i, int j, int l, int r, int val){
    unlazy(no, i, j);
    if(i > r || j < l) return;
    if(i >= l && j <= r){
        lazy[no] = max(lazy[no], val);
        unlazy(no, i, j);
        return;
    }

    int mid = (i+j)/2;

    update(2*no, i, mid, l, r, val);
    update(2*no + 1, mid+1, j, l, r, val);
}

int query(int no, int l, int r, int id){
    unlazy(no, l, r);
    if(l > id || r < id) return 0;
    if(l==r) return tree[no];

    int mid = (l+r)/2;
    return query(no*2, l, mid, id) + query(no*2 + 1, mid+1, r, id);
}

int32_t main(){
    int n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b, c, d;
        cin>>a>>b;

        if(a==2){
            cout<<query(1, 1, n, b + 1)<<"\n";
        } 
        else if(a==1){
            cin>>c>>d;
            update(1, 1, n, b + 1, c, d);
        }
    }


    return 0;
}