#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
    ll n1, n2, n12;
    cin>>n1>>n2>>n12;

    cout<<((n1 + 1LL) * (n2 + 1LL) - (n12 + 1LL))/(n12 + 1LL)<<"\n";

    return 0;
}