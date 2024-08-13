#include <bits/stdc++.h>

using namespace std;

int cont [102][102];
int cont2 [102][102];
int celulas [102][102];

void adj(int i, int j, int v){
    cont2[i+1][j]+=v;   cont2[i][j-1]+=v;
    cont2[i+1][j+1]+=v;   cont2[i-1][j+1]+=v;
    cont2[i+1][j-1]+=v;   cont2[i-1][j]+=v;
    cont2[i][j+1]+=v;   cont2[i-1][j-1]+=v;
}

int main() {
    int n, q;
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            scanf(" %1d", &celulas[i][j]);
            if(celulas[i][j] > 0){
                adj(i, j, 1);
            }
        }
    }

    for(int z=0; z<q; z++){

        for(int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                cont[i][j]=cont2[i][j];
                //cont2[i][j]=0;
            }
        }

        for(int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                if(celulas[i][j]==0 && cont[i][j]==3){
                    celulas[i][j]=1;
                    adj(i,j,1);
                }
                else if(celulas[i][j]==1 && (cont[i][j]<2 || cont[i][j] >3)){
                    celulas[i][j]=0;
                    adj(i,j,-1);
                }
            }
        }

        
    }

    for(int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cout<<celulas[i][j];
        }
        cout<<"\n";
    }

    return 0;
}

// 500000
