#include <bits/stdc++.h> //Stair Game- CSES
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int gr[2010];

int main(){
    int t;
    cin>>t;

    rep(i, 3, 2010){
        unordered_set<int> xors;
        for(int j = 1; j< (i+1)/2; j++){
            xors.insert(gr[j]^gr[i-j]);
        }
        int mex = 0;
        while(xors.count(mex)) mex++;

        gr[i] = mex;
    }

    while(t--){
        int n; cin>>n;
        int x1;
        if(n > 2000) x1 = 1;
        else x1 = gr[n];

        if(x1 == 0) cout<<"second\n";
        else cout<<"first\n";

    }


    return 0;
}