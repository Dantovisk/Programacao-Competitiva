#include <bits/stdc++.h>
#define MAXN 100010
#define int long long
#define all(x) (x).begin(), (x).end()
using namespace std;


const int M = 1e9;

int32_t main(){
    int n; cin>>n;

    
    vector<int> v(n);
    for(int i =0; i<n; i++){
        cin>>v[i];
    }

    vector<int> vec;
    sort(all(v));
    v.erase(unique(all(v)), v.end());

    for(int i = 1;  i<n; i++){
        v[i] -= v[0];
        if(v[i] > 0) vec.push_back(v[i]);
    }

    // for(auto x: vec) cout<<x<<" ";
    // cout<<"\n";

    if(vec.size() == 0){
        cout<<"1 "<< M-1<<"\n";
        return 0;
    }

    int gcdd = v[2];

    for(auto x: vec){
        gcdd = __gcd(gcdd, x);
    }

    vector<int> factors;
    for(int i =1; i*i<=gcdd; i++){
        if(i*i == gcdd) factors.push_back(i);
        else if(gcdd%i == 0){
            factors.push_back(i);
            factors.push_back(n/i);
        }
    }

    //cout<<"GCD: "<<gcdd<<"\n";

    if(gcdd != 1) cout<<"1 "<< factors.size() - 1<<"\n";
    else cout<<"2 1\n";

}