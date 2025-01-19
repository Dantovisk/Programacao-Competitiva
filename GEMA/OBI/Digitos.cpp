#include <bits/stdc++.h> // OBI 3a fase - 2022

using namespace std;

string v = "";

string nextString(string s){
    string ret = s;
    int i = s.length() - 1;
    
    while(1){
        if(ret[i] == '9'){
            ret[i] = '0';
            if(i == 0){
                ret = "1" + ret;
                return ret;
            }
            i--;
        }
        else{
            ret[i]++;
            return ret;
        }
    }

}

int main(){
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        char c;
        cin>>c;
        v.push_back(c);
    }
    
    for(int dig=1; dig<=n; dig++){
        bool reau = true;
        string ant = "", atual = "";
        int i=dig;
        ant = v.substr(0, dig);

        string esp = nextString(ant);
        int espSize = esp.length();
 
        while(i<n){
            atual = v.substr(i, espSize);
            if(atual != esp){
                reau = false;
                break;
            }

            i+= espSize;
            ant = atual;
            esp = nextString(atual);
            espSize = esp.length();
        }
        if(reau) {
            cout<< v.substr(0, dig);
            return 0;
        }
    }

    return 0;
}