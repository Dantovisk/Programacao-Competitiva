#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int n, k, l, r; 
        cin>>n>>k>>l>>r;

        vector <int> v(n);

        for(int i =0; i<n; i++){
            cin>>v[i];
        }

        map <int, int> vis;
        set <int> fds;

        ll resp = 0;

        int esq = 0;
        int esqfds = 0;
        for(int i =0; i<n; i++){
            vis[v[i]] ++;

            while(i-esq + 1 > r || vis.size() > k){
                if(esq >=esqfds){
                    if(vis[v[esq]] == 1) vis.erase(v[esq]);
                    else {
                        vis[v[esq]]--;
                    }
                }
                esq++;
            
                esqfds = max(esq, esqfds);
            }

            if(vis.size() < k || i-esq+1 <l) continue;

            while(vis[v[esqfds]] > 1 && i-esqfds+1 > l) {
                if(vis[v[esqfds]] == 1) vis.erase(v[esqfds]);
                else {
                    vis[v[esqfds]]--;
                }

                esqfds++;
            }

            // cout<<i<<" "<<esqfds<<" "<<esq<<"\n";
            resp += esqfds-esq+1;
        }

        cout<<resp<<"\n";
    }



    return 0;
}