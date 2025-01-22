#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin>>n>>k;
    string a;
    cin>>a;
    int x;
    for(int i =0; i<n; i++){
        x = a[i] - 'a';
        x+= k;
        x%=26;
        a[i]='a'+x;
    }
    cout<<a;
    return 0;
}