#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()

int main(){
    vector<ll> coord = {-123, 583, 235, 329, 10000}; 
    
    sort(coord.begin(), coord.end());
    coord.erase(unique(all(coord)),  coord.end());
    auto id = [&](ll val){
        return lower_bound(all(coord), val) - coord.begin();
    };

    cout<<id(-123)<<"\n";
    cout<<id(235)<<"\n";
    cout<<id(329)<<"\n";
    
    return 0;
}