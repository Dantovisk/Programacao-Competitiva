#include <bits/stdc++.h>
#define ll long long


using namespace std;

int n; string a; 

ll solve(char xd){
    ll cont= 0;
    int l = 0, r = n-1;
    int lx = 0, rx = n-1; // o proximo a colocar
    // cout<<xd<<"\n";

    while(r>= l){
        while(a[l] != xd && r>= l) l++;
        while(a[r] != xd && r>= l) r--;


        
        if(abs(lx-l) < abs(rx - r)){
            cont+= abs(lx-l);
            l++;
            lx++;
        }else{
            cont+= abs(rx-r);
            r--;
            rx--;
        }
        
    }
    return cont;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        cin>>n>>a;

        cout<<min(solve('a'), solve('b'))<<"\n";
    }



    return 0;
}