#include <bits/stdc++.h> //dado uma soma, encontre a posição de dois valores que formem a soma
using namespace std;
 
map <int,int> mp;
 
int main(){
    int n, s;
    cin>>n>>s;
    int a;
    bool reau = false;
    for(int i =0; i<n; i++){
        cin>>a;
        if(mp.find(a)!=mp.end()){
            reau = true;
            cout<<mp[a]<<" "<<i+1<<"\n";
            break;
        } 
        mp[(s-a)] = i+1;
    }
    if(!reau) cout<<"IMPOSSIBLE\n";
 
    return 0;
}