#include <bits/stdc++.h>   //programa que, dado uma lista de números, responde a soma de N
using namespace std;  //intervalos dessa lista

const int MAXN = 1000010;

int main()
{
	int n, q;         //n é o tamanho da lista, q é a quantidade de consultas de intervalo
	int v[MAXN], psa[MAXN]; // psa[i] = v[0] + v[1] + ... + v[i], ou seja, psa[i] = psa[i - 1] + v[i]
    cin >> n >> q;

	for (int i = 0; i < n; i++) //lendo os n elementos da lista
		cin >> v[i];

	psa[0] = v[0];  //primeiro item da soma é igual ao primeiro item da lista

	for (int i = 1; i < n; i++)  //calcula todos os prefixos até psa[n-1]
		psa[i] = psa[i - 1] + v[i];

	for (int i = 0; i < q; i++)  //leitura das consultas
	{
		int L, R;
		cin >> L >> R;

        int sum;

    	if (L == 0) 
		    sum = psa[R]; // Versão mais fácil
	    else 
		    sum = psa[R] - psa[L - 1]; //cálculo da soma do intervalo


		cout << "Soma do intervalo: " << sum << endl;

	}

    return 0;
}