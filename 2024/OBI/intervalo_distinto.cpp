#include <bits/stdc++.h>

using namespace std;
int a;
int v[100010];

int mp[100010];

int main() {
    cin>>a;
    for(int i=0; i<a; i++){
        cin>>v[i];
    }

    int l=0, r=0;
    int cont =0, maxcont=1;
    while(r<a){
        mp[v[r]] ++;
        while(mp[v[r]]>1){
            mp[v[l]]--;
            l++;
            cont--;
        }
        cont++;
        maxcont = max(cont, maxcont);
        r++;
    }
    cout<<maxcont;
    return 0;
}