#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> v;

int32_t main(){
    int  n; cin>>n;

    for(int i =0; i<n; i++){
        int a; cin>>a;
        v.push_back(a);
    }
    //excluindo casos de tamanho 1;
    long long resp = -accumulate(v.begin(), v.end(), 0LL);

    
    for(int i =0; i<31; i++){
        int par = 1;
        int impar = 0;

        int bit = 0;
        for(auto x : v){
            bit ^= (1 & (x >> i)); 

            if(bit){
                resp +=  (par<<i) *1LL;
                impar ++;
            } else{
                resp += (impar<<i) *1LL;
                par ++;
            }
        }
    }

    cout<<resp<<"\n";

    return 0;
}