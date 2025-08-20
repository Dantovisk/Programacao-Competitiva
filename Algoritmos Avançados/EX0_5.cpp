#include <bits/stdc++.h>    // Dante Brito Lourenço - 15447326
#define tup tuple<double, int, string>
using namespace std;

const double pi = acos(-1);
const double R = 6371.0;
const double degToRad = pi/180.0;

double haversine(double lat1, double lon1, double lat2, double lon2){
    lat1 *= degToRad;
    lon1 *= degToRad;
    lat2 *= degToRad;
    lon2 *= degToRad;

    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;

    double sinLat = sin(dlat/2);
    double sinLon = sin(dlon/2);

    double a = sinLat*sinLat + cos(lat1)*cos(lat2)*sinLon*sinLon;
    double c = 2 * asin(sqrt(a));

    return R * c;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;

    double trueX, trueY;
    cin>>trueX>>trueY;

    priority_queue <tup, vector<tup>, greater<tup>> pq;
    cout<<fixed<<setprecision(3);

    for(int i =0; i<n; i++){
        string nome;
        double x, y;
        cin>>nome>>x>>y;

        double palpite = haversine(x, y, trueX, trueY);
        pq.push({palpite, i, nome});

        //Fala o melhor palpite até agr
        auto melhorpalpite = get<0>(pq.top());
        cout<<"> [AVISO] MELHOR PALPITE: "<<melhorpalpite<<"km\n";
    }

    cout<<"\nRANKING\n-------\n";

    int cont = 1;
    while(!pq.empty()){
        auto [palpite, id, nome] = pq.top();
        pq.pop();


        cout<<right<<setw(2)<<cont++;
        cout<<". "<<left<<setw(20)<<nome;
        
        cout<<" : "<<right<<setw(6)<<palpite;
    
        cout<<" km"<<(palpite <0.05? " [FANTASTICO]\n" : "\n");
    }

    return 0;
}