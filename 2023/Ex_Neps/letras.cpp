#include <bits/stdc++.h> 
using namespace std;

int lis(string &v){
	vector<char> pilha;
	
	for(int i=0; i<v.size(); i++){
		vector<char>::iterator it = upper_bound(pilha.begin(), pilha.end(), v[i]);		
		if(it==pilha.end()) pilha.push_back(v[i]);
		else *it = v[i];
	}
	
	return pilha.size();
}

int main(){
    
	string s;
	cin>>s;
	cout<<lis(s)<<endl;
    return 0;
}