#include <bits/stdc++.h> // Atcoder - Hop Sogoroku
#define MAXN 1000010      
#define pii pair<int,int>
using namespace std;


const int inf = 1e9 + 3;
vector<pii> points[1010];

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    for(int i =1; i<=n; i++) {
        int a, b;
        cin>>a>>b;
        points[a/1000].push_back({b, i});
    }

    for(int i =0; i<=1000; i++){
        if(i%2) sort(points[i].begin(), points[i].end());
        else sort(points[i].rbegin(), points[i].rend());
    }
    for(int i =0; i<= 1000; i++){
        for(auto [u, id]: points[i])
            cout<<id<<" ";
    }

    return 0;
}