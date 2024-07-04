#include <bits/stdc++.h>

using namespace std;

int main(){
	list <int> l = {1, 2, 3};
	auto ptr = l.begin(); //auto pela sintaxe simplificada
	// Vamos mover o ponteiro até a segunda posição
	int pos = 1;
	while(pos != 2){
		pos++;
		ptr++;
	}
	// Inserindo o elemento na posição desejada 
	l.insert(ptr, 10);
	// Note que o 10 agora está na segunda posição
	for(auto i : l) // lê o alcance da lista
		cout << i << " ";
	cout << endl;

    pos=1;
    ptr = l.begin();
    while(pos != 2){
		pos++;
		ptr++; //nao dá pra simplesmente somar prt = ptr + 2; ou algo do tipo 
	}

    l.erase(ptr); //função para apagar o 10
	for(auto i : l)
		cout << i << " ";
	cout << endl;


	return 0;
}