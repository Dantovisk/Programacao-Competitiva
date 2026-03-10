#include <bits/stdc++.h> //CSES - Graph Paths 2
#define int long long int

using namespace std;
const int inf = 3e18+7;

using matrix = vector<vector<int>>;

//É uma fórmula diferente para multiplicação de matrizes aplicada à quant de caminhos mínimos
matrix matmult(matrix a, matrix b){
    int n = a.size();
    matrix resp(n, vector<int>(n, inf));

    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            for(int k =0; k<n; k++){
                resp[i][j] = min(a[i][k] + b[k][j], resp[i][j]);
            }
        }
    }
    return resp;
}

//precisamos achar o tamanho do caminho mínimo de 1 a n usando k nós
int32_t main(){
    int n, m, k; 
    cin>>n >> m>> k;

    matrix mt(n, vector<int>(n, inf));
    matrix base(n, vector<int>(n, -1));

    for(int i=0; i<m; i++){
        int a, b, c; cin>>a>>b>>c;
        a--; b--;
        //pode ter mais de uma aresta entre dois nós
        mt[a][b] = min(mt[a][b], c);
    }

    bool foi = true;

    for(; k>0; k/=2, mt = matmult(mt, mt)){
        if(k % 2){
            if(foi){
                base = mt;
                foi = false;
            }
            else base = matmult(base, mt);
        }
    }

    cout<<(base[0][n-1] == inf? -1: base[0][n-1]);

}