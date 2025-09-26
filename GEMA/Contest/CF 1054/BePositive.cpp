#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;

        int zeros = 0;
        int menos = 0;
        for(int i =0; i<n; i++){
            int a; cin>>a;
            if(a==-1) menos++;
            else if(a==0) zeros ++;
        }

        cout<<zeros + (menos%2)*2<<"\n";
    }



    return 0;
}