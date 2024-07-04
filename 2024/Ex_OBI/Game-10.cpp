#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, c, resposta;
    cin>>a>>b>>c;
    if(c>b){
        resposta = a-c+b;
    } else{
        resposta = b-c;
    }
    cout<<resposta;
    return 0;
}