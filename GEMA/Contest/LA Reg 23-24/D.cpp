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
string key;

bool valid(string& g, string w){
    vi cont (26, 0);

    rep(i, 0, 5){
        if(g[i] != '*')cont[key[i]-'a']++;
    }

    rep(i, 0, 5){
        if(g[i] == '*'){
            if(key[i] != w[i]) return false;
        }
        if(g[i] == '!'){
            if(key[i] == w[i]) return false;
            cont[w[i] - 'a'] --;
            if(cont[w[i] - 'a'] < 0) return false; 
        }
    }
    rep(i, 0, 5){
        if(g[i] == 'X'){
            if(key[i] == w[i]) return false;
            if(cont[w[i] - 'a'] > 0) return false; 
        }
    }

    return true;
}

void solve(){
    int n; cin>>n;

    vector<string> act;
    rep(i,0, n){
        string a; cin>>a;

        if(i==0) key = a;

        act.pb(a);
    }

    int k; cin>>k;
    rep(i, 0, k){
        string guess;
        cin>>guess;
        int ct  = 0;
        auto ptr = act.begin();
        while(ptr != act.end()){
            if(!valid(guess, (*ptr))){
                ptr++;
                continue;
            }

            ct++;
            ptr++;
        }

        cout<<ct<<"\n";
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    // cin>>t;

    while(t--)solve();
}