#include <bits/stdc++.h>

using namespace std;

int main(){
    int c, moedas=0;
	cin>>c;
	int S[6] ={1, 5, 10, 25, 50 ,100};
	for(int i = 5; i>=0; i--){
		while(c>=S[i]){
			moedas++;
			c-=S[i];
		}
	}	
	cout<<moedas;
    return 0;
}
