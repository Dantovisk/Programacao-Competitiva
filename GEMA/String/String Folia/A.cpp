#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        bool reau = false;
        string s;
        int n;
        cin>>n>>s;

        for(int i = 0; i< n - 10; i++) 
            if(s[i] == '8') reau = true;

        cout<< (reau? "YES\n" : "NO\n");
    }
    return 0;
}