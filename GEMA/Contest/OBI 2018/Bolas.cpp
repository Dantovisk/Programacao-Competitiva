#include <bits/stdc++.h>

using namespace std;

int v[8];
int used[10];

int main(){
    
    for(int i = 0; i<8; i++){
        cin>>v[i];
        used[v[i]]++;
    }

    sort(used, used + 10);

    if(used[9] > 4) cout<<"N\n";
    else cout<<"S\n";

    return 0;
}