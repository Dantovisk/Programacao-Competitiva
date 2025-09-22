#include <bits/stdc++.h>
using namespace std;

// Mapeia o nível do herói para a sua produtividade
map<string, double> produtividade = {
    {"Aprendiz", 0.75},
    {"Aventureiro", 1.00},
    {"Cavaleiro", 1.20},
    {"Mestre", 1.50},
    {"Lenda", 2.00}
};

struct Quest {
    int id;
    double custo;               // tempo base
    vector<int> deps;           // lista de pré-requisitos
};

void solve() {
    int n, m; 
    cin >> n >> m;

    // Vetor de heróis
    vector<pair<double,string>> herois; // (produtividade, nome)
    for(int i = 0; i < n; i++) {
        string nome, classe;
        cin >> nome >> classe;
        herois.push_back({produtividade[classe], nome});
    }

    // Vetor de quests
    vector<Quest> quests(m);
    for(int i = 0; i < m; i++) {
        int id;
        double cost;
        cin >> id >> cost;
        quests[i].id = id;
        quests[i].custo = cost;

        string line;
        getline(cin, line);
        istringstream iss(line);
        int x;
        while(iss >> x) {
            if(x != 0) quests[i].deps.push_back(x);
        }
    }

    // Construindo o grafico para toposort
    vector<vector<int>> adj(m+1);
    vector<int> indeg(m+1, 0);
    map<int,int> idToIndex; // mapeia ID da quest para posição no vetor
    for(int i = 0; i < m; i++) idToIndex[quests[i].id] = i;

    for(auto &q : quests) {
        for(auto d : q.deps) {
            adj[idToIndex[d]].push_back(idToIndex[q.id]);
            indeg[idToIndex[q.id]]++;
        }
    }

    // Toposort (Kahn)
    queue<int> q;
    for(int i = 0; i < m; i++) if(indeg[i] == 0) q.push(i);

    vector<int> ordem;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        ordem.push_back(u);
        for(auto v : adj[u]) {
            if(--indeg[v] == 0) q.push(v);
        }
    }

    // Guloso
    vector<vector<int>> tasks(n);     // tasks[i] = quests do herói i
    vector<double> tempo(n, 0.0);     // tempo acumulado de cada herói
    map<int,double> fim;              // fim[id] = instante em que quest id acaba

    double res = 0;

    for(auto idx : ordem) {
        Quest &cur = quests[idx];
        double melhorTempo = 1e18;
        int heroiGoat = 0;

        // Para cada herói, simular tempo de execução
        for(int i = 0; i < n; i++) {
            // Tempo mais cedo que o herói pode começar
            double inicio = tempo[i];
            for(auto d : cur.deps) inicio = max(inicio, fim[d]);

            double fimEstimado = inicio + cur.custo / herois[i].first;

            if(fimEstimado < melhorTempo) {
                melhorTempo = fimEstimado;
                heroiGoat = i;
            }
        }

        // Atribuir a quest
        tempo[heroiGoat] = melhorTempo;
        fim[cur.id] = melhorTempo;
        tasks[heroiGoat].push_back(cur.id);
        res = max(res, melhorTempo);
    }

    // Imprime a resposta
    for(int i = 0; i < n; i++) {
        cout << herois[i].second << " = {";
        for(int j = 0; j < (int)tasks[i].size(); j++) {
            cout << tasks[i][j];
            if(j+1 < (int)tasks[i].size()) cout << ",";
        }
        cout << "}\n";
    }
    cout << fixed << setprecision(2);
    cout << "Tempo mínimo: " << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;
    while(q--) {
        solve();
        if(q) cout << "\n";
    }
}
