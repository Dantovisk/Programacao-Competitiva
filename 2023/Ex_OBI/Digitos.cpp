#include <bits/stdc++.h>

using namespace std;

// CORRETO

int n, menor, proximo, ndigsprox, ndigsesse, esse, add;
bool mogas;
int lista[1000];

main(){
    cin>>n;
    int dig[n];
    for (int i=0; i<n; i++){ //pega os digitos a serem analizados
        cin>>dig[i];
    }
    
    for(int digprim = 1; digprim*2 <= n; digprim++){ // aumenta os digitos do 1º num
        add=1;
        for (int i=0; i<(n-ndigsprox);i+=ndigsesse){
            esse=0;
            for(int j=0;j<(digprim+add-1);j++){
                esse = (esse*10)+dig[(i+j)];
            }
            //cout<<" esse:"<<esse;
            lista[i]=esse;
            proximo = lista[i]+1;
            ndigsesse= int(log10(esse) + 1);
            ndigsprox= int(log10(proximo) + 1); //pega o n de digs do prox
            //cout<<" ndedig:"<<ndigsprox;
            add=ndigsprox;
            proximo=0;
            for(int j=0;j<ndigsprox;j++){
                proximo = proximo*10+dig[i+j+ndigsesse];
            }
            //cout<<" proximo:"<<proximo;
            if(proximo==esse+1){
                mogas=true;
            }else{
                mogas = false;
                i=n;
            }
        }
        if(mogas==true){
            menor=0;
            for(int j=0;j<digprim;j++){
                menor = menor*10+dig[j];
            }
            digprim=n;
        }
    }
    cout<<menor;
}

