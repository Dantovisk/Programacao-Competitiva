#include <bits/stdc++.h>
#define MAXN 100010
#define int long long 
using namespace std;

int b, m;

int exp(int e){
    if(e== 0) return 1LL;
    if(e == 1) return (b%m);
    int k = (exp(e/2))%m;

    if(e%2) return (((k*k)%m)*b)%m;
    return (k*k)%m;
}

int32_t main(){
    int e;
    cin>>b>>e>>m;

    cout<<exp(e)<<"\n";

}