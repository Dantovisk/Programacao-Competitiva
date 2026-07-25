#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5+7;
const int inf = 1e9+7;

//retorna a melhor resposta que está no mínimo até o índice i
pair<int, long long> dp[MAX];

// Representa um intervalo
struct interv{
    int st, ed, val;

    interv(int a, int b, int c){
        st = a;
        ed = b;
        val = c;
    }
    bool operator <(interv &a){ // Ordena os intervalos pelo menor tempo de saída
        return (*this).ed < a.ed;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0); // para facilitar a visualização
    int n;
    cin>>n;

    // armazena tempo de fim e o indice de cada intervalo
    set<pair<int, int>> vistos;
    
    vector<interv> v; //armazena os intervalos
    v.emplace_back(0, 0, 0); // sentinela
    vistos.insert({0, 0});
    dp[0] = {0, 0};

    for(int i = 0; i<n; i++){
        int l, r, p;
        cin>>l>>r>>p;

        v.emplace_back(l, r, p);
    }
    
    // ordena pelo horario de finalização
    sort(v.begin(), v.end());
    
    // itera pelos intervalos
    for(int i = 1; i <= n; i++){
        vistos.insert({v[i].ed, i});

        //encontra o indice mais a direita que termina antes
        //do meu intervalo começar
        auto ptr = vistos.lower_bound({v[i].st, inf});
        ptr--;

        // Verifica qual seria a resposta se eu escolhesse o intervalo atual
        pair<int, long long> newval = dp[(*ptr).second];
        newval.first ++;
        newval.second += v[i].val;

        dp[i] = max(newval, dp[i-1]);
        // cout<<"dp["<<i<<"] = "<<dp[i].first<<", "<<dp[i].second<<"\n";
    }

    cout<<dp[n].first<<" "<<dp[n].second<<"\n";
}
