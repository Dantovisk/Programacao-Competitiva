#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 3e5+69;

int par[MAX];
int siz[MAX];
int prox[MAX];
int curr[MAX];
int v[MAX];
int id[MAX];
int where[MAX];

int n, q;

int find(int a){
    if(a != par[a]) return par[a] = find(par[a]);
    return a;
}



void merge(int a, int b){
    // cout<<"Antes do merge "<<a<<" "<<b<< "\n";
    // for(int i = 0; i<n; i++) cout<<where[i]<<" ";
    // cout<<"\n";
    // for(int i = 0; i<n; i++) cout<<id[i]<<" ";
    // cout<<"\n";
    
               

    a = find(a);
    b = find(b);

    if(a== b) return;
    // cout<<"Com o find: "<<a<<" "<<b<< "\n";

    if(siz[a] > siz[b]) {
        swap(curr[a], curr[b]);
        prox[a] = prox[b];
        swap(v[a], v[b]);
        swap(id[a], id[b]);
        where[id[a]] = a; 
        where[id[b]] = b; 
        

        swap(a, b);
    }


    par[a] = b;
    siz[b] += siz[a];

    // for(int i = 0; i<n; i++) cout<<where[i]<<" ";
    // cout<<"\n";
    // for(int i = 0; i<n; i++) cout<<id[i]<<" ";
    // cout<<"\n";
    
                
}



int main() {
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    
    cin>>n>>q;

    set<pii> vis;
    memset(prox, -1, sizeof(prox));


    for(int i =0; i<n; i++) {
        cin>>v[i];

        auto ptr = vis.begin();

        while(ptr != vis.end() && (*ptr).first < v[i]){
            prox[(*ptr).second] = i;
            vis.erase(ptr);
            ptr = vis.begin();
        }

        vis.insert({v[i], i});
    }

    for(int i =0; i<n; i++) {
        par[i] = i;
        siz[i] = 1;
        id[i] = i;
        where[i] = i;
    }

    for(int i = 0; i<q; i++){
        string t; cin>>t;
        int a, b;
        if(t == "+"){
            
            cin>>a>>b;
            a--;

            // cout<<"+: "<<a<<" "<<find(a)<<"\n";
            a = find(a);

            bool vai = true;
            while(b > 0){
                if(!vai) break;
                int cost = min(b, v[a] - curr[a]);
                

                curr[a] += cost;

                int u = prox[a];
                if(prox[a] != -1 && curr[a] == v[a]) {
                    merge(a, prox[a]);
                    a = find(a);
                }
                else vai = false;
                b -= cost;

            }

        }else{
            cin>>a;
            a--;
            cout<<curr[where[a]]<<"\n";
        }
        
    }

    // cout<<"final:\n";
    //             for(int i = 0; i<n; i++) cout<<where[i]<<" ";
    // cout<<"\n";
    // for(int i = 0; i<n; i++) cout<<id[i]<<" ";
    // cout<<"\n";
    
	
}


