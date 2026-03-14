#include <bits/stdc++.h> //Stair Game- CSES

using namespace std;
int v[200010];

int main(){
    int t;
    cin>>t;

    while(t--){
        int n; cin>>n;
        int x1 = 0;

        for(int i =0; i<n; i++){
            cin>>v[i];
        }

        for(int i =1; i<n; i+=2) x1 ^=v[i];

        if(x1 == 0) cout<<"second\n";
        else cout<<"first\n";

    }


    return 0;
}