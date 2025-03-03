#include <bits/stdc++.h>

using namespace std;

vector <string> w;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;

    cin>>n;
    for(int i =0; i<n; i++){
        string a; cin>>a;
        w.push_back(a);
    }

    sort(w.begin(), w.end());

    cin>>q;
    for(int i =1; i<=q; i++){
        string a; cin>>a;

        auto ptr = lower_bound(w.begin(), w.end(), a);

        cout<<"Case #"<<i<<":\n";
        bool b = false;

        while(ptr != w.end() && (*ptr).compare(0, a.size(), a) == 0){
            cout<<*ptr<<"\n";
            b = true;
            ptr++;
        }
        if(!b) cout<<"No match.\n";
    }

    return 0;
}