#include <bits/stdc++.h>

using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    int l, e=0;

    while(n--){    
        cin>>l;
        if(l>=62) e++;
    }
    cout<<"e: "<<e;
    return 0;
}
