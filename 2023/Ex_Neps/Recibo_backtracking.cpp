#include <bits/stdc++.h>

using namespace std;
int n;

int dp[110][22][110]; //primeiro a soma desejada, dps o numero de produtos e por fim o menor valor
int r, k; //r é a soma desejada e k é o total de produtos

//funcao do tipo int pq vai retornar uma int
int solve(int valor, int quant, int menor)  //os numeros serao ordenados de forma crescente
{                                            //assim nao repetirá ordens diferentes dos mesmos numeros
	
    if(dp[valor][quant][menor] != -1) return dp[valor][quant][menor]; //se o numero lido nao tiver -1
    //é pq já passamos por ele, então retorna o numero atual

    //caso coloquem 0, é necessário essas verificações pra nao dar algum resultado indesejado
    if(valor==0){
        if(quant==0){
            return dp[valor][quant][menor] = 1;
        } else{
            menor=0;
            return dp[valor][quant][menor] = 0;
        }
    } else{
        if(quant==0){
            menor=0;
            return dp[valor][quant][menor] = 0;
        }
    }
    //agora ocorre a operação de fato

    dp[valor][quant][menor] = 0; //primeiro zera o o numero neste endereço

    for(int i=1; i<min(valor+1, menor); i++){  //repete o processo até que utilize a quant de numeros dada
        dp[valor][quant][menor] += solve(valor-i, quant-1, i); //ou até que a soma chegue no valor dado
    } 
    //quando termina de testar todos os conjuntos com um determinado numero
    //aumenta esse numero até irem todos

    return dp[valor][quant][menor]; //entao retorna o numero de somas possiveis

}

int main()
{
	cin>>r>>k;
    memset(dp,-1,sizeof(dp)); //deixa a matriz dp com -1 em tudo
    cout<<solve(r,k,r+1)<<endl; 
}