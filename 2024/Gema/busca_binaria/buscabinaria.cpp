#include <bits/stdc++.h>
using namespace std;

int a[100010];
int n;

int bb (int x){
    int k=0;
    if(a[k]==x) return k;
    for(int i = n/2; i>=1; i/=2){
        while(i+k<n && a[k+i]<x) k+=i;
    }
    if(a[k+1]==x) return k+1;
    return -1;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    int c;
    cin>>c;
    for(int i =0; i<n; i++){
        cin>>a[i];
    }
    int v;
    for(int i =0; i<c; i++){
        cin>>v;
        cout<<bb(v)<<"\n";
    }

    return 0;
}