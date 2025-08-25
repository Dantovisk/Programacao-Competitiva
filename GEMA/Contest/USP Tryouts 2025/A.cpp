#include <bits/stdc++.h>
#define MAXN 100010
#define int long long

using namespace std;

int v[2*MAXN];

int tin[MAXN], tout[MAXN];


int bestq = 0, bestc = 1e9+7;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;

    vector<pair<int,int>> resp(2*n+1);

    resp[0] = {0,0};

    for(int i =1; i<=2*n; i++){
        cin>>v[i];
        if(tin[v[i]] == 0) tin[v[i]]  = i;
        else tout[v[i]] = i;
    }

    for(int i =1; i<= 2*n; i++){
        int u = v[i];

        if(tout[u] == i){
            auto [a, b] = make_pair(resp[tin[u]].first + 1, resp[tin[u]].second + tout[u] - tin[u]);
            auto u = resp[i-1];
            if(u.first > a){
                resp[i] = resp[i-1];
            }
            else if(u.first == a && u.second < b){
                resp[i] = resp[i-1];
            }
            else{
                resp[i] = {a, b};
            }
        }
        else{
            resp[i] = resp[i-1];
        }
    }

    // for(auto u: resp){
    //     cout<<u.first<<" "<<u.second<<" |\n";
    // }


    int a = 0, b =1e11+69;

    for(auto u: resp){
        if(u.first > a){
            a = u.first;
            b = u.second;
        }
        else if(u.first == a && u.second < b){
            a = u.first;
            b = u.second;
        }
    }


    cout<<a<<" "<<b<<"\n";
    
}