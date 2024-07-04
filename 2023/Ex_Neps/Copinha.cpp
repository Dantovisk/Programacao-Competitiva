#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    vector <char> vencedores[5];
    for(char i='A'; i<='P'; i++){
        vencedores[0].push_back(i);
    }

    for(int i = 0 ; i < 4 ; i++){ //muda a chave
        for(int k=0; k<(8/pow(2,i)); k++){
            cin >> m >> n;
            if(m>n){
                vencedores[i+1].push_back(vencedores[i][k*2]);
            } else{
                vencedores[i+1].push_back(vencedores[i][(k*2)+1]);
            }
        }
    }
    
    cout<<vencedores[4][0];
    
}