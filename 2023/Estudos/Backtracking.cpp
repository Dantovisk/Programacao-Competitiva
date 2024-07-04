#include <iostream>  //algoritmo de força bruta que encontra todas as soluções
using namespace std; //ou a melhor solução de um problema   

const int MAXN = 20; // Maior quantidade de elementos que esperamos ler

int n;               //complexidade 2^n

void backtracking(int i, bool choosed[])
{
	if (i == n) // Nós já escolhemos para todos os números se eles estarão na resposta ou não
	{
		for (int j = 0; j < n; j++) // Imprimindo a resposta atual
			if (choosed[j]) cout << j << " ";

		cout << endl;
		return;
	}

	choosed[i] = false;
	backtracking(i + 1, choosed); // Não escolher i na resposta atual

	choosed[i] = true; 
	backtracking(i + 1, choosed); // Escolher i na resposta atual
}

int main()
{
	bool choosed[MAXN];

	// Ler o tamanho do conjunto
	cin >> n;
	cout << "Todos os subconjuntos: " << endl;

	backtracking(0, choosed);
}
