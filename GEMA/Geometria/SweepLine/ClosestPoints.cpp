#include <bits/stdc++.h>
using namespace std;

const double INF = 1e20;
#define pdd pair<double, double>
#define ff first
#define ss second

double dst(pdd a, pdd b){
    return sqrt((a.ff-b.ff)* (a.ff-b.ff) + (a.ss-b.ss)* (a.ss-b.ss));
}

void solve(vector<pdd>& points){
    sort(points.begin(), points.end());
    
    set<pdd> vis; //invertidos para ordenar pelo y agora
    double dist = INF;

    int esq = 0;
    pdd p1, p2;

    for(auto p: points){
        //vendo se o x não está muito à esquerda
        while(points[esq].ff < p.ff - dist){
            vis.erase({points[esq].ss, points[esq].ff});
            esq++;
        }

        auto ptr1 = vis.lower_bound({p.ss - dist, -INF});
        auto ptr2 = vis.upper_bound({p.ss + dist, INF});

        for(auto it = ptr1; it != ptr2; it++){
            double u = dst({(*it).ss, (*it).ff}, p);
            if(dist > u){
                p1 = p;
                p2 = {(*it).ss, (*it).ff};
                dist = u;
            }
        }
        vis.insert({p.ss, p.ff}); 
    }
    cout<<fixed<<setprecision(2);
    cout<<p1.ff<<" "<<p1.ss<<" "<<p2.ff<<" "<<p2.ss<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while(n>0){
        vector<pdd> points(n);
        for (auto& p : points) {
            cin >> p.ff >> p.ss;
        }
        solve(points);

        cin >> n;
    }

    return 0;
}
