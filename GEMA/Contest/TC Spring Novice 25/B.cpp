#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int dir2[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0},
                  {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n; cin>>n;
    rep(i, 0, n){
        string k1, r, k2;
        vector<vi> v(8, vi(8, 0));

        cin>>k1>>r>>k2;

        string a = k1;
        v[a[0]-'a'][a[1]-'1'] = 1;

        a = r;
        v[a[0]-'a'][a[1]-'1'] = 2;

        a = k2;
        v[a[0]-'a'][a[1]-'1'] = 3;

        for(auto d: dir){
            a = r;
            int x =a[0]-'a';
            int y =a[1]-'1';

            while(x < 8 && x>= 0 && y < 8 && y >= 0){
                if(v[x][y] == 1 || v[x][y] == 3) break;
                
                v[x][y] = 2;
                x += d[0];
                y += d[1];
            }
        }

        for(auto d: dir2){
            a = k1;
            int x =a[0]-'a';
            int y =a[1]-'1';

            x += d[0];
            y += d[1];

            if(!(x < 8 && x>= 0 && y < 8 && y >= 0)) continue;

            v[x][y] = 1;
        }

        bool foi = false;

        for(auto d: dir2){
            a = k2;
            int x =a[0]-'a';
            int y =a[1]-'1';

            x += d[0];
            y += d[1];

            if(!(x < 8 && x>= 0 && y < 8 && y >= 0)) continue;

            if(v[x][y] == 2){
                foi = true;
                break;
            }
        }

        // rep(i, 0, 8){
        //     rep(j, 0,8) cout<<v[j][i]<<" ";
        //     cout<<"\n";
        // }
        // cout<<"\n";

        if(foi) cout<<"YES\n";
        else cout<<"NO\n";

    }
}