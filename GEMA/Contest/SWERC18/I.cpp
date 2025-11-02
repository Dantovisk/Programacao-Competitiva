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
                {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int main() {
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int w, h;
    cin>>w>>h;
    vector <string> v(h);

    rep(i, 0, h) cin>>v[i];

    queue<pair<int,int>> q;

    q.push({0, 0});
    v[0][0] = '.';

    //limpa borda
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        for(auto d: dir2){
            int nx = x + d[0], ny = y + d[1];
            if(nx < 0 or ny < 0 or nx >= h or ny >= w) continue;
            if(v[nx][ny] == '#'){
                q.push({nx, ny});
                v[nx][ny] = '.';
            }
        }
    }

    rep(x, 0, h){
        rep(y, 0, w){
            if(v[x][y] == '.') continue;

            bool uai = true;
            for(auto d: dir2){
                int nx = x + d[0], ny = y + d[1];
                if(nx < 0 or ny < 0 or nx >= h or ny >= w) continue;
                if(v[nx][ny] == '#'){
                    uai = false;
                    break;
                }
            }
            if(uai)v[x][y] = '.';
        }
    }

    // rep(x, 0, h){
    //     cout<<v[x]<<"\n";
    // }
    int n = h, m = w;

    int a = 0, b = 0, c = 0;

    // PARTE BOA   
    for(int i = h-1; i >= 0; i--){
        for(int j = w-1; j >= 0; j--){
            if(v[i][j] != '#') continue;

            q.push({i, j});
            v[i][j] = 'K';

            int mini = i, minj = j;

            while(!q.empty()){
                auto [x, y] = q.front();
                q.pop();

                for(auto d: dir){
                    int nx = x + d[0], ny = y + d[1];
                    if(nx < 0 or ny < 0 or nx >= h or ny >= w) continue;
                    if(v[nx][ny] == '#'){
                        q.push({nx, ny});
                        v[nx][ny] = 'K';

                        mini = min(mini, nx);
                        minj = min(minj, ny);
                    }
                }
            }
            int moio = 0;

            for(int k = i; k >= mini; k--){
                if(v[k][j] != 'K'){
                    moio = 1;
                    c++; break;
                }
            }
            if(moio) continue;
            for(int k = j; k >= minj; k--){
                if(v[i][k] != 'K'){
                    moio = 1;
                    a++; break;
                }
            }
            if(moio) continue;
            b++;
        }
    }

    cout<<a<<" "<<b<<" "<<c<<"\n";
}