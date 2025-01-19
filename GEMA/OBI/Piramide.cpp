#include <bits/stdc++.h>  //nao eh a maneira mais otimizada
using namespace std;      //mas eu achei mais rapido de codar

int main(){
    int v[6];
    for(int i=0; i<6; i++){
        cin>>v[i];
    }
    //sort(v, v+6);
    
    for(int i=0; i<720; i++){
        if(v[0]+ v[1] + v[2] == v[5] && v[5] == v[3] + v[4]){
            cout<<"S";
            return 0;
        }
        next_permutation(v, v+6);
    }
    
    cout<<"N";
    return 0;
}
