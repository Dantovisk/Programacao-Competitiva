//a ideia é ter um vetor de chegada e um de saida, e ver a maxima distancia de indices
// dado um certo tempo de entrada
#include <bits/stdc++.h>  
using namespace std;

int entrada[200010], saida[200010];

int main(){
    int n;
    cin>>n;
    int a, b;

    for(int i=0; i<n; i++){
        cin>>a>>b;
        entrada[i] = a;
        saida[i] = b;
    }
    sort(entrada, entrada +n);
    sort(saida, saida +n);
    
    int p=0, maxi = 0;
    for(int i=0; i<n; i++){
        while(saida[p]<entrada[i]) p++;
        maxi = max(maxi, i-p+1);
    }
    cout<<maxi;
    return 0;
}