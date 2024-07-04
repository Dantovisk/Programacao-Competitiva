#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, c, drone = 3;
	
	
	cin>>a>>b>>c;
	
	if(a+b<c){ 
		drone -=2;
		}
	else if (a<b){
		drone--;
        if (b<c) drone--;
	} 
    else if (b<c) drone--;
	
	cout<<drone;
    return 0;
}
