#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
	cin>>n;
	
	int leitura[n];
	vector <int> menores;

	for (int i = 0; i<n; i++){
		cin>>leitura[i];
		if(leitura[i]==0) menores.push_back(i);
	}

	while(!menores.empty()){
		for (int i = 0; i<n; i++){
			if(leitura[i]==-1) leitura[i]=9;
			if(leitura[i]!=0 && leitura[i]>abs(menores.back()-i)) {
				leitura[i]=abs(menores.back()-i);
			}
		}
		for (int i = n-1; i>=0; i--){
			if(leitura[i]!=0 && leitura[i]>abs(menores.back()-i)) {
				leitura[i]=abs(menores.back()-i);
			}
		}	
		menores.pop_back();
	}
	for (int i = 0; i<n; i++){
		cout<<leitura[i]<<" ";
	}
    return 0;
}