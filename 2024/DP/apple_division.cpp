#include <bits/stdc++.h>
//exercicio de backtracking (pois n<=20)

using namespace std;

int v [21];
int n;

long long int minDif = 1e11 + 69;

void bt(int i, long long int a){
    if(i==n){
        if(abs(minDif)> abs(a)){
            minDif = a;
        }
    }
    else{
        bt(i+1, a + v[i]);
        bt(i+1, a - v[i]);
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    bt(0, 0);

    cout<<abs(minDif);
    return 0;
}