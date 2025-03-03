#include <bits/stdc++.h>

using namespace std;

vector<string> v;

int main(){
    string a;
    cin>>a;
    int n; cin>>n;

    for(int i =0; i<n; i++){
        string b; cin>>b;
        v.push_back(b);
    }

    sort(v.begin(), v.end());

    auto ptr = lower_bound(v.begin(), v.end(), a);

    if(ptr == v.end() || (*ptr).compare(0, a.size(), a) != 0) cout<<a;
    else cout<< *ptr;
    return 0;
}