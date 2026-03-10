#include <bits/stdc++.h>
#define int long long int
#define SZ 2 //tamanho da matriz

using namespace std;
const int mod = 1e9+7;

using matrix = array<array<int, SZ>, SZ>;

matrix matmult(matrix a, matrix b){
    matrix k = {{{0, 0}, {0,0}}};
    for(int i =0; i< SZ; i++){
        for(int j =0;j<SZ; j++){
            for(int ct =0; ct <SZ; ct++){
                k[i][j] += a[i][ct] * b[ct][j];
                k[i][j] %= mod;
            }
        }
    }
    return k;
}

matrix matexp(matrix a, int exp){
    if(exp == 0) return {{{1,0},{0, 1}}};
    if(exp == 1) return a;
    matrix k = matexp(a, exp/2);
    matrix v = matmult(k, k);
    if(exp % 2){
        return matmult(a, v);
    }
    return v;
}

int32_t main(){
    int n; cin>>n;

    matrix m = {{{1,1},{1,0}}};

    matrix res = matexp(m, n);
    cout<<res[0][1];
}