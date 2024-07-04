#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, a;
    int d1=0, d2=0;

	bool result = true;

	cin>> N;
	int somaX[N], somaY[N];
	
	for(int i= 0; i<N; i++){  //leitura da matriz
		for(int j= 0; j<N; j++){
			somaX[j] = 0;
			somaY[i] = 0;
		}
	}

	for(int i= 0; i<N; i++){  //leitura da matriz
		for(int j= 0; j<N; j++){
			cin>>a;
			somaX[j] += a;
			somaY[i] += a;

			if(i==j){
				d1+=a;
			} 
			if(i == N-1-j){
				d2+=a;
			}

		}
	}	
	
	if(d1 != d2){
		result = false;
	}

	for(int i= 0; i<N; i++){  
		if (d1 != somaX[i]) result = false;
		if (d1 != somaY[i]) result = false;

	}


	if(result){
		cout<<d1;
	} else{
		cout<<-1;
	}

    return 0;
}