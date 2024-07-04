#include <iostream>
#include <map>

using namespace std;

int main(){
	// Declarando um Mapa <chave, elemento>
	map <char, int> mp;  
    mp.insert({'a', 1});
    mp.insert({'b', 2});
    mp.insert({'c', 3});

    if(mp.find('c') != mp.end()) //retorna um ponteiro da chave, se não, retorna o ponteiro do fim do map
		cout << "Existe" << endl;
	else
		cout << "Não existe" << endl;

    // Acessando um elemento diretamente usando o 
    // Operador []
    cout << mp['a'] << endl;
    // Criando um elemento usando o operador []
    mp['d'] = 4;
    cout << mp['d'] << endl;
    // Modificando usando o operador []
    mp['a'] = 5;
    cout << mp['a'] << endl;
	
    // Ponteiro para o final do map 
	auto ptr = mp.end();
    // Movendo para acessar o último elemento do map
    ptr--; 
    // Para acessar a chave usamos o first, e o elemento usamos o second
    cout << "Chave: '" << ptr->first << "' Elemento: " << ptr->second << endl;
    
    return 0;

}