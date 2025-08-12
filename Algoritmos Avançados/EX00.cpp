#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, float> registros;

    int n; cin>>n;
    for(int i =0; i<n; i++){
        string nome;
        float val;
        cin>>nome>>val;

        if(registros.find(nome) != registros.end()){ //já tem
            cout<<"Produto com código "<<nome<<" já cadastrado.\n";
            continue;
        }
        registros[nome] = val;
    }

    int q; 
    cin>>q;

    cout<<fixed<<setprecision(2);

    while(q != -1){
        float resp = 0.0;

        for(int i =0; i<q; i++){
            string nome;
            float val;
            cin>>nome>>val;

            if(registros.find(nome) != registros.end()){ //achou
                resp += val*registros[nome];
            }
            else{
                cout<<"Produto com código "<<nome<<" não cadastrado.\n";
            }
        }
        cout<<"R$"<<resp<<"\n";
        cin>>q;
    }


    return 0;
}