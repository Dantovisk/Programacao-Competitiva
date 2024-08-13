#include <bits/stdc++.h>

using namespace std;
bool visto[200010];
vector <vector<pair<int,int>>> vertices(200010);
multiset <int> conjuntos;
int n;

int tamconjunto(int a, int tlimite){
    int resp=1;
    visto[a]= true;
    for(pair<int,int> x: vertices[a]){
        if(!visto[x.first] && x.second<=tlimite){
            resp+= tamconjunto(x.first, tlimite);
        }
    }
    return resp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m, t, a, b, temp;
    cin>>n;
    cin>>m>>t;
    for(int j = 0; j<m; j++){
        cin>>a>>b>> temp;
        vertices[a].push_back(make_pair(b,temp));
        vertices[b].push_back(make_pair(a,temp));
    }
    int minimo=0, maximo = 8760, media;

    while(minimo<maximo){
            for(int i =0; i<=n; i++){
                visto[i] = false;
            }
            media = minimo + (maximo-minimo)/2;
            
            int k = tamconjunto(1, media);
            
            //cout<<"Media: "<<media<<" k: "<<k<<"\n";

            if(k>=t) maximo = media;
            else minimo = media+1;
        }

    cout<<minimo<<"\n";
    
    return 0;
}