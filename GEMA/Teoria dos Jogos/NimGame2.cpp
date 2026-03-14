#include <bits/stdc++.h> //Nim Game II - CSES

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n; cin>>n;
        int at = 0;

        for(int i =0; i<n; i++){
            int a; cin>>a;
            at ^= (a%4);
        }

        if(at == 0) cout<<"second\n";
        else cout<<"first\n";

    }


    return 0;
}