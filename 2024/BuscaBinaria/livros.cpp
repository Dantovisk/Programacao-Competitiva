#include <bits/stdc++.h>

using namespace std;

long long int  soma[510];
int livros[510], indices[510];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;

    while(n--){
        int l, e;
        cin>>l>>e;
        
        if(l>0){
            cin>>livros[0];
            soma[0] = livros[0];
        }
        
        int minimo =0, maximo =0, media;

        for(int i=1; i<l; i++){         //leitura dos livros e dos prefixos
            cin>>livros[i];
            soma[i]= soma[i-1] + livros[i];
        }
        minimo = *max_element(livros, livros + l-1);
        maximo = soma[l-1];
        
        //agora checaremos se eh possivel com os numeros dados
        
        while(minimo<maximo){
            auto ptr = soma;
            media = minimo + (maximo-minimo)/2;
            int antecessor = 0;
            
            for(int i=0; i<e; i++){
                ptr = upper_bound(ptr, soma+l, antecessor+media);
                ptr--;
                antecessor = *ptr;
            }
            
            if((ptr-soma) >=l-1) maximo = media;
            else minimo = media+1;
        }
        //cout<<"\nmedia: "<<media<<" minimo: "<<minimo<<"\n";
        media = minimo;
        //  achamos a media, hora de organizar o vetor

        // If there is more than one solution, print the one that
        // minimizes the work assigned to the first scriber, then 
        // to the second scriber etc. But each scriber must be assigned at least one book
        
        int acumul = 0;
        int j = e-2;
        for(int i=l-1; i>=0; i--){
            acumul+= livros[i];
            //cout<<"acumul: "<<acumul<<" livros: "<<livros[i]<<"\n";
            if(acumul>media){
                indices[j] = i+1;
                j--;
                acumul = livros[i];
            } else if(i<=j){
                indices[j]= i+1;
                j--;
                //acumul = livros[i];
            }
            
        }
        
        int antecessor = 0;
        for(int i=0; i<e-1; i++){
            for(int j=antecessor; j<indices[i]; j++){
                cout<<livros[j]<<" ";
            }
            cout<<"/ ";
            antecessor = indices[i];
        }
        for(int j=antecessor; j<=l-1; j++ ){
                cout<<livros[j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
