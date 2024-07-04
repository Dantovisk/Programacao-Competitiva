#include <bits/stdc++.h>

using namespace std;

int main(){
    // Seu código vai aqui
	int a, b, c;
	int st, sm=100000;
	
	cin>>a>>b>>c;
	st = 4*a + 2*b;
	if(sm>st) sm=st;
	st = 4*c + 2*b;
	if(sm>st) sm=st;
	st = 2*a + 2*c;
	if(sm>st) sm=st;
	
	cout<<sm;
	
    return 0;
}