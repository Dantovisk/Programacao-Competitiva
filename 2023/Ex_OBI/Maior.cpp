#include <bits/stdc++.h>

int n, m, s;

int main(){
    scanf("%d%d%d", &n, &m, &s);
    int numeroi;
    bool xisde=false;
    for (int i=m; i >n; i--){
        int soma = 0, x = i;
        while (x>0){
            soma += x%10;
            x/=10;
        }
        if (soma==s){
            numeroi=i;
            xisde = true;
            break;
        }
    }
    if (xisde==true){
        printf("\n%d", numeroi);
    } else{
        printf("-1");
    }
    return 0;
    
}