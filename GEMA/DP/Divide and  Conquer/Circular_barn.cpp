#include <bits/stdc++.h>  //usaco

using namespace std;

typedef long long ll;

ll dp[1100][8];
ll v[2100];

//Custo acumulado de mover a rapaziada de i  até j;
ll sum [2010][1010];

const ll inf = 1e16 + 67;

int rot = 0;

// calcule dp[x][k] para todo x em [st, ed], sabendo que a porta k pode
// estar em qualquer ponto de [l, r]
void solve(int k, int st, int ed, int l, int r){
    int mid = (st+ed)/2;

    ll meior = inf, goat = -1;

    for(int u = l; u<= min(mid, r); u++){
        ll custo = dp[u-1][k-1] + sum[u+rot][mid-u+1];
        if(custo < meior){
            meior = custo;
            goat = u;
        }else if(custo == meior && u < goat){
            goat = u;
        }
    }

    dp[mid][k] = meior;

    if(st == ed) return;

    solve(k, st, mid, l, goat);
    solve(k, mid+1, ed, goat, r);
}

int main(){
    freopen("cbarn.in", "r", stdin);

    int n, k;
    cin>>n>>k;

    for(int i =0; i<n; i++){
        cin>>v[i];
        v[i+n] =  v[i];
    }   

    for(int i =0; i<n; i++){
        for(int j =1; j<=n; j++){
            sum[i][j] = sum[i+n][j] = sum[i][j-1] + v[j + i - 1] * (j-1);
        }
    }

    ll resp = inf;

    for(rot= 0; rot<n; rot++){
        for(int i =0; i <n; i++){
            dp[i][0] = sum[rot][i+1];
        }
        for(int i =1; i<k; i++){
            for (int j = 0; j < n; j++) { dp[j][i] = inf; }
            solve(i, i, n-1, i, n-1);
        }
        resp = min(resp, dp[n-1][k-1]);
    }

    freopen("cbarn.out", "w", stdout);
    cout<<resp<<"\n";
}