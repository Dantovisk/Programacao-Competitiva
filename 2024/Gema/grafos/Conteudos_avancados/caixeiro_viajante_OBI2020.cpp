#include <bits/stdc++.h> //nao esta funcionando

using namespace std;

int adj[1510][1510];
int dp[1510][1510];

vector <vector<int>> pos;

int solve(int a, int b){
    
}

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