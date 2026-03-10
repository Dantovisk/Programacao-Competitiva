#include <bits/stdc++.h> //CSES - Graph Paths 1
#define int long long int

using namespace std;
const int mod = 1e9+7;

using matrix = vector<vector<int>>;

//multiplicacao de matrizes
matrix matmult(matrix a, matrix b){
    int n = a.size();
    matrix resp(n, vector<int>(n, 0));

    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            for(int k =0; k<n; k++){
                resp[i][j] += (a[i][k] * b[k][j]) % mod;
                resp[i][j] %= mod;
            }
        }
    }
    return resp;
}


int32_t main(){
    int n, m, k; 
    cin>>n >> m>> k;

    matrix mt(n, vector<int>(n, 0));
    matrix base(n, vector<int>(n, 0));

    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        a--; b--;
        //pode ter mais de uma aresta entre dois nós
        mt[a][b] ++;
    }

    for(int i =0; i<n; i++) base[i][i] = 1;


    for(; k>0; k/=2, mt = matmult(mt, mt)){
        if(k % 2) base = matmult(base, mt);
    }

    cout<<base[0][n-1];

}