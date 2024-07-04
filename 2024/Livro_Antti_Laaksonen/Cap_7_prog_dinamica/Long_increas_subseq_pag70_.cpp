// Problema para encontrar a maior subsequência crescente em um vetor
//nao ta funfando

#include <bits/stdc++.h>
#define INF 10000000
#define MAXN 10000

using namespace std;

int length[MAXN]; // guarda a maior subsequência até aquele valor
int valor[MAXN];

int main(){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) cin>>valor[i];
    
    length[0] = -INF;
    length[1] =1;

    for(int i=1; i<=n; i++){ //
        auto ptr = valor;
        while(ptr!=valor+n+1){
            ptr = lower_bound(valor+1, valor+n+1, valor[i]);
            *ptr = max(*ptr, length[i]+1);
        }
        
    }
    cout<<length[n];
}