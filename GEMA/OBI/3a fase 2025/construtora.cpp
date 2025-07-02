#include <bits/stdc++.h>

using namespace std;

int v[110];

int main(){
    int n; cin>>n;
    int mx = 1;

    for(int i =0; i<n; i++){
        cin>>v[i];
        mx = max(mx, v[i]);
    }
    int resp = 0;

    for(int i =2; i<=mx; i++){
        for(int j =0; j<n; j++){
            if(v[j] < i){
                resp++;
                while(j < n && v[j] < i){
                    v[j] ++;
                    j++;
                }
            }
        }
    }
    cout<<resp<<"\n";


    return 0;
}