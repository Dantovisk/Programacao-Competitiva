#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int x, y;
char direcao;

//INCOMPLETO - BUSCA EM PROFUNDIDADE OU BUSCA EM LARGURA

 main(){
    cin >> n >> m >> k;
    bool matriz [n][m] ;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) matriz[i][j] = true; //bota tudo falso na matriz

    for(int i = 0; i <k; i++){  
        cin >> x >> y >> direcao;  //pega as coordenadas das cameras e a direcao delas
        if(direcao == 'S'){
            for (int j = (y-1); j<m; j++){
                matriz [(x-1)][j] = false;
            }
        }
        if(direcao == 'N'){
            for (int j = (y-1); j>=0; j--){
                matriz [(x-1)][j] = false;
            }
        }
        if(direcao == 'L'){
            for (int j = (x-1); j<n; j++){
                matriz [j][(y-1)] = false;
            }
        }
        if(direcao == 'O'){
            for (int j = (y-1); j<m; j--){
                matriz [j][(y-1)] = false;
            }
        }
        
    }

    for(int i = 0; i <m; i++){ //printa a matriz
        for(int j = 0; j <n; j++){
            cout<<matriz[j][i]; //1 é onde a câmera não vê, 0 é onde vê
    }
    cout<<"\n";
    }

    if(matriz[0][0]==false){
        cout<<"N";
    } else {


    }

 }