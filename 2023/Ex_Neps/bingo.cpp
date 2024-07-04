#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, k, u; //n = numero de participantes, k = numero de casas, u = maior numero de uma cartela

    cin>> n >> k >> u;
    int leitura;
    
    vector <vector <int>> nums(u+1); //u números com x indices jogadores que precisam do numero

    int jogadores[n+1]; //quantidade de casas q já foi

    for(int i = 1; i<=n; i++){
        jogadores[i]=0;
    }

    for(int i = 1; i<=n; i++){
        for (int j=0; j<k; j++){
            cin>>leitura;
            nums[leitura].push_back(i);
        }
    }
    int sorteio;
    vector <int> respostas;
    for (int i=0; i<u; i++){
        cin>>sorteio;
        
        while(!nums[sorteio].empty()){
            auto ptr = nums[sorteio].end();
            ptr--;
            jogadores[*ptr]++;
            if(jogadores[*ptr] >= k){
                respostas.push_back(*ptr);
            }
            nums[sorteio].pop_back();
        }
        if(!respostas.empty()){
            while(!respostas.empty()){
                auto ptr = respostas.end();
                ptr--;
                cout<< *ptr <<" ";
                respostas.pop_back();
            }
            i=u;
        }    
    }
    return 0;
}