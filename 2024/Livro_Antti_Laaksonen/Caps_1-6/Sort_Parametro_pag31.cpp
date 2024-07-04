//É possível dar uma função de comparação ao método sort
//No programa está implementado a seguinte ordenação:
//1 - Ordem crescente de tamanho
//2 - Ordem alfabética (padrão do método sort)

#include <bits/stdc++.h>

using namespace std;

bool comp(string a, string b) {    // método personalizado de comparação de strings
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

int main(){
    vector <string> v(4);
    v[0] = "macau";
    v[1] = "lua";
    v[2] = "penedos";
    v[3] = "amongus";

    sort(v.begin(), v.end(), comp);

    for(unsigned int i = 0; i<v.size(); i++){
        cout<<v[i]<<endl;
    }

}