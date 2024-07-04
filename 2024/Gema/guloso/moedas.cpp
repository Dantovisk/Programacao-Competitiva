#include <bits/stdc++.h> 
using namespace std;
 
int moedas[6]={1,5,10,25,50,100};
 
int main(){
    int soma, resp=0, ind = 5;
    cin>>soma;
    while(soma>0){
        resp += soma/moedas[ind];
        soma %= moedas[ind];
        ind --;
    }
    
    cout<<resp;
    return 0;
}