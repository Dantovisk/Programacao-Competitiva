#include <iostream>

using namespace std;

int main(){
    bool reau = false;
	int n;
    cin>>n;
	for(int i=2; i*i<=n && reau == false;i++){
		if(n % i == 0) reau = true;
	}	
	if (reau==true) cout<<"N";
	else cout<<"S";
    return 0;
}