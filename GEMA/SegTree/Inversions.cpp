#include <bits/stdc++.h>
#define MAXN 100010
//#define int long long int
using namespace std;

int tree [4*MAXN];
int v[MAXN];

// l, r são o intervalo desejado, i,j sao o atual
int query(int no, int i, int j, int l, int r){
    if(j<l || i>r) return 0;
    if(i>=l && j<=r) return tree[no];

    int mid = (i+j)/2;

    return query(2*no, i, mid, l, r) + query(2*no +1, mid+1, j, l, r);

}

void update(int no, int l, int r, int ind){
    if(r<ind || l>ind) return;
    if(l==ind && r ==ind){
        tree[no] = 1;
        return;
    }

    int mid = (l+r)/2;
    update(no*2, l, mid, ind);
    update(no*2+1, mid+1, r, ind);

    tree[no] = tree[no*2] + tree[no*2 +1];
}



int main(){
    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>v[i];
    }


    for(int i=1; i<=n; i++){
        cout<<query(1, 1, n, v[i], n)<<" ";
        update(1, 1, n, v[i]);
    }

    return 0;
}