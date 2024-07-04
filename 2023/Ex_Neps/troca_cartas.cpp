#include <bits/stdc++.h>

using namespace std;

int main(){
    int A, B, lido;
	cin>>A>>B;
	set <int> Alice, Beatriz;
	for(int i = 0; i<A; i++){
		cin>>lido;
		Alice.insert(lido);
	}	
	for(int i = 0; i<B; i++){
		cin>>lido;
		Beatriz.insert(lido);
	}
	int countA =0, countB=0;
	while(!Alice.empty() && !Beatriz.empty()){
        auto ptrA = Alice.begin();
        auto ptrB = Beatriz.begin();
		if(*ptrA>*ptrB){
			Beatriz.erase(Beatriz.begin());
			countB++;
		} else if(*ptrA<*ptrB){
			Alice.erase(Alice.begin());
			countA++;
		} else{
			Alice.erase(Alice.begin());
			Beatriz.erase(Beatriz.begin());
		}	    
	}	
    countA += Alice.size();
    countB += Beatriz.size();
	if(countA<countB){
			cout<<countA;
		}	else cout<<countB;
    return 0;
}
