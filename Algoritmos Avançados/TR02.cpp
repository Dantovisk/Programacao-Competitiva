#include <bits/stdc++.h>

using namespace std;

// Epsilon para comparação de igualdade entre doubles
const double EPS = 1e-9;


// IMPLEMENTAÇÃO DO DISJOINT SET UNION (UNION FIND)
struct UF{
    vector<int> sz, pai;
    UF(int n){
        sz.resize(n, 1);
        pai.resize(n);

        for(int i =0; i<n; i++){
            pai[i] = i;
        }
    }

    int find(int a){ //find com compressão de caminho
        while(pai[a] != a) return pai[a] = find(pai[a]);
        return pai[a];
    }
    //merge com compressão de rank
    void merge(int a, int b){
        a = find(a);
        b = find(b);

        if(sz[b] > sz[a]) swap(a, b);

        pai[b] = a;
        sz[a] += sz[b];
    }
};


void solve(){
    int quantTotal, quantImportantes, maxTensao;
    cin>>quantTotal>>quantImportantes>>maxTensao;

    // Mapeia o id do sistema para suas coordenadas
    vector<pair<double, double>> coord(quantTotal);

    // Mapeia o nome do sistema para um identificador inteiro único
    map<string, int> id; 

    // Armazena os sistemas na ordem do input
    vector<string> sistemas(quantTotal);

    for(int i =0; i<quantTotal; i++){
        cin>>sistemas[i];
        double x, y;
        cin>>x>>y;
        coord[i] = {x, y}; 
        id[sistemas[i]] = i;
    }

    // PARTE 1 - MST COM KRUSKALL
    vector<tuple<double, int, int>> arestas;


    // Cria arestas entre os sistemas importantes
    for(int i =0; i<quantImportantes; i++){
        for(int j =i+1; j<quantImportantes; j++){
            auto [x1, y1] = coord[i];
            auto [x2, y2] = coord[j];
            double dist = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));

            //ignora arestas que passem do limite de tensao
            if(dist > maxTensao) continue; 

            arestas.push_back({dist, i, j});
        }
    }

    vector<tuple<double, int, int>> arestasSelecionadas;

    UF conjuntos = UF(quantImportantes);

    sort(arestas.begin(), arestas.end());

    for(int i =0; i<arestas.size(); i++){
        auto [dist, a, b] = arestas[i];

        if(conjuntos.find(a) == conjuntos.find(b)) continue;
        conjuntos.merge(a, b);
        arestasSelecionadas.push_back(arestas[i]);
    }

    cout<<fixed<<setprecision(2);
    for(auto [dist, a, b]: arestasSelecionadas){
        cout<< sistemas[a] <<", ";
        cout<< sistemas[b] <<", "<<dist<<"\n";
    }

    //-------------------------------------------
    // PARTE 2 - PONTOS MAIS PROXIMOS NO PLANO
    double minDist = 1e15 + 50;
    int melhor1 = 0, melhor2 = 0; // Os pontos mais próximos

    vector<tuple<double, double, int>> pontos;

    //Pega os pontos no plano e os ordena pelas posições em X e Y
    for(int i =0; i<quantTotal; i++){
        pontos.push_back({coord[i].first, coord[i].second, i});
    }  
    sort(pontos.begin(), pontos.end());

    // Mantém a posição y e o IDs dos pontos que podem ser considerados no cálculo da distância
    set <pair<double, int>> abertos;
    int ponteiro_remocao = 0;

    for(int i =0; i< pontos.size(); i++){
        auto [currX, currY, currId] = pontos[i];

        // Remove os pontos que abertos que estão mais distantes em X do ponto atual
        // Do que a menor distância encontrada
        while (ponteiro_remocao < i) {
            auto [oldX, oldY, oldId] = pontos[ponteiro_remocao];
            if (currX - oldX > minDist) {
                abertos.erase({oldY, oldId});
                ponteiro_remocao++;
            } else {
                break; // Se este ponto está na faixa, os próximos também estarão
            }
        }

        //Encontra os limites superiores e inferiores dos candidatos
        auto it_lower = abertos.lower_bound({currY - minDist, -1});
        auto it_upper = abertos.upper_bound({currY + minDist, -1});
        
        // Verifica para cada candidado sua distância
        while(it_lower != it_upper){
            int candidatoID = (*it_lower).second;
            auto [candX, candY] = coord[candidatoID];

            double newDist = sqrt(pow(currX-candX, 2)+ pow(currY-candY, 2));

            // Encontrou um candidado melhor
            if(newDist < minDist - EPS){
                minDist = newDist;
                melhor1 = currId;
                melhor2 = candidatoID;
            }
            // No caso de empate, mantemos o que apareceu antes no input
            else if(abs(newDist - minDist) < EPS){
                int comp1 = currId, comp2 = candidatoID;
                int comp3 = melhor1, comp4 = melhor2;
                if(comp1 > comp2) swap(comp1, comp2);
                if(comp3 > comp4) swap(comp3, comp4);

                // Atualiza somente se o novo par for estritamente menor que o melhor par atual
                if (make_pair(comp1, comp2) < make_pair(comp3, comp4)) {
                    melhor1 = currId;
                    melhor2 = candidatoID;
                }
            }

            ++it_lower;
        }

        abertos.insert({currY,currId});
    }

    // Imprime em ordem de entrada
    if(id[sistemas[melhor1]] > id[sistemas[melhor2]]) swap(melhor1, melhor2);

    cout<<"Ponto de Ressonância: "<<sistemas[melhor1]<<", "<<sistemas[melhor2]<<", ";
    cout<<minDist<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int casos;
    cin>>casos;

    while(casos--){
        solve();
        cout<<"\n";
    }

}