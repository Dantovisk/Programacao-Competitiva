#include <iostream>

using namespace std;

int main(){
    int N, a, soma=0, resp=1;
	cin>>N;
	
	for (int i = 0; i<N; i++){
		cin>>a;
		soma+=a;
		if(soma<1000000){
			resp++;
		}	
	}	
	
	cout<<resp;
    return 0;
}
