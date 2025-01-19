#include <bits/stdc++.h>
#define MAXN 200010
#define ll long long int
using namespace std;

ll tree [4*MAXN];
int v[MAXN];

void build(int no, int l, int r){
    if(l==r){
        tree[no] = v[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*no, l, mid);
    build(1 + 2*no, mid+1, r);
    tree[no] = tree[2*no] + tree[2*no +1];
}

// l, r são o intervalo desejado, i,j sao o atual
ll query(int no, int i, int j, int l, int r){
    if(j<l || i>r) return 0;
    if(i>=l && j<=r) return tree[no];

    int mid = (i+j)/2;

    return query(2*no, i, mid, l, r) + query(2*no +1, mid+1, j, l, r);

}

void update(int no, int l, int r, int ind, int value){
    if(r<ind || l>ind) return;
    if(l==ind && r ==ind){
        tree[no] = value;
        return;
    }

    int mid = (l+r)/2;
    update(no*2, l, mid, ind, value);
    update(no*2+1, mid+1, r, ind, value);

    tree[no] = tree[no*2] + tree[no*2 +1];
}



int main(){
    int n, q;
    cin>>n>>q;

    for(int i=1; i<=n; i++){
        cin>>v[i];
    }

    build(1,1,n);

    for(int i=0; i<q; i++){
        int a, b, c;
        cin>>a>>b>>c;
        if(a==2){
            cout<<query(1, 1, n, b, c)<<"\n";
        }else if(a==1){
            update(1, 1, n, b, c);
        }
    }

    return 0;
}