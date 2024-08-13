#include <bits/stdc++.h>

using namespace std;

int main() {
    string lida;

    cin>>lida;
    string resp ="";
    for(unsigned int i=0; i< lida.length(); i++){
        if(lida[i]>='A' && lida[i]<='Z') resp+="c";
        else if(lida[i]=='-') resp+="-";
        else if(lida[i]>='0' && lida[i]<='9') resp+="n";
        else resp += "o";
    }

    if(resp== "ccc-nnnn") cout<<1;
    else if(resp=="cccncnn") cout<<2;
    else cout<<0;
    
    return 0;
}