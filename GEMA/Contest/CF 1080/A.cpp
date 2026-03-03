#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define ff first
#define ss second
#define pb push_back
int n; 
int v[10];

bool solve(int i, int prod){
    if(i == n){
        return prod == 67;
    }
    return (solve(i+1, prod * v[i]) or solve(i+1, prod));
}

void solvee(){
    cin>>n;

    rep(i, 0, n){
        cin>>v[i];
    }

    if(solve(0, 1)) cout<<"YES\n";
    else cout<<"NO\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solvee();
}