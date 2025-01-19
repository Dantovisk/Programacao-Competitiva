#include <bits/stdc++.h>

using namespace std;

int main(){
    int a; cin>>a;

    for(int k =0; k<2; k++){
        if(a==0) cout<<"*\n";
        else{
            for(int i=0; i<5 && a>0; i++){
                cout<<"I";
                a--;
            }
            cout<<"\n";
        }
    }
    
    return 0;
}