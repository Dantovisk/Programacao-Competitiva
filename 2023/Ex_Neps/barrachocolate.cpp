#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, x1, y1, x2, y2;
	cin>>N>>x1>>y1>>x2>>y2;
	
	if(x1<=(N/2) && x2>(N/2)){
		cout<<"S";
	}else if(x2<=(N/2) && x1>(N/2)){
		cout<<"S";
	}else if(y1<=(N/2) && y2>(N/2)){
		cout<<"S";	
	}else if(y2<=(N/2) && y1>(N/2)){
		cout<<"S";
	} else cout<<"N";	
    return 0;
}
