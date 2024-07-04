#include <iostream> 
// Biblioteca com a implementação da pilha
#include <stack>

using namespace std;

int main(){
	// Declarando uma pilha de inteiros
	stack <int> q;	
	// Inserindo elementos na pilha
	q.push(1);
	q.push(2);

	//Removendo o elemento do topo da pilha
	// O novo elemento do topo será o 1
	q.pop();

	cout << q.top() << endl;

    q.push(3);
    q.push(4);
    // Retorna o topo da pilha, no caso, será 2
	cout << q.top() << endl;

	return 0;
}