#include <bits/stdc++.h>

using namespace std;

int main(){
    int C, total =0, leitura;
	set <int> tacos;
    cin>>C;
	for (int i = 0; i<C; i++){
		cin>>leitura;
		if(tacos.find(leitura) != tacos.end()){
			tacos.erase(tacos.find(leitura));
		}	else {
			tacos.insert(leitura);
			total+=2;
		}	
	}
	
	cout<< total;

    return 0;
}
