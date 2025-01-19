#include <bits/stdc++.h>
#define MAXN 100010
#define int long long int

using namespace std;

int v[MAXN];

//soma max no intervalo
int tree[4*MAXN];
int pref[4*MAXN];
int suf[4*MAXN];
int sum[4*MAXN];


void build(int no, int l, int r){
    if(l==r){
        sum[no] = v[l];
        int k = (v[l] > 0 ? v[l] : 0);
        tree[no] = k;
        pref[no] = k;
        suf[no] = k;
        return;
    }

    int mid = (l+r)/2;

    build(2*no, l, mid);
    build(2*no+1, mid+1, r);

    sum[no] = sum[no*2] + sum[no*2+1];

    pref[no] = max(sum[no*2] + pref[no*2+1], pref[no*2]);

    suf[no] = max(suf[no*2] + sum[no*2+1], suf[no*2+1]);

    tree[no] = max({suf [2*no] + pref[2*no+1], tree[2*no], tree[2*no+1]});
}

void update(int no, int l, int r, int id, int val){
    if(l>id || r<id) return;
    if(l==r){
        sum[no] = val;
        int k = (val > 0 ? val : 0);
        tree[no] = k;
        pref[no] = k;
        suf[no] = k;
        return;
    }

    int mid = (l+r)/2;

    update(2*no, l, mid, id, val);
    update(2*no+1, mid+1, r, id, val);

    sum[no] = sum[no*2] + sum[no*2+1];

    pref[no] = max(sum[no*2] + pref[no*2+1], pref[no*2]);

    suf[no] = max(suf[no*2] + sum[no*2+1], suf[no*2+1]);

    tree[no] = max({suf [2*no] + pref[2*no+1], tree[2*no], tree[2*no+1]});
}

int32_t main(){
    int n, m;
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        cin>>v[i];
    }

    build(1, 1, n);
    cout<<tree[1]<<"\n";

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        update(1, 1, n, a+1, b);
        cout<<tree[1]<<"\n";
    }


    return 0;
}