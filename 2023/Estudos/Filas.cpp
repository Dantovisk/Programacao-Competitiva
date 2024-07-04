#include <bits/stdc++.h>

using namespace std;

int main(){
	// Declarando uma fila de inteiros
	queue <int> q;
	// Inserindo elementos na fila
	q.push(1);
	q.push(2);
    q.push(4);
    q.push(7);
	// O front retorna o primeiro elemento (o mais antigo) da fila, nesse caso 1
	cout << q.front() << endl;
	// Removendo o elemento da frente da lista
	q.pop();
	cout << q.front() << endl;
    // Aí vira o 2

    cout << q.size() << endl; //tamanho da fila

	return 0;

}