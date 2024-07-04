#include <iostream>
using namespace std;

const int MAXN = 1000010;

int main()
{
	int n, k;
	int v[MAXN];

	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> v[i];

	int i = 0, j = n - 1; // Os dois ponteiros

	while (i <= j) 
	{
		if (v[i] + v[j] == k) // Primeiro caso
		{
			cout << "Resposta: ("  << i << "," << j << ")" << endl;
			return 0;
		}
		else if (v[i] + v[j] < k) // Segundo caso
			i++;
		else // Terceiro caso
			j--;
	}

	cout << "Não há nenhum par com a soma desejada" << endl;
}

//1° caso -> a+b = c -> neste caso, encontramos a nossa resposta
//2° caso -> a+b < c -> a soma é pequena, por isso moveremos i para a próxima posição na matriz
//3° caso -> a+b > c -> a soma é muito grande, por isso vamos diminuir j em 1 para diminuir a soma