#include <bits/stdc++.h>
using namespace std;

//representa nossos retângulos
struct rect{
    int x1 = 1e9+7, x2 = -1e9-7;// x1, é a coordenada à esquerda. x2 à direita
    int y1 = 1e9+7, y2 = -1e9-7;// x1, é a coordenada à em baixo. x2 acima
    
    //constroi retangulos a partir de 4 pontos
    rect(vector<pair<int, int>> & pts){
        for(int i =0; i<4; i++){
            x1 = min(pts[i].first, x1);
            x2 = max(pts[i].first, x2);
            y1 = min(pts[i].second, y1);
            y2 = max(pts[i].second, y2);
        }
    }
};

bool intersect(rect a, rect b){
    //a deve estar à esquerda de b
    if(a.x1 > b.x1) swap(a, b);

    // a acaba antes de b começar
    if(b.x1 > a.x2) return false;

    // em x pode ter intersecção!

    //a deve abaixo de b
    if(a.y1 > b.y1) swap(a, b);

    // a acaba embaixo de b começar
    if(b.y1 > a.y2) return false;

    return true;
}

void solve(){
    vector<pair<int, int>> q1, q2;

    //lê os pontos
    for(int i = 0; i<4; i++){
        int a, b;
        cin>>a>>b;
        q1.push_back({a, b});
    }
    for(int i = 0; i<4; i++){
        int a, b;
        cin>>a>>b;
        q2.push_back({a, b});
    }
    rect r1(q1), r2(q2);
    if(intersect(r1, r2)){
        cout<<"SIM\n";
    }else{
        cout<<"NAO\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0); // para facilitar a visualização

    int t = 1;;
    // cin>>t;

    while(t--) solve();
}