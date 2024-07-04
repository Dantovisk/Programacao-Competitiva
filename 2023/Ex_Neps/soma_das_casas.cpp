#include <bits/stdc++.h>

using namespace std;
int main(){
    int n, k;
    cin>> n;
    vector <int> coisas(n);

    for(int i=0; i<n; i++){
        cin>> coisas[i];
    }

    cin>>k;
    int l=0, r=n-1;
    int respa =-1, respb=-1;
    while(l<r){
        if(coisas[l]+coisas[r]==k){
            respa = coisas[l];
            respb = coisas[r];
            l=r;
        }
        else if(coisas[l]+coisas[r]<k){
            l++;
        }else{
            r--;
        }
    }
    cout<<respa<<" "<<respb;
    return 0;
}