#include <bits/stdc++.h>
 
using namespace std;
bool deu = true;
set <string> base;
int n;
string resposta;
 
bool brute(int x, int w, string b){
    string l = "";
    l += ('a'+(w-1));
    if(x==n-1) {
        if(base.find(b+l) == base.end()){
            deu = false;
            resposta = b+l;
            return false;
        }
        return true;
    }
    else{
        for(int i = w; i>=1; i--){
            if(!brute(x+1, i, b+l)) return false;
        }
        return true;
    }
}
 
int main(){
    int f; cin>>f;
 
    for(int j=0;j<f; j++){
        int k, m;
        cin>>n>>k>>m;
 
        string a;
        cin>>a;
 
        for(int i = n-1; i<m; i++){
            base.insert(a.substr((i-n)+1,n));
        }

        for(int i=1; i<=k; i++){
            brute(0, i, "");
            if(!deu) break;
        }
 
        if(deu){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl<<resposta<<endl;
        base.clear();
        deu = true;
    }
    return 0;
}