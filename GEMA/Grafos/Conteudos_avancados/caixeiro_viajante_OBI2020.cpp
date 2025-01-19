#include <bits/stdc++.h> //nao esta funcionando

using namespace std;

int adj[1510][1510];
int dp[1510][1510];

vector <vector<int>> pos;

int solve(int a, int b){
    
}
/*
    int solve(int a, int b){
        if(dp[a][b] != -1) return dp[a][b] ; 
        int i = max(a, b) ; 
        if(i > n) return 0 ; 
        int antes_a = solve(i+1, b) + ar[i+1][a] ; 
        int depois_b = solve(a, i+1) + ar[i+1][b] ; 
        return dp[a][b] = min(antes_a, depois_b) ; 
    }
*/
int main() {
    int n;
    cin >> n;
    
    for(int i=0; i < (n*(n-1))/2; i++){
        int a, b, c;
        cin>>a>>b>>c;
        adj[a][b] = c;
        adj[b][a] = c;
    }

    memset(dp, -1, sizeof(dp));

    cout<< solve (1, 1);
    return 0;
}