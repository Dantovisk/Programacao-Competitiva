// Problema introdutório para a programação dinâmica
// Dado um conjunto de moedas, qual é o número mínimo de moedas
// Necessárias para atingir alguma soma?

#include <bits/stdc++.h>
#define INF 10000000
#define MAXN 10000

using namespace std;

int valor[MAXN]; // guarda o número minimo de moedas para um valor dado
bool visto[MAXN]; // guarda os valores que já foram visitados
set <int> moedas;
int n;

int solve(int a){                   //recursão para achar o numero minimo para cada valor
    if (a < 0) return INF;          //não dá para atingir um valor negativo com moedas
    if (a == 0) return 0;           // se o valor é 0, serão 0 moedas
    if (visto[a]) return valor[a];  //se já leu, não precisa ler de novo
    int menor = INF;                //o menor numero de moedas
    for(auto m: moedas){
        menor = min(menor, (solve((a-m))+1));
    }
    valor[a] = menor;
    visto[a] = true;
    return menor;
}

int main(){
    int b, soma;
    cin>>n;
    for (int i=0; i<n; i++){  //leitura dos valores de moeda disponíveis
        cin>>b;
        moedas.insert(b);
    }
    cin>>soma;
    cout<<solve(soma)<<endl;;

}