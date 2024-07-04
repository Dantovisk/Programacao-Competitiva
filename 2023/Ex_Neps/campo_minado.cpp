#include <iostream>

using namespace std;

int main(){
    int anterior=0, n, aux;
	cin>>n;
	int resp[n];
	for (int i =0; i<n; i++){
		cin>>aux;
		resp[i]= aux+anterior;
		if(i!=0) resp[i-1] +=aux;
		anterior = aux;
	}	
	
	for (int i =0; i<n; i++){
		cout<<resp[i]<<endl;
	}
    return 0;
}
