#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin>>n;

    vector <string> ordem(n);
    map <string, int> idades;
    map <int,string> prioridades;

    for (int i =0; i<n; i++){
        cin>>ordem[i];
    }
    string lida;
    for (int i =0; i<n; i++){
        cin>>lida;
        idades[lida] = i;
        prioridades[i] = lida;
    }

    for (int i =0; i<n-1; i++){
        auto ptr = prioridades.begin();
        cout<<ptr ->second<<" ";
        int remover = idades[ordem[i]];
        prioridades.erase(remover);
    }
    if(n>0){
        auto ptr = prioridades.begin();
        cout<<ptr ->second<<"\n";
    }
    return 0;
}