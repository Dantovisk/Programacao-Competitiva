#include <bits/stdc++.h> 
using namespace std;

int n;

vector<int> LIS(vector<int> &v){ //longest increasing subsequence
    vector <int> lis;            //o método vai retornar um vetor com a distância (+1) do proximo
    vector <int> ans;            //maior numero e o inicio da lis (que ta vazia no começo)

	for(int i = 0; i<n; i++){
        auto ptr = lower_bound(lis.begin(),lis.end(), v[i]);  //auto ptr = lower_bound
        long int distance {ptr - lis.begin()};
        if(ptr == lis.end()){       //se o ponteiro chegar no fim da lis (nao achar algo maior), adiciona
            lis.push_back(v[i]);    //no fim da lis o elemento atual do vetor na
        }else{                      //se achar, muda no indice do ptr o valor 
            *ptr = v[i];            //pro elemento do vetor atual
        }
        ans.push_back(distance + 1);
	}
    //o resultado é um vetor com o tamanho do LIS terminado em cada posicao
    return ans;
}

int solve (vector<int> &v){                         //funcao que vai calcular o LIS, o LDS, e compará-los
    vector <int> lisNormal{LIS(v)};                 //testando por todos os valores de i
    reverse(v.begin(),v.end());
    vector <int> lisInvers{LIS(v)};                 //se lis1[i] for igual a lis2[i], e seus tamanhos /2 tiverem modulo 0
    reverse(lisInvers.begin(),lisInvers.end());     //só ver se é a maior resposta até agr

    int respostaxd = 0;

    for(int i = 0; i < n; i++){
        if(lisNormal[i]==lisInvers[i] && (lisNormal[i]+lisInvers[i]) % 2==0){
            respostaxd= max(respostaxd, lisNormal[i]+lisInvers[i]-1);
        }
    }

    return respostaxd;
}

int main(){
    cin>>n;
    vector <int> v(n);

    for (int i =0; i<n; i++){
        cin>>v[i];
    }
    
    cout << solve(v);

    return 0;
    
}