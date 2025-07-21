#include <bits/stdc++.h>
#define MAXN 1010

using namespace std;

int n;

int v[MAXN];
int v2[MAXN];

int32_t main(){
    cin>>n;
    for(int i =0; i< n; i++){
        int m; cin>>m;

        for(int j = 0; j< m; j++){
            cin>>v[j];
            v2[j] = v[j];
        }

        sort(v, v+m);
        reverse(v, v+m);

        int res = 0;
        for(int j=0; j<m; j++){
            if(v[j] == v2[j]) res++;
        }

        cout<<res<<"\n";
    }

    
}