#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector <bool> visto(100010, false);

    int n, m;
    cin>>n>>m;

    vector <vector <int>> odio (100010);
    vector<set <int>> valido(2);

    int a, b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        odio[a].push_back(b);
        odio[b].push_back(a);
    }
    bool falhou = false;

    for(int i=1; i<=n; i++){
        //int j=0;
        int impA =0, impB=0, impG =0;

        for(int k=0; k<odio[i].size(); k++){
            bool x = (valido[0].find(odio[i][k])!=valido[0].end());
            bool y = (valido[1].find(odio[i][k])!=valido[1].end());

            if(x && !y){
                impA++;
            }else if(!x && y){
                impB++;
            } else if(x && y) impG++;
            
        }
        if(impA==0 && impB>0){
            valido[0].insert(i);
            for(int h=0; h<odio[i].size(); h++){
                valido[0].erase(odio[i][h]);
            }
        }else if(impB==0 && impA>0){
            valido[1].insert(i);
            for(int h=0; h<odio[i].size(); h++){
                valido[1].erase(odio[i][h]);
            }
        }else if(impB==0 && impA==0){
            if(impG>0){
                for(int h=0; h<odio[i].size(); h++){
                    valido[0].erase(odio[i][h]);
                }
            }
            valido[0].insert(i);
            valido[1].insert(i);
            
        }else{
            falhou = true;
            break;
        }
        /*
        for(int k=0; k<odio[i].size(); k++){
            if(valido[j].find(odio[i][k])!=valido[j].end()){
                j++;
                if(j==2){
                    falhou = true;
                    break;
                }
            }
        }
        if(j==2) break;
        valido[j].insert(i);
        */
    }
    for(int z: valido[0])cout<<z<<" ";
    for(int z: valido[1])cout<<z<<" ";
    if(falhou) cout<<-1;
    else{
        cout<<max(valido[0].size(), valido[1].size());
    }
    return 0;
}