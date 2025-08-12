#include <bits/stdc++.h>    //exemplo para encontrar a soma dos elementos no intervalo
#define MAXN 100010
#define int long long
using namespace std;

int tree[MAXN*4];
int v[MAXN];

void build(int no, int l, int r){
    if(l==r){
        tree[no] = v[l];
        return;
    }

    int mid = (l+r)/2;

    build(2*no, l, mid);
    build(2*no+1, mid+1, r);

    tree[no] = tree[2*no] + tree[(2*no)+1];
}

//l e r ->intervalo atual sendo observado
// indx -> indice do valor no vetor v que será substituido
// x -> elemento a ser substituido
void update(int no, int l, int r, int indx, int x){
    if(l==r){
        tree[no] = x;
        v[l] = x;
        return;
    }

    int mid = (l+r)/2;

    if(l <= indx && indx <= mid) update(2*no, l, mid, indx, x);
    else update(2*no + 1, mid+1, r, indx, x);

    tree[no] = tree[(no*2)] + tree[(no*2)+1];
}

// i j -> o intervalo que o no atual abrange
// l r -> intervalo desejado
int query(int no, int i, int j, int l, int r){
    //esté fora do intervalo desejado
    if(l > j || r < i) return 0;
    //está dentro do intervalo, não precisamos entrar em uma recursão ainda mais profunda
    if(l <= i && r>=j) return tree[no];

    int meio = (i+j)/2;
    return query(2*no, i, meio, l, r) + query(2*no+1, meio +1, j, l, r);
}


int32_t main(){
    int n, q;
    cin>>n>>q;
    for(int i=1; i<=n; i++) cin>>v[i];

    build(1, 1, n);

    for(int i=0; i<q; i++){
        int a, b, c;
        cin>>a>>b>>c;
        if(a==1) update(1, 1, n, b+1, c);
        else cout << query(1, 1, n, b+1, c)<<"\n";
    }
    return 0;
}