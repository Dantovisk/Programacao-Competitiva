#include <bits/stdc++.h>
using namespace std;

int main(){

    int T, tamanho;
    string reading;
    cin>>T;
    char resposta[T];
    bool reau;
    stack <char> carac;
    for (int i = 0; i<T; i++){
        reau = true;
        cin>>reading;
        tamanho=reading.size();

        while(!carac.empty())
            carac.pop();

        for(int j=0; j<tamanho;j++){
            if(reading[j]==']'){
                if (!carac.empty()){
                    if(carac.top()=='['){
                        carac.pop();
                    }else reau=false;
                }else reau=false;
           }
           else if(reading[j]=='}'){
                if (!carac.empty()){
                    if(carac.top()=='{'){
                        carac.pop();
                    } else reau=false;
                }else reau=false;

           }
           else if(reading[j]==')'){
                if (!carac.empty()){
                    if(carac.top()=='('){
                        carac.pop();
                    } else reau=false;
                }else reau=false;

           }
           else carac.push(reading[j]);
        }
        if(reau == true && carac.empty()){
            resposta[i] = 'S';
        } else resposta[i] = 'N';
    }

    for (int i = 0; i<T; i++){
        cout<< resposta [i]<<endl;
    }

}