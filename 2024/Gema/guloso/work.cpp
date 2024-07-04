#include <bits/stdc++.h>  
using namespace std;

int main(){
    int n;
    cin>>n;

    vector <int> resposta;

    int a, cont=0, negativos=0;
    for(int i=0; i<n; i++){
        cin>>a;
        if (a<0) negativos++;
        if(negativos >=3) {
            resposta.push_back(cont);
            cont =0;
            negativos=1;
        }
        cont++; 
    }
    if(cont>0) resposta.push_back(cont);
    cout<<resposta.size()<<endl;
    for(int x: resposta) cout<<x<<" ";
    return 0;
}