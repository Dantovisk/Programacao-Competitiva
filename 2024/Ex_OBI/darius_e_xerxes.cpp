#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, pdario = 0 ;
    int dar, xer;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>dar>>xer;
        if ( (xer == (dar+1)%5) || (xer == (dar+2)%5) ) pdario++;
    }
    if(pdario>(n-1)/2){
        cout<<"dario"<<endl;
    }
    else{
        cout<<"xerxes"<<endl;
    }


    return 0;
}