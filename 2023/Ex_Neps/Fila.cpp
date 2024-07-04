#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, leitura, m;
    cin>>n;
	
	int fila[n];
    set <int> sairam;
	
	for(int i =0; i<n; i++){
		cin>> leitura;
		fila[i]=leitura;
	}
	
	cin>>m;
	
	for(int i =0; i<m; i++){
		cin>> leitura;
		sairam.insert(leitura);
	}

    for(int i =0; i<n; i++){
        if(sairam.find(fila[i]) ==sairam.end()){
            cout<<fila[i]<<" ";
        }
    }    
	
    return 0;
}