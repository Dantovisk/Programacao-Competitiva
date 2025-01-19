#include <bits/stdc++.h>

using namespace std;

int valores[1000010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin>>n;
    for(int i =0 ; i<n; i++){
        cin>> valores[i];
    }
    sort(valores, valores+n);

    //for(int i =0 ; i<n; i++) cout<<valores[i]<<" ";
    int minimo = 0, maximo =  n, media = (minimo + maximo)/2; //quant;
    

    while(minimo<=valores[n-minimo]){
            media = minimo + (maximo-minimo)/2;
            //printf("media: %d max: %d min %d", media, maximo, minimo);
            if(valores[n-media]>=media){
                minimo = media+1;
            } else{
                maximo = media;
            }
    }
    //printf("valor[%d] = %d max: %d min %d\n", minimo, valores[n-minimo], maximo, minimo);
    
    
    cout<<--minimo<<"\n";

    return 0;
}