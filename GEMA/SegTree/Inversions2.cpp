#include <bits/stdc++.h>
#define MAXN 100010
//#define int long long int
using namespace std;

int tree [4*MAXN];
int v[MAXN];

void build(int no, int l, int r){
    if(l==r){
        tree[no] = 1;
        return;
    }

    int mid = (l+r)/2;
    build (2*no, l, mid);
    build (2*no+1, mid+1, r);

    tree[no] = tree[2*no] + tree[2*no+1];
}

//buscando k-th one da direita pra esquerda
int query(int no, int l, int r, int saldo){
    if(l==r) return l;

    int mid = (l+r)/2;

    if(tree[no*2+1] <= saldo) return query(no*2, l, mid, saldo - tree[no*2+1]);

    return query(no*2+1, mid+1, r, saldo);
}

void update(int no, int l, int r, int ind){
    if(r<ind || l>ind) return;
    if(l==r){
        tree[no] = 0;
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

    build (1, 1, n);


    vector <int> resp;
    for(int i=n; i>0; i--){
        int a = query(1, 1, n, v[i]);
        update(1, 1, n, a);

        resp.push_back(a);
    }
    reverse(resp.begin(), resp.end());

    for(int x: resp) cout<<x<<" ";

    return 0;
}