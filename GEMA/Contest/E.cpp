#include <bits/stdc++.h>

using namespace std;

unsigned long long int fact(int n, int m){
    unsigned long long int resp=1;
    int cont = 1;

    for(int i=m+1; i<=n; i++){
        resp*=i;
       while (resp%cont==0 &&cont<=n-m){
            resp/=cont;
            cont++;
        }
    }
    return resp;
}

int main() {
    int a, b;

    cin>>a>>b;

    unsigned long long int resp = fact(a, b);

    cout<<resp;
    return 0;
}