#include <bits/stdc++.h>

using namespace std;

int main(){
	int N, D; 
	cin >> N >> D; //numero de pedaços, comprimento total


	vector<int> A(N); //lê o tamanho dos pedaços do sanduiche
	for (int i = 0; i < N; i++)
		cin >> A[i];

	int ans1 = 0; //soma sem as pontas 
	int l = 0, r = 0;
	int soma = 0;

	while (l < N) {
		while (r < N && soma + A[r] <= D) { //vai adicionando os elementos à direita
			soma += A[r];                   //até que seja maior q N
			r += 1;
		}

		if (soma == D)                      // se for igual ao tamanho desejado, ans++
			ans1++;

		soma -= A[l];                       //aí remove o item mais à esquerda da soma
		l += 1;                             //e desloca l uma casa à direita
	}

	vector<int> Pref(N), Suf(N);

	int acc = 0;
	for (int i = 0; i < N; i++) {           //cria um vetor de prefixos
		acc += A[i];                        //onde Pref={A0, A0+A1, A0+A1+A2 ...}
		Pref[i] = acc; 
	}

	acc = 0;                                
	for (int i = N - 1; i >= 0; i--) {      //cria um vetor de sufixos
		acc += A[i];                        //que tem os mesmos elementos de Pref[]
		Suf[i] = acc;                       //só que invertidos
	}

	map<int, int> SufCount;
	
	int ans2 = 0;                           //respostas com soma das pontas apenas
	for (int i = N - 2; i >= 0; i--) {      //começa na penultima posiçao, e diminui
		SufCount[Suf[i + 1]] += 1;          
		if (Pref[i] > D) continue;
		ans2 += SufCount[D - Pref[i]];
	}

	cout << ans1 + ans2 << endl;
	
    return 0;
}
