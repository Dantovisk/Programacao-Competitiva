#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

int tree [8*MAXN];
//int v[2*MAXN];
int tin[MAXN];
int tout[MAXN];
/*
void build(int no, int l, int r){
    if(l==r){
        tree[no] = v[l];
        return;
    }

    int mid = (l+r)/2;
    build (2*no, l, mid);
    build (2*no+1, mid+1, r);

    tree[no] = tree[2*no] + tree[2*no+1];
}*/

//seg de soma
int query(int no, int i, int j, int l, int r){
    if(i>r || j< l) return 0;
    if(i>= l && j<=r){
        return tree[no];
    }

    int mid = (i+j)/2;
    return query(no*2, i, mid, l, r) + query(no*2+1, mid+1, j, l, r);
}

void update(int no, int l, int r, int id){
    if(l>id || r<id) return;
    if(l==r){
        tree[no] = 1;
        return;
    }
    int mid = (l+r)/2;

    update(no*2, l, mid, id);
    update(no*2+1, mid+1, r, id);

    tree[no] = tree[no*2+1]+tree[no*2];
}



int main(){
    int n;
    cin>>n;

    vector <int> ord;

    for(int i=1; i<=2*n; i++){
        int a; cin>>a;

        if(tin[a] != 0){
            tout[a] = i;
            //v[i] = 1;
            ord.push_back(a);
        }
        else tin[a] = i;
    }

    //build (1, 1, 2*n);

    map<int, int> resp;

    for(int x: ord){
        resp[x] = query(1, 1, 2*n, tin[x], tout[x]);
        update(1, 1, 2*n, tin[x]);
    }

    for(int i=1; i<=n; i++){
        cout<<resp[i]<<" ";
    }
   

    return 0;
}