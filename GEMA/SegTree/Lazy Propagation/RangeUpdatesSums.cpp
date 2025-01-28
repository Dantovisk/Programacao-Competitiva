#include <bits/stdc++.h>
#define MAXN 200010
#define int long long int
using namespace std;

int v[MAXN];

// relativos à arvore
int tree[4*MAXN]; 

int lazySum[4*MAXN];
int lazySet[4*MAXN];


void build(int no, int l, int r){
    if(l==r){
        tree[no] = v[l];
        return;
    }
    
    int mid = (l+r)/2;
    build(no*2, l, mid);
    build(no*2 +1, mid+1, r);

    tree[no] = tree[no*2] + tree[no*2 +1];
}

void unlazy(int no, int l, int r){
    if(lazySet[no] != 0){
        tree[no] = (r - l + 1) * lazySet[no];

        if(l != r){
            lazySet[2*no] = lazySet[no];
            lazySet[2*no + 1] = lazySet[no];

            lazySum[2*no] = 0;
            lazySum[2*no + 1] = 0;
        }

        lazySet[no] = 0;

    } 

    if(lazySum[no] != 0){
        tree[no] += (r - l + 1) * lazySum[no];

        if(l != r){
            lazySum[2*no] += lazySum[no];
            lazySum[2*no + 1] += lazySum[no];
        }

        lazySum[no] = 0;

    } 

    
}

//seta todos os valores no intervalo [l,r] para value
void updateSet(int no, int i, int j, int l, int r, int value){
    unlazy(no, i, j);
    
    if(i > r || j < l) return;

    if(i>= l && j<= r){
        lazySet[no] = value;
        unlazy(no, i, j);
        return;
    }

    int mid = (i+j)/2;

    updateSet(2*no, i, mid, l, r, value);
    updateSet(2*no + 1, mid+1, j, l, r, value);

    tree[no] = tree[no*2] + tree[no*2 + 1];
}

void updateSum(int no, int i, int j, int l, int r, int value){
    // a gente limpa a lazy antes de 
    unlazy(no, i, j);

    if(i > r || j < l) return;

    if(i>= l && j<=r){
        lazySum[no] = value;
        unlazy(no, i, j);
        return;
    }

    int mid = (i+j)/2;

    updateSum(2*no, i, mid, l, r, value);
    updateSum(2*no + 1, mid+1, j, l, r, value);

    tree[no] = tree[no*2] + tree[2*no + 1];
}

int query(int no, int i, int j, int l, int r) {
    unlazy(no, i, j); // Aplica as operações pendentes
    if (i > r || j < l) return 0;
    if (i >= l && j <= r) return tree[no];

    int mid = (i + j) / 2;
    return query(no * 2, i, mid, l, r) + query(no * 2 + 1, mid + 1, j, l, r);
}



int32_t main(){
    int n, q;
    cin>>n>>q;

    for(int i=1; i<=n; i++){
        cin>>v[i];
    }

    build(1, 1, n);

    for(int i=0; i<q; i++){
        int a, b, c, d;
        cin>>a>>b>>c;

        if(a==1){
            cin>>d;
            updateSum(1, 1, n, b, c, d);
        }else if(a==2){
            cin>>d;
            updateSet(1, 1, n, b, c, d);
        }else if(a==3){
            cout<<query(1, 1, n, b, c)<<"\n";
        }
    }

    return 0;
}