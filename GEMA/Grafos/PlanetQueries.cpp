#include <bits/stdc++.h>    //CSES -Planet Queries I

using namespace std;
int n, q;
int prox[31][200010];

int main(){
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0); 

    cin>>n>>q;

    for(int i=1; i<=n; i++){
        cin>>prox[0][i];
    }
    for(int i=1; i<=30; i++){
        for(int j=1; j<=n; j++){
            prox[i][j]= prox[i-1][prox[i-1][j]];
        }
    }
    for(int i=0; i<q; i++){
        int a, b;
        cin>>a>>b;
        
        for(int k = 0; k<=30; k++){
            if(b&(1<<k)) a = prox[k][a];
        }

        cout<<a<<"\n";
    }
    

    return 0;
}