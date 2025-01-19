#include <bits/stdc++.h> //OBI 2021 - Terceira fase
#define MAXN 20002
using namespace std;

string v[MAXN];
map <string, int> mp;

int main(){
    int n; cin>>n;

    for(int k =0; k<n; k++){
        cin>>v[k];  
        set <string> subword;
        for(int i=1; i<= v[k].length(); i++){
            for(int j=0; j <= v[k].length() - i; j++){
                subword.insert(v[k].substr(j, i));
            }
        }

        for(auto x:subword){
            mp[x]++;
        }
    }

    long long resp = 0;

    for(auto x: v){
        mp[x];
        resp += (mp[x]>0? (mp[x]-1): 0);
    }
    cout<<resp;
    
    return 0;
}