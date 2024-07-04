#include <iostream>

using namespace std;

int main(){
	int n, ant1=0, ant2=0, leit=0;
	int resp = 0;
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>leit;
		if(leit==0 && ant2==0 && ant1==1){
			resp++;	
		}	
		ant1 = ant2;
		ant2= leit;
	}	
	
	cout<<resp;
    return 0;
}