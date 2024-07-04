#include <bits/stdc++.h>

using namespace std;

int main(){
    unsigned int NumAlg=1, DigRet=1;
    string digitos, resposta;

    while(cin>>NumAlg>>DigRet){ 
        if(NumAlg==0 && DigRet==0) return 0; //se a leitura de ambos for igual a 0, retorne 0

        cin>> digitos; //lê os digitos do 1° número

        unsigned int erased = 0; // é o índice do digito apagado
        for(char atual : digitos){   //3759, 3 e 0   -> 3759, 7 e 3 -> 3759, 5 e 7 -> 3759, 9 e 49 
            while(resposta.size() > 0 && atual > resposta.back() && erased < DigRet){
                resposta.pop_back();
                erased++;
            }

            if(resposta.size() < NumAlg-DigRet) resposta.push_back(atual);
        }

        cout << resposta << "\n";

        digitos.clear();
        resposta.clear();
    }

    return 0;

}