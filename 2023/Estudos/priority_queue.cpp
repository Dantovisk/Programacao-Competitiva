#include <bits/stdc++.h>

using namespace std;

/*
são três parametros da priority queue:
1- Tipo de dado que será armazenado.
2- O container onde serão alocados os elementos
(quando não especificado std::vector será usado).
3- A função de comparação 
(por padrão a estrutura mantém no topo o maior elemento).
*/

int main(){
	// Declarando uma Fila de Prioridade
	priority_queue <int, vector <int>> pq;
	// Inserindo elementos na Fila 
	pq.push(1);
	pq.push(4);
	pq.push(2);
	// O elemento no topo
	cout << pq.top() << endl;
	// Removendo o elemento do topo, nesse caso, o maior
	pq.pop();

	// O elemento no topo
	cout << pq.top() << endl;
	return 0; 
}

