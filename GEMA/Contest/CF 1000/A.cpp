#include <bits/stdc++.h>
#define MAXN 200010
#define ll long long int 

using namespace std;

int main(){
    int t; cin>>t;

    while(t--){
        int a, b;
        cin>>a>>b;

        if(a==1 && b==1) cout<<1<<"\n";
        else cout<<b-a<<"\n";
    }


    return 0;
}