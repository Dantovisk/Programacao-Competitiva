#include <bits/stdc++.h> //Day 3: Chessboard game, again! - Hackerrank
using namespace std;

map <pair<int,int>, int> vis;

int grundy(int i, int j){
    if (vis.find({i,j}) != vis.end()) return vis[{i, j}];

    if(i >= 15 || j >= 15 || i<0 || j <0) return -1;

    set <int> pos = {grundy(i+1, j-2), grundy(i-1, j-2), 
        grundy(i-2, j+1), grundy(i-2, j-1)};

    int id = 0;
    while(pos.count(id)) id++;

    return vis[{i, j}] = id;
}

int main(){
    int t; cin>>t;
    while(t--){
        int k; cin>>k;

        int nsum = 0;
        while(k--){
            int a, b;
            cin>>a>>b;

            nsum ^= grundy(a-1, b-1);
        }
        if(nsum == 0) cout<<"Second\n";
        else cout<<"First\n";
    }
}