#include <bits/stdc++.h>    //Assignment and Max Segment - CF
using namespace std;        

#define int long long int
#define MAXN 100010

const int maxval = 1e9 + 69;

int tree[4*MAXN];  //max segment
int pref[4*MAXN];  //max prefix
int suf[4*MAXN];  //max suffix
int sum[4*MAXN];  //sum of elements in range

int lazy[4*MAXN];

void unlazy(int no, int l, int r){
    if(lazy[no] == maxval) return;

    sum[no] = lazy[no] * (r-l+1);
    pref[no] = max(sum[no], (long long)0);
    suf[no] = max(sum[no], (long long)0);
    tree[no] = max(sum[no], (long long)0);

    if(r != l){
        lazy [2*no] = lazy[no];
        lazy [2*no + 1] = lazy[no];
    }

    lazy[no] = maxval;
}

void update(int no, int i, int j, int l, int r, int val){
    unlazy(no, i, j);
    if(i > r || j < l) return;
    if(i >= l && j <= r){
        lazy[no] = val;
        unlazy(no, i, j);
        return;
    }

    int mid = (i+j)/2;

    update(2*no, i, mid, l, r, val);
    update(2*no + 1, mid+1, j, l, r, val);

    sum[no] = sum[2*no] + sum[2*no+1];

    pref[no] = max(pref[2*no], sum[2*no] + pref[2*no+1]);

    suf[no] = max(suf[2*no + 1], sum[2*no + 1] + suf[2*no]);

    tree[no] = max({tree[no*2], tree[no*2 + 1], suf[2*no] + pref[2*no+1]});
}

int32_t main(){
    int n, m;
    cin>>n>>m;

    for(int i=0; i<= n * 4; i++){
        lazy[i] = maxval;
    }

    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;

        update(1, 1, n, a + 1, b, c);

        cout<<tree[1]<<"\n";
    }


    return 0;
}