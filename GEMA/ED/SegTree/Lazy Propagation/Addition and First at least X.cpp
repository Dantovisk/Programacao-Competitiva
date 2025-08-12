#include <bits/stdc++.h> //CF - Addition and First element at least X
using namespace std;        

#define MAXN 100010
#define int long long int

int tree[4*MAXN]; //seg de max
int lazy[4*MAXN];

void unlazy(int no, int l, int r){
    if(lazy[no] == 0) return;

    tree[no] += lazy[no];

    if(r != l){
        lazy [2*no] += lazy[no];
        lazy [2*no + 1] += lazy [no];
    }

    lazy[no] = 0;
}

void update(int no, int i, int j, int l, int r, int val){
    unlazy(no, i, j);
    if(i > r || j < l) return;
    if(i >= l && j <= r){
        lazy[no] += val;
        unlazy(no, i, j);
        return;
    }

    int mid = (i+j)/2;

    update(2*no, i, mid, l, r, val);
    update(2*no + 1, mid+1, j, l, r, val);

    //unlazy(no * 2, i, mid);
    //unlazy(no * 2 + 1, mid+1, j);

    tree[no] = max(tree[no*2], tree[no*2 + 1]);
}

int query(int no, int i, int j, int x, int l){
    unlazy(no, i, j);
    if(i==j) {
        if(tree[no] < x) return -1;
        return i-1;
    }
    
    int mid = (i + j) / 2;

    unlazy(no * 2, i, mid);
    unlazy(no * 2 + 1, mid+1, j);

    //necessário ignorar a parte à esquerda
    if(x > tree[no*2] || mid < l) 
        return query(2*no + 1, mid+1, j, x, l);
    //é seguro ir somente pela esquerda
    else if (i >= l) 
        return query(2*no, i, mid, x, l);

    //nesse caso, não sabemos se a resposta está na esquerda
    //ou na direita, e teremos de verificar ambos
    int a = query(2*no, i, mid, x, l);
    int b = query(2*no + 1, mid+1, j, x, l);

    if(a==-1 || b == -1) return max(a,b);
    return min(a,b);
}

int32_t main(){
    int n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b, c, d;
        cin>>a>>b>>c;

        if(a==2){
            cout<< query(1, 1, n, b, c+1) <<"\n";
        } 
        else if(a==1){
            cin>>d;
            update(1, 1, n, b + 1, c, d);
        }
    }


    return 0;
}
