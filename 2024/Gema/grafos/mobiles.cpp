#include <bits/stdc++.h>

using namespace std;
vector <vector<int>> adj(100010);
int n;
bool resposta = true;

int pesar(int a){
    set <int> pesos;
    int soma = 1;
    for(int x: adj[a]){
        int k = pesar(x);
        soma += k;
        pesos.insert(k);
    }

    if(pesos.size()>1) resposta = false;

    return soma;
}

int main(){
    cin>>n;
    int a, b;
    for(int i =0; i<n; i++){
        cin>>a>>b;
        adj[b].push_back(a);
    }

    pesar(0);

    if(resposta) cout<<"bem";
    else cout<<"mal";
    return 0;
}

