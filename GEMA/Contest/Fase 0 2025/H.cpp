#include <bits/stdc++.h>

using namespace std;
#define int long long

long long maxPal(vector <int> xd, int n, int k){
    vector <int> v = xd;
    long long resp = 0;
    if(v[k] == 0) return 0; 

    for(int i = 0; i< n/2; i++){
        if(i == k || n-(1+i) == k){
            v[n-1-i] = v[i] = 0;
        }
        if(i > k){
            v[n-1-i] = 1;
            v[i] = 1;
        }
        else if(n-(i+1) > k){
            if(v[i] != v[n-1-i]){
                v[n-1-i] = v[i];
            }
        }
        
        else{
            if(v[i] != v[n-1-i]){
                v[i] = 0;
                v[n-1-i] = 0;
            }
        }
        
    }
    if(n%2){
        if((n/2)> k) v[n/2] = 1;
        else if(n/2 == k) v[n/2] = 0;
    } 

    for(int i = 0; i< n; i++){
        resp +=(v[i]<<(n-i-1));
    }
    // cout<<k<<": ";
    // for(int i =0; i<n; i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<"\n"<<resp<<"\n";
    return resp;
}


int32_t main(){
    long long n, resp1 = 0; cin>>n;
    long long resp = 0;
    vector <int> v;

    int sz = 63;
    while(!((n>>(sz-1)) & 1)) sz --;

    for(int i =sz-1; i>=0; i--){
        v.push_back((n >> i) & 1);
    }
    // cout<<"v: ";

    // for(int i = 0; i<sz; i++){
    //     cout<< v[i]<<" ";
    // }
    // cout<<"\n";

    for(int i =1; i<sz; i++){
        resp =  max(resp, maxPal(v, sz, i));
    }
    
    //v[0] = MAIS SIGNIFICATIVO

    for(int i =0; i< sz/2; i++){
        if(v[i] != v[sz-1-i]){
            v[i] = 0;
            v[sz-1-i] = 0;
        }
    }

    long long resp2 =0;

    for(int i =0; i<sz-1; i++){
        resp2+= (1<<i);
    }

    for(int i = 0; i< sz; i++){
        resp1 +=(v[i]<<(sz-1-i));
    }


    

    cout<< max({resp1, resp2, resp})<<"\n";
    return 0;
}