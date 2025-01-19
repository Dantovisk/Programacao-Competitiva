#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, tab;
    cin>>n>>tab;
    int locais[n+1];
    int recargas[n+1];
    int minimo[n+1];

    for(int i=1; i<=n; i++){
        cin>>locais[i];
    }
    for(int i=1; i<=n; i++){
        cin>>recargas[i];
    }
    locais[0]=0;
    recargas[0]=0;
    minimo[0]=0;
    int ant = 0;
    

    for(int i=1; i<=n; i++){
        if(tab>=(locais[i]-locais[i-1])){
            minimo[i]= minimo[i-1];
            tab-=(locais[i]-locais[i-1]);
        } else{
            int valor = -1;// melhor;
            for(int j=ant+1; j<i; j++){
                if(recargas[j]-(locais[i]-locais[j])>valor){
                    valor = recargas[j]-(locais[i]-locais[j]);
                    //melhor = j;
                    ant = j;
                }
            }
            if(valor==-1){
                minimo[n] =-1;
                break;
            }
            minimo[i-1]++;
            minimo[i]=minimo[i-1];
            tab=valor;
        }
    }
    cout<<minimo[n]<<endl;
    return 0;
}