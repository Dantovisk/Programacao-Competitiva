#include <bits/stdc++.h>

using namespace std;

const int INF = 1000010;
const int MAXN = 100010;

int v[MAXN], smpref[MAXN];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    smpref[0]=v[0];
    int ans = -INF;
    for(int i=1; i<n;i++){
        smpref[i]=max(v[i],smpref[i-1]+v[i]);
        if(smpref[i]>ans) ans=smpref[i]; 
    }
    cout<<ans;

    return 0;
}