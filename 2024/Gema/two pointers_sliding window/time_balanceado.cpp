#include <bits/stdc++.h>
using namespace std;

int v[200010];

int main(){
    int n;
    cin>>n;
    for(int i =0; i<n; i++) cin>>v[i];
    sort(v, v+n);

    int maxSoma = 1;
    int i=0, j=1;

    while(j<n){
        if(v[j]-v[i]<=5){
            maxSoma = max(maxSoma, (j-i)+1);
            j++;
        }
        else i++;
    }
    
    cout<<maxSoma;

    return 0;
}