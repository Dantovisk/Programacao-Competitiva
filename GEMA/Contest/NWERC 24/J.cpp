#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int de(pii a, pii b){
    int k1 = a.first - b.first;
    int k2 = a.second - b.second;
    return (int)(sqrt(k1*k1 + k2*k2)+0.0001);
}


int dist[510][510];
int resp[510];
int sz[510];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;  
    
    vector <pii> coord;

    //sz, ord
    vector<pii> ord;
    
    for(int i =0; i<n; i++){
        int a, b, c;
        cin>>a>>b>>c;

        coord.push_back({a, b});
        sz[i] = c;
        ord.push_back({c, i});
    }

    sort(ord.begin(), ord.end());


    for(int i =0; i<n; i++){
        for(int j = i+1; j<n; j++){
            int u = de(coord[i], coord[j]);

            dist[i][j] = u;
            dist[j][i] = u;
        }
    }

    for(int i =0; i< ord.size(); i++){
        auto [mx, id] = ord[i];
        int mini = mx;

        // cout<<"mini "<<id<<": "<<mini<<"\n";
    
        for(int j = i+1; j<ord.size(); j++){
            mini = min(mini, dist[id][ord[j].second]);
        }
    
        resp[id] = mini;
    }

    for(int i =0; i<n; i++)cout<<resp[i]<<"\n";

}