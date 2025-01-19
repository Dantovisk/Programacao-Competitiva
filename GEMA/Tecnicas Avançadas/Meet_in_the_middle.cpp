#include <bits/stdc++.h>
#define ll long long int

using namespace std;

vector <ll> s1, s2;
int v1[22];
int v2[22];

void subset(int v[], vector <ll>& sum, int n){
    for(int i=0; i<(1<<n); i++){
        ll newsum = 0;
        for(int j=0; j<n; j++){
            if((1<<j) & i) newsum += v[j];
        }
        sum.push_back(newsum);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, sum;
    cin>>n>>sum;

    int mid = n/2;

    for(int i=0; i<mid; i++){
        cin>>v1[i];
    }

    subset(v1, s1, mid);

    for(int i=mid; i<n; i++){
        cin>>v2[i-mid];
    }

    subset(v2, s2, n - mid);

    ll resp = 0;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
   
    for(auto x: s1){
        auto p1 = lower_bound(s2.begin(), s2.end(), sum-x);
        auto p2 = upper_bound(s2.begin(), s2.end(), sum-x);
        resp += p2-p1;
    }

    cout<<resp<<"\n";

    return 0;
}