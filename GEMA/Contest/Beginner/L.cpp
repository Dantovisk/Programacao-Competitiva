#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, m; 
vector<string> v;
bool a(int i, int j){
    if(i < 0 || j < 0 || i >=n || j >= n) return false;
    return (v[i][j] == 'A');
}

bool b(int i, int j){
    if(i < 0 || j < 0 || i >=n || j >= n) return false;
    return (v[i][j] == 'B');
}
bool pt(int i, int j){
    if(i < 0 || j < 0 || i >=n || j >= n) return false;
    return (v[i][j] == '.');
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;

    int tempo[1010][1010];
    
    for(int i = 0; i<n; i++){
        string a; cin>>a;
        v.push_back(a);
    }

    queue <pair<int,int>> q;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(v[i][j] ==  'A') {
                q.push({i, j});
                v[i][j] = '.';
            }
        }
    }

    bool resolveu = false;

    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();

        

        if(a(i-1, j) && pt(i+1, j)) q.push({i+1, j});
        if(a(i+1, j) && pt(i-1, j)) q.push({i-1, j});
        if(a(i, j-1) && pt(i, j+1)) q.push({i, j+1});
        if(a(i, j+1) && pt(i, j-1)) q.push({i, j-1});

        if(a(i-1, j) && b(i+1, j)) resolveu = true;
        if(a(i+1, j) && b(i-1, j)) resolveu = true;
        if(a(i, j-1) && b(i, j+1)) resolveu = true;
        if(a(i, j+1) && b(i, j-1)) resolveu = true;

        if(v[i][j] == '.'){
            v[i][j] = 'A';

            if(a(i-1, j)) q.push({i-1, j});
        }

    }
    
}