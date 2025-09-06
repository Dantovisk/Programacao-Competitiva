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

bool verifica(int st){
    cout<<"verificando "<<st<<"\n";
    int k = st;
    for(int i = 1; i<n; i++){
        if(v[i] % k) return false;
        k = v[i]/k;
    }
    return true;
}

int main(){
    cin>>n;

    for(int i =1; i<n; i++) cin>>v[i];

    int k = 1;
    vi f = fac(v[1]);

    for(auto x: f){
        k*= x;
        if(verifica(k)){
            cout<<"Yes\n";
            int z = k;
            cout<<z<<" ";
            for(int i = 1; i<n; i++){
                z = v[i]/k;
                cout<<z<<" ";
            }
            return 0;
        }
    }

    cout<<"No\n";
    return 0;
}