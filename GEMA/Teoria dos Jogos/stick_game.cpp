#include <bits/stdc++.h> // Atcoder - Strange Nim
using namespace std;

int dp[1000010];

int main(){
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    
    int n, m;
    cin>>n>>m;

    vector <int> c;
    for(int i =0; i<m; i++){
        int a; cin>>a;
        c.push_back(a);
    }
    sort(c.begin(), c.end());

    dp[0] = 0;
    for(int i =1; i<=n; i++){
        for(auto k : c){
            if(i - k < 0) {
                break;
            }
            if(dp[i-k] == 0) dp[i] = 1;
        }
    }

    for(int i =1; i<=n; i++){
        cout<<(dp[i] == 1? 'W' : 'L');
    }
    cout<<"\n";
}