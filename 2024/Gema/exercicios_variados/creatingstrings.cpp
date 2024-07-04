#include <bits/stdc++.h>

using namespace std;

int main(){

    string a;
    cin>>a;
    set <char> letras;
    vector <string> resposta;
    for(char b : a){
        letras.insert(b);
    }

    sort(a.begin(), a.end());
    resposta.push_back(a);
    while(next_permutation(a.begin(),a.end())){
        resposta.push_back(a);
    }

    cout<< resposta.size()<<"\n";
    for(string c : resposta){
        cout<<c<<"\n";
    }
    return 0;
}