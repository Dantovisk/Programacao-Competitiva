#include <bits/stdc++.h> //a palavra dada tem palindromo? dar um exemplo se tiver
 
using namespace std;
 
map <char,int> dicio;
 
int main(){
    string a;
    cin>>a;
    for(int i =0; i<a.length(); i++){
        if(dicio.find(a[i])==dicio.end()){
            dicio [a[i]] = 1;
        }else dicio[a[i]]++;
    }
    bool reau = true; //dá pra escrever o palindromo?
    bool meio = false;
    string r ="";
    while(dicio.size()>0){
        auto ptr = dicio.begin();
        if(ptr->second % 2==1){
            if (meio){
                reau = false;
                break;
            }
            else{
                string x ="";
                x= ptr->first;
                r.insert(r.length()/2, x);   
                meio = true;
                ptr->second--;
            }
        } 
        //cout<<"deu bom mano\n";
        string y ="";
        y = string(ptr->second /2, ptr->first ); //string é uma composição de n caracteres x
        r = y + r + y; 
        dicio.erase(ptr->first);
    }
    if(reau)cout<<r;
    else cout<<"NO SOLUTION";
    return 0;
}