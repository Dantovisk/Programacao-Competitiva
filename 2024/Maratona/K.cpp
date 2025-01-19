#include <bits/stdc++.h>
using namespace std;

short int v[2000010];

long long int fatorial(int n){
    long long int factorial;
    for(int i = 1; i <= n; ++i) {
        factorial *= i;
        factorial%=998244353;
    }
    return factorial;
}

int main(){
    int n, k;
    cin>>n>>k;

	v[1]=1;
    //vector <int> primos;
	for(int i=2;i<=2000000;i++){
		if(v[i]!=1){
			int pot=i;
			while(pot<=2000000){
				pot+=i;
				v[pot]=1;
			}
		}
	}

    int cont = 0;
    long long int q = 1;
    for(int i=2; i<=n; i++){
        if(v[i]>0) {
            cont++;
            q*=cont;
            q%=98244353;
        }
        //primos.push_back(v[i]);
    }

    long long int resp = 0;

    if(cont<k){
        cout<<0<<endl;
    }
    else{
        resp = fatorial(n-1);
        resp /=fatorial(n-1)*fatorial((n-1)-(k-1));
        resp %= 998244353;
        cout<<(resp/q)<<endl;
    }
}


