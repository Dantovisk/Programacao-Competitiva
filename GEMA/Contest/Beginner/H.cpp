#include <bits/stdc++.h>
#define ll long long

using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    priority_queue <int, vector<int>, greater<int>> pq;
    set <int> vis;


    int n; cin>>n;

    for(int i=0; i<n; i++){
        int a; cin>>a;
        vis.insert(a);
        pq.push(a);
    }

    int mex = 0;
    while(vis.find(mex) != vis.end()) mex++;

    cout<<mex<<" ";

    for(int i=1; i<n; i++){
        int a = pq.top();
        pq.pop();

        if(a != pq.top()){
            mex = min(mex, a);
        }

        cout<<mex<<" ";
    }
    
    
    
}