#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned int n, m;
    cin>>n>>m;

    int cont =0;
    unsigned int a =1;
    a<<=31;
    for(int i = 0; i<32; i++){
        if (n/a != m/a) cont +=a;
        n%=a;
        m%=a;
        a>>=1;
    }
    cout<<cont;
    
    return 0;
}