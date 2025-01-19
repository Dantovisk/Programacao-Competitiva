#include <bits/stdc++.h>

using namespace std;
int val[10010];
int erro[10010];
int temp[10010];

bool ehPossivel(int media, int n){
    for(int i=0; i<n; i++){
        temp[i] = abs(val[i]- media);
    }
    sort(temp, temp+n);
    for(int i=0; i<n; i++){
        if (temp[i]!=erro[i]) return false;
    }
    return true;
}

long long int qualErro(int media, int n){
    long long int somaErro = 0;
    for(int i=0; i<n; i++){
        somaErro+=abs(val[i]- media);
    }
    return somaErro;
}

bool ehCrescente(int media, int n){
    if(qualErro(media, n)>=qualErro(media+1, n)) return false;
    else return true;
}



int main(){
    int n;
    long long int somaErro=0;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>val[i];
    }
    for(int i=0; i<n; i++){
        cin>>erro[i];
        somaErro+=erro[i];
    }

    sort(erro, erro+n);

    int maximo=1000000000, minimo =1, media;

    while(minimo<maximo){
        media = minimo + (maximo-minimo)/2;
        if(ehCrescente(media, n)){
            maximo = media;
            
        } else{
            if(somaErro>qualErro(media, n)){
                minimo = media+1;
            }else{
                maximo = media;
            }
        }

    }
    //cout<<" Resposta inferior "<<minimo<<"\n";
    if(ehPossivel(minimo, n)){
        cout<<minimo<<"\n";
    }
    
    maximo=1000000000; minimo =1;
    while(minimo<maximo){
        media = minimo + (maximo-minimo)/2;
        if(ehCrescente(media, n)){
            if(somaErro>qualErro(media, n)){
                minimo = media+1;
            }else{
                maximo = media;
            }
        } else{
            minimo = media+1;
        }

    }
    if(ehPossivel(minimo, n)){
        cout<<minimo<<"\n";
    }
    

    return 0;
}