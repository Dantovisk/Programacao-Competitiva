#include <bits/stdc++.h> // Ainda incompleto
using namespace std;     // Precisa fazer o backtracking

#define vi vector<int>
#define ll long long

int v[21], n;

vi fac(int u){
    vi res;
    res.push_back(1);
    for(int i =2; i<=u; i++){
        while(u%i == 0){
            res.push_back(i);
            u/=i;
        }
    }
    return res;
}

bool verifica(int id, int start){
    if(v[id] % start) return false;

    int u = v[id]/start;
    if(u > 100) return false;

    //vai de 1 até n-1
    vector<bool> vis(n);
    vector<int> res;

    res.push_back(start);
    res.push_back(u);

    vis[id] = 1;
    int cont = 1;
    
    for(int i = 1; i<n-1; i++){
        for(int j = 1; j<n; j++){
            if(vis[j]) continue;
            if(v[j] % u == 0 && v[j]/u <= 100){
                u = v[j] / u;
                vis[j] = 1;
                cont++;
                res.push_back(u);
                break;
            }
        }
        if(cont < i+1) return false;
    }

    cout<<"Yes\n";
    for(auto x: res) cout<<x<<" ";
    return true;
}

int main(){
    cin>>n;

    random_device rd;
    mt19937 g(rd());

    for(int i =1; i<n; i++) cin>>v[i];

    int quant= 40;
    while(quant--){
        for(int i =1; i<n; i++){
            for (int j = 1; j<= min(v[i], 100); j++){
                if(verifica(i, j)) return 0;
            }
        }

        shuffle(v + 1, v + n, g);
    }
    

    cout<<"No\n";
    return 0;
}