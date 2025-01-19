#include <bits/stdc++.h>//falta continuar

using namespace std;

vector<int>adj[300010];
int n, k;
int cont = 0;

// retorna numero de radares usados até o momento, e o quao 
// perto está de outro radar
pair<int,int> dfs (int u, int r, int pai){

}

bool solve(int r){
    cont = 0;
    auto x = dfs(1, r, 0);
    if(x.second >= 0)cont++;
    return cont <= k;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;
    for(int i=1; i<n; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int maxR = 300000;
    int minR = 1;
    int med = (maxR+minR)/2; 

    while(minR < maxR){
        med = (maxR+minR)/2;
        if(solve(med)) maxR = med;
        else minR = med+1;
    }

    cout<< med;


    return 0;
}