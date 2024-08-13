#include <bits/stdc++.h>

using namespace std;
bool visto[1000];
vector <vector<int>> vertices(1000);
multiset <int> conjuntos;
int n;

int tamconjunto(int a){
    int resp=1;
    for(int x: vertices[a]){
        if(!visto[x]){
            visto[x]= true;
            resp+= tamconjunto(x);
        }
    }
    return resp;
}

int main(){
    int m, a, b;
    cin>>n;
    for(int i =0; i<1000; i++){
        visto[i] = false;
    }
    for(int i = 0; i<=n; i++){
        cin>>m;
        for(int j = 0; j<m; j++){
            cin>>a>>b;
            vertices[a].push_back(b);
            vertices[b].push_back(a);
        }
    }

    for(int i=0; i<n; i++){
        if (!visto[i]){
            conjuntos.insert(tamconjunto(i));
        }
    }
    cout<<conjuntos.size()<<endl;
    for(int v : conjuntos){
        cout<<v<<" ";
    }

    return 0;
}