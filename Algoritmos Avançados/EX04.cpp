#include <bits/stdc++.h>

using namespace std;

// Mapeia o nível do herói para a sua produtividade
map <string, float> produtividade = 
    {{"Aprendiz", 0.75},
    {"Aventureiro", 1.00},
    {"Cavaleiro", 1.20},
    {"Mestre", 1.50}, 
    {"Lenda", 2.00}};

void solve(){
    int n, m; 
    cin>>n >> m;
    vector<vector<int>> adj(m+1); // adj[i] = lista de quests que dependem da quest i
    vector<int> grau(m+1, 0); // grau[i] = número de pré-requisitos que a quest i ainda precisa completar

    vector<pair<float, string>> herois; //par(produtividade, nome) do i-ésimo herói
    vector<vector<int>> tasks(n);    // tasks[i] = lista de quests atribuídas ao i-ésimo herói
    vector<float> tempo (n, 0);    // tempo[i] = tempo acumulado que o i-ésimo herói gastou até agora
    vector<float> custo(m+1, 0);    // custo[i] = custo base da quest i (em tempo)
    vector<float> liberation_time (m+1, 0); // liberation_time[i] = tempo em que a quest i fica liberada (todos pré-requisitos concluídos)
    

    for(int i = 0; i<n; i++){
        string nome, classe;
        cin>>nome>>classe;

        herois.push_back({produtividade[classe], nome});
    }
    //sort(herois.rbegin(), herois.rend());

    for(int i = 0; i<m; i++){
        int id;
        float cost;
        cin>>id>>cost;

        custo[id] = cost;

        string line;
        getline(cin, line);
        istringstream iss(line);
        int x;
        while(iss >> x){
            adj[x].push_back(id); // a quest x é pré-requisito de id
            grau[id]++; // conta pré-requisitos da quest id
        }  
    }

    // Fila de quests prontas para alocação
    queue<int> pronto;

    // Sempre começando da "quest 0", que é fictícia e já pronta
    pronto.push(0);

    float res = 0; // tempo total mínimo para completar todas as quest (resposta)

    while(!pronto.empty()){
        int u = pronto.front();
        pronto.pop();

        float best = 1e7 + 6;
        int goat = 0;
        for(int i =0; i<n; i++){
            // Define o tempo em que a tarefa u será desbloqueada:
            // Será o máximo entre o tempo que o heroi i deixa de estar ocupado
            // vs o tempo que as dependências da tarefa u são concluídas.
            float tempo_inicio = max(tempo[i], liberation_time[u]);

            // Se o heroi atual vai terminar a tarefa antes do melhor encontrado
            // até agora, vale a pena pegar
            if(tempo_inicio + custo[u]/herois[i].first < best){
                best = tempo_inicio + custo[u]/herois[i].first;
                goat = i; // O goat é o heroi que melhor se qualifica pra tarefa u
            }
        }

        // Atualiza a resposta
        res = max(res, best);

        // Deixa o heroi escolhido ocupado com a tarefa
        tasks[goat].push_back(u);
        tempo[goat] = best;

        // Elimina as dependências da tarefa atual
        for(auto v : adj[u]){
            grau[v]--;
            if(grau[v] == 0){
                pronto.push((v));
                liberation_time[v] = max(best, liberation_time[v]);
            }
        }
    }

    // Impressão da resposta
    for(int i =0; i<n; i++){
        string nome = herois[i].second;

        cout<<nome<<" = {";

        for(int j =0; j< tasks[i].size(); j++){
            if(tasks[i][j] == 0) continue;
            
            cout<<tasks[i][j];
            if(j < tasks[i].size()-1) cout<<",";
        }
        cout<<"}\n";
    }

    cout<<fixed<<setprecision(2);
    cout<<"Tempo mínimo: "<<res<<"\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin>>q;

    while(q--){
        solve();

        if(q>=1) cout<<"\n";
    }

}