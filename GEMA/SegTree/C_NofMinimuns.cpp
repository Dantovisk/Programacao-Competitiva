#include <bits/stdc++.h>    //exemplo para encontrar a soma dos elementos no intervalo
#define MAXN 100010
using namespace std;

const int inf = 1e9 + 9;

// numero minimo, numero de minimos
pair<int, int> tree[MAXN*4];
int v[MAXN];

void build(int no, int l, int r){
    if(l==r){
        tree[no] = {v[l], 1};
        return;
    }

    int mid = (l+r)/2;

    build(no*2, l, mid);
    build(no*2+1, mid+1, r);

    if(tree[no*2].first == tree[no*2+1].first){
        tree[no] = tree[no*2];
        tree[no].second += tree[no*2+1].second;
    }
    else tree[no] = min(tree[no*2], tree[no*2+1]);
}

void update(int no, int l, int r, int indx, int x){
    if(l==r){
        v[l] = x;
        tree[no] = {x,1};
        return;
    }

    int mid = (l+r)/2;

    if(l<= indx && indx <= mid) update(no*2, l, mid, indx, x);
    else update(no*2 +1, mid+1, r, indx, x);

    if(tree[no*2].first == tree[no*2+1].first){
        tree[no] = tree[no*2];
        tree[no].second += tree[no*2+1].second;
    }
    else tree[no] = min(tree[no*2], tree[no*2+1]);
}


pair <int,int> query(int no, int i, int j, int l, int r){
    if(i>r || j<l) return {inf, 1};
    if(i>= l && j<= r) return tree[no];

    int mid = (i+j)/2;

    auto x1 = query(no*2, i, mid, l, r);
    auto x2 = query(no*2 +1, mid+1, j, l, r);

    if(x1.first == x2.first) {
        return {x1.first, x1.second + x2.second};
    } else if (x1.first < x2.first) {
        return x1;
    } else {
        return x2;
    }
}


int main(){
    int n, q;
    cin>>n>>q;
    for(int i=1; i<=n; i++) cin>>v[i];

    build(1, 1, n);

    for(int i=0; i<q; i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1) update(1, 1, n, b+1, c);
        else {
            auto x = query(1, 1, n, b+1, c);
            cout<<x.first<<" "<<x.second<<"\n";
        }

    }
    return 0;
}