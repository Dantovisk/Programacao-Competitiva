#include <bits/stdc++.h>

using namespace std;

set <string> w;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n;

    for(int i =0; i<n; i++){
        string a; cin>>a;
        w.insert(a);
    }

    cin>>q;
    for(int i =1; i<=q; i++){
        string a; cin>>a;

        cout<<"Case #"<<i<<":\n";

        bool b = false;

        auto ptr = w.upper_bound(a);

        
        while(ptr != w.end() && (*ptr).compare(0, a.size(), a) == 0){
            cout<<*ptr<<"\n";
            b = true;
            ptr++;
        }

        if(!b) cout<<"No match.\n";
    }

    return 0;
}