#include <bits/stdc++.h> //S-Nim - Kattis
using namespace std;

int s[110];
int vis[110];
int grundy[1000010];

int main(){
    int n; cin>>n;
    for(int i =0; i<n; i++){
        cin>>s[i];
    }

    sort(s, s+n);

    for(int i =0; i<=10002; i++){
        memset(vis, 0, sizeof(vis));

        for(int j=0; j<n; j++){
            if(i-s[j] < 0) break;
            vis[grundy[i-s[j]]] = 1;
        }
        for(int j=0; j<102 && vis[j] == 1; j++, grundy[i] = j);
    }

    int t; cin>>t;
    while(t--){
        int m; cin>>m;
        int nsum = 0;
        for(int i =0; i<m; i++){
            int a; cin>>a;
            nsum ^=grundy[a];
        }
        if(nsum) cout<<"W";
        else cout<<"L";
    }
    cout<<"\n";

    return 0;
}