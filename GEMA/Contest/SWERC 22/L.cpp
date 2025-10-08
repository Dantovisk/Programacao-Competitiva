#include <bits/stdc++.h>

using namespace std;
#define vi vector<int>
#define pb push_back
#define all(a) (a).begin(),(a).end()
typedef long long ll;
#define pii pair<int,int>

const int MAX = 5e3+69;

//grau, nivel, dir;

array<array<array<int, 4>, 22>, 360> adj;

int vis[360][22];

vector <pair<int, int>> dir = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

void solve(){
    for (auto &mat : adj)
        for (auto &linha : mat)
            linha.fill(1);

    memset(vis, 0, sizeof(vis));

    int n; cin>>n;

    for(int i =0; i<n; i++){
        string a;
        cin>>a;

        int raio, s, e, ang;

        if(a=="C"){
            cin>>raio>>s>>e;

            for(int j = s; j!=e; j = (j+1+360)%360){
                // cout<<j<<" ";
                adj[j][raio][2] = 0;
                adj[j][raio-1][3] = 0;
            }
            // cout<<"\n";

        }else{
            cin>>s>>e>>ang;

            int l = (ang-1+360)%360;
            for(int j = s; j < e; j++){
                // cout<<j<<" ";
                adj[ang][j][0] = 0;
                adj[l][j][1] = 0;
            }
            // cout<<"\n";
        }
    }

    stack <pii> st;

    st.push({0, 0});


    while(!st.empty()){
        auto[x, y] = st.top();
        st.pop();

        vis[x][y] = 1;
        // cout<<x<<" "<<y<<"\n";

        if(y == 21){
            cout<<"YES\n";
            return;
        }

        for(int i =0; i<4; i++){
            if(adj[x][y][i] == 0) continue;
            int nx = (dir[i].first + x+ 360) % 360;
            int ny = dir[i].second + y;

            if(ny < 0) continue;

            if(vis[nx][ny]) continue;

            st.push({nx, ny});
        }

    }
    cout<<"NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--) solve();
}