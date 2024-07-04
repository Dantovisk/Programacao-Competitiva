#include <bits/stdc++.h>

using namespace std;

int main(){
    int c,n;
	cin >> c >> n;
	
	map <int,int> mp;
	map <int,int> resp;
	
	int app, vers;
	
	for (int i = 0; i<c; i++){
		cin >> app >> vers;
		mp[app] = vers;
	}	
	
	for (int i = 0; i<n; i++){
		cin >> app >> vers;
		if(mp[app] < vers)
			resp[app] = vers;
		else if(mp.find(app) == mp.end()){
            resp[app] = vers;
        }
	}	
	auto ptr = resp.begin();
	
	for (unsigned int i=0; i<resp.size(); i++){
		
		cout<< ptr->first<< " "<< ptr->second<< "\n";
		ptr++;
	}	

    return 0;
}