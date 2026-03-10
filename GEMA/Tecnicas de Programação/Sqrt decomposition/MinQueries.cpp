#include <bits/stdc++.h> // CSES - Dynamic Range Minimum Queries
//#define int long long
#define MAXN 200010
 
using namespace std;
 
int v[MAXN];
int buckets[1000];
 
const int inf = 1e9 + 3;
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, q;
    cin>>n>>q;
 
    // Tamanho de cada bucket
    int sz = 1;
    while(sz * sz < n) sz++;
 
    memset(buckets, -1, sizeof(buckets));
    for(int i =0; i < 999; i++){
        buckets[i] = inf;
    }
 
    for(int i =0; i<n; i++){
        cin>>v[i];
        buckets[i/sz] = min(buckets[i/sz], v[i]);
    }
 
    while(q--){
        int a, b, c;
        cin>>a>>b>>c;
        if(a==1){
            b--; //tornaremos 0-indexado
            int id = b/sz;
            v[b] = c;
            buckets[id] = inf;
            for(int i =0; i<sz; i++){
                buckets[id] = min(buckets[id], v[i + id*sz]);
            }
        } else{
            int resp = inf;
            b--; //tornaremos 0-indexado
            c--;
            
            while(b <= c){
                if(b % sz == 0 && b + sz <= c){
                    resp = min(resp, buckets[b/sz]);
                    b += sz;
                }
                else{
                    resp = min(resp, v[b]);
                    b++;
                }
            }
 
            cout<<resp<<"\n";
 
        }
    }
 
    return 0;
}