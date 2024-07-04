#include <iostream>
using namespace std;

const int MAXN = 1000010;      //tamanho máximo de elementos

int parent[MAXN], size[MAXN];

int find(int value)
{
	if (parent[value] == value)                     //se o parente do valor for ele mesmo, retorne
		return value;               
	return parent[value] = find(parent[value]);     //se não for, procure o parente do parente
                                                    //até achar a raiz    
}
void merge(int i, int j)
{
	i = find(i); j = find(j);       //procura os parentes dos valores 'i' e 'j'

	if (i == j)                     //se forem iguais, retorne, pois já estão unidos
		return;

	if (size[i] >= size[j])         //se o tamanho de i for maior ou igual ao de j, será o novo parente
	{
		parent[j] = i;              
		size[i] += size[j];         // e o tamanho de i é somado com j
	}
	else
	{
		parent[i] = j;
		size[j] += size[i];
	}
}

int main()
{
	int n, q;
	cin >> n >> q;  // numero de elementos e numero de operações

	for (int i = 0; i < n; i++)   //o tamanho de todos os elementos é igual a 1
	{                             //os parentes de todos os elementos são eles mesmos inicialmente
		size[i] = 1;
		parent[i] = i;
	}

	for (int i = 0; i < q; i++)   
	{
		int type, a, b;             //pede o tipo de operaçao
		cin >> type >> a >> b;      //e os indices

		if (type == 1)
			merge(a, b);
		else
		{
			if (find(a) == find(b))                 //se os parentes forem iguais
				cout << "Same set" << endl;         //set é igual
			else
				cout << "Different sets" << endl;   //se não, sets diferentes
		}
	}
}