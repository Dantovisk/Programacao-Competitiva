#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
	cin>>n;
	int numeros[n];
	for(int i =0;i<n;i++){
		cin>>numeros[i];
	}	
	sort(numeros, numeros + n);
    
    for(int i =0;i<n;i++){
		cout<<numeros[i]<<" ";
	}	
    return 0;
}