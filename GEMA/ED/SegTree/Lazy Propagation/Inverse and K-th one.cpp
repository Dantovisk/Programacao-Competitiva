#include <bits/stdc++.h>    //Codeforces - Inverse and K-th one
using namespace std;        

#define MAXN 100010

int tree[4*MAXN];
int lazy[4*MAXN];

void unlazy(int no, int l, int r){
    if(lazy[no] == 0) return;

    tree[no] = (r-l+1) - tree[no];

    if(r != l){
        lazy [2*no] = !(lazy [2*no]);
        lazy [2*no + 1] = !(lazy [2*no + 1]);
    }

    lazy[no] = 0;
}

void update(int no, int i, int j, int l, int r){
    unlazy(no, i, j);
    if(i > r || j < l) return;
    if(i >= l && j <= r){
        lazy[no] = !(lazy[no]);
        unlazy(no, i, j);
        return;
    }

    int mid = (i+j)/2;

    update(2*no, i, mid, l, r);
    update(2*no + 1, mid+1, j, l, r);

    tree[no] = tree[no*2] + tree[no*2 + 1];
}

int query(int no, int i, int j, int cont){
    unlazy(no, i, j);
    if(i==j) return i-1;
    
    int mid = (i + j) / 2;

    unlazy(no * 2, i, mid);
    unlazy(no * 2 + 1, mid+1, j);

    if(cont < tree[no*2]) return query(2*no, i, mid, cont);
    else return query(2*no + 1, mid+1, j, cont- tree[2*no]);
}

int main(){
    int n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b;

        if(a==2){
            cout<< query(1, 1, n, b) <<"\n";
        } 
        else if(a==1){
            cin>>c;
            update(1, 1, n, b + 1, c);
        }
    }


    return 0;
}
