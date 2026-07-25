#include <bits/stdc++.h>
using namespace std;

int n, l, w;

const double eps = 1e-7;

// retorna os 2 pontos em que o círculo se intersecta com 
// o limite inferior do jardim (limitado em [0, l])
pair <double, double> inters(double x, double r){
    //encontra o tamanho do intervalo que o sprinkler pega na extremidade inferior
    //com teorema de pitagoras
    double dx = sqrt(r*r - w*w/4.0);

    return {max(0.0, x-dx), min((double)l, x+dx)};
}

int main() {
    cin.tie(0)->sync_with_stdio(0); // para facilitar a visualização

    cin>>n>>l>>w;

    // intervalo que um circulo cobre na extremidade inferior/superior do retangulo
    vector<pair<double, double>> intervals;

    for(int i = 0; i< n; i++){
        int x, r;
        cin>>x>>r;

        //o circulo não toca a parte de baixo.
        if(2*r <= w) continue;
        intervals.push_back(inters(x, r));
    }

    if(intervals.empty()){
        cout<<"-1\n";
        return 0;
    }

    //ordena os intervalos pela sua abertura
    sort(intervals.begin(), intervals.end());

    int res = 0;
    double last = 0;
    
    int i = 0;
    while(i<intervals.size()){
        res++;
        
        double mx = 0;
        //dado que eu preciso pegar um sprinkler, pego o que me leva mais longe
        while(i<intervals.size() and intervals[i].first - last < eps){
            mx = max(mx, intervals[i].second);
            i++;
        }

        // não há um sprinkler que cubra tudo à esquerda
        if(mx < eps){
            cout<<"-1\n";
            return 0;
        }

        last = mx;
        
        //já achou resposta
        if(last - l > - eps){
            cout<<res<<"\n";
            return 0;
        }
    }

    // não há um sprinkler que cubra tudo à direita
    
    cout<<"-1\n";
}
