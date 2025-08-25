#include <bits/stdc++.h> // Atcoder - Strange Nim
using namespace std;

int grundy(int n, int k){
    if(n%k == 0) return n/k;
    if(n < k) return 0;
    return grundy(n - n/k - 1, k);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    int xorval = 0;

    int q; cin>>q;
    while(q--){
        int n, k;
        cin>>n>>k;

        xorval ^=grundy(n, k);
    }

    if(xorval == 0) cout<<"Aoki\n";
    else cout<<"Takahashi\n";

    return 0;
}