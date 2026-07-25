#include <bits/stdc++.h>
using namespace std;

//tamanho max da entrada
const int maxn = 1e3+3;

// abstrai as coordenadas cartesianas
struct cords{
    double x, y;
    cords(double x1, double y1){
        x = x1;
        y = y1;
    }
    cords operator-(cords b){
        return cords(x - b.x, y - b.y);
    }
    double norm(){
        return sqrt(x*x + y*y);
    }
};

//UNION FIND PARA FAZER KRUSKALL
namespace UF{
    int par[maxn], sz[maxn];
    void setup(int n){
        for(int i = 0; i<=n; i++) {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int find(int a){
        //compressão de caminho
        if(par[a] != a) return par[a] = find(par[a]);
        return par[a];
    }
    bool merge(int a, int b){
        a = find(a);
        b = find(b);
        // Small to large merging (compressao de tamanho)
        if(sz[b] > sz[a]) swap(a, b);

        if(a == b) return false;
        sz[a] += sz[b];
        par[b] = a;
        return true;
    }
}

void solve(){
    int n; cin>>n;

    vector<cords> predios;

    for(int i = 0; i< n; i++){
        int a, b; cin>>a>>b;
        predios.emplace_back(a, b);
    }

    UF::setup(n);
    int m; cin>>m;
    for(int i = 0; i< m; i++){
        int a, b;
        cin>>a>>b;
        //entrada 0-indexada, trabalhamos com 1-indexado
        UF::merge(a-1, b-1);
    }
    

    double res = 0;

    // minqueue, guarda as arestas no kruskall
    // {distancia da aresta, a, b}
    priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>, greater<tuple<double, int, int>>> ed;

    for(int i = 0; i< n; i++){
        for(int j = i+1; j<n; j++){
            //adiciona o valor da aresta, e os ids dos vértices
            ed.push({(predios[i]-predios[j]).norm(), i, j});
        }
    }
   
    while(!ed.empty()){
        //pega o primeiro elemento da minheap
        auto [dist, a, b] = ed.top();
        ed.pop();

        if(UF::merge(a, b)) res += dist;
    }

    cout<<fixed<<setprecision(3);
    cout<<res<<"\n";

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t = 1;
    // cin>>t;

    for(int i = 0; i<t; i++){
        solve();
    }

}