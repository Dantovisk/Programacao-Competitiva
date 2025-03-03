#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        bool r = true;
        string a, b; cin>>a>>b;
        int n = a.length();
        int m = b.length();
        int k = 0;

        for(int i = 0; i < n; i++){
            if(k >= m) {
                r = false;
                break;
            }

            while(i+1 < n && a[i] == a[i+1]){
                if(a[i] != b[k]){
                    r = false;
                    break;
                }
                k++;
                i++;
            }
            while(k+1 < m && b[k] == b[k+1]) k++;

            if(a[i] != b[k]){
                r= false;
                break;
            }
            k++;
        }

        if(r && k == m) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}