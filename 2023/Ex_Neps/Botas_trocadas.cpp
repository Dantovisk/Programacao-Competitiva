#include <bits/stdc++.h>

using namespace std;

// 30 D 30 D 30E 30E  vai ler um só, melhor seria usar uma matriz 32 por 2

int main(){
    int n; //numero de botas
	int num, resposta=0;
	char lado;
	cin>>n;
	map <int,char> mp; //le o numero e o pe da bota
	for(int i=0; i<n; i++){
		cin>>num>>lado;
		if(mp.find(num) != mp.end()){
			if(lado != mp[num]){
				resposta++;
				mp.erase(num);
			}	
		} else{
			mp[num]=lado;	
		}	
	}	
	cout<<resposta;
    return 0;
}