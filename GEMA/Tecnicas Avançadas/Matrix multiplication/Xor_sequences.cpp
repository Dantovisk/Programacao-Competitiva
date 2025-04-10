#include <bits/stdc++.h>

using namespace std;
#define int long long
using matrix = vector<vector<int>>;

const int mod = 1e9+7;
int v[110];


matrix mult(matrix a, matrix b){
    int n = a.size();
    matrix res(n, vector<int>(n, 0));
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            for(int k =0; k<n; k++){
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= mod;
            }
        }
    }
    return res;
}

int32_t main(){
    int n, k;
    cin>>n>>k;
    k--;

    for(int i = 0; i< n; i++){
        cin>>v[i];
    }

    matrix mt(n, vector<int>(n, 0));
    matrix base(n, vector<int>(n, 0));
    for(int i = 0; i< n; i++){
        for(int j = 0; j< n; j++){
            if (__popcount((v[i]^v[j]))%3) continue;
            mt[i][j] = 1;
        }
    }

    for(int i = 0; i< n; i++)
        base[i][i] = 1;

    for(; k>0; k/=2, mt = mult(mt, mt)){
        if(k & 1) base = mult(base, mt);
    }

    int resp = 0;
    for(auto x: base){
        for (auto y: x){
            resp += y;
            resp %= mod;
        }
    }
    cout<<resp<<endl;

    return 0;
}