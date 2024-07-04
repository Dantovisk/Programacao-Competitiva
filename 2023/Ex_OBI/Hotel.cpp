#include <bits/stdc++.h>
using namespace std;

int d, a, n;

int main (){
    scanf("%d%d%d",&d,&a,&n);
    int diaria, valor;
    diaria = n;
    if(n>15)
        diaria= 15;

    valor = d+((diaria-1)*a);
    printf("\n %d", (31-n+1)*valor);

    return 0;
}