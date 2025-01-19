#include <bits/stdc++.h>    //falta completar
#define MAXN 200010
using namespace std;

const int inf = 1e9 + 9;

int tree[MAXN*4];
int v[MAXN];
int nv[MAXN];

//para compressão de coordenadas
vector <pair<int, int>> compres;
map <int, int> dicio;

void build(int no, int l, int r){
    if(l==r){
        tree[no] = v[l];
        return;
    }

    int mid = (l+r)/2;

    build(no*2, l, mid);
    build(no*2+1, mid+1, r);

    tree[no] = min(tree[no*2], tree[no*2+1]);
}

void update(int no, int l, int r, int indx, int x){
    if(l==r){
        v[l] = x;
        tree[no] = x;
        return;
    }

    int mid = (l+r)/2;

    if(l<= indx && indx <= mid) update(no*2, l, mid, indx, x);
    else update(no*2 +1, mid+1, r, indx, x);

    tree[no] = min(tree[no*2], tree[no*2+1]);
}

// l, r são o intervalo desejado, i,j sao o atual
int query(int no, int i, int j, int l, int r){
    if(i>r || j<l) return inf;
    if(i>= l && j<= r) return tree[no];

    int mid = (i+j)/2;

    return min(query(no*2, i, mid, l, r), query(no*2 +1, mid+1, j, l, r));
}


int main(){
    int n, q;
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>v[i];
        compres.push_back({v[i], i});
    }

    sort(compres.begin(), compres.end());

    for(int i=0; i<n; i++) nv[compres[i].second] = i;

    build(1, 1, n);

    for(int i=0; i<q; i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1) update(1, 1, n, b+1, c);
        else cout<<query(1, 1, n, b+1, c)<<"\n";

    }
    return 0;
}