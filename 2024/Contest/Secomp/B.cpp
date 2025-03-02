#include <bits/stdc++.h>    //sei la esse enunciado ta mal feito

using namespace std;

map <string, int> poderes;

int main(){
    int n, k, j;
    cin>>n>>k>>j;

    int vidas = 3, contPod = 0, contVid = 0;

    for(int i=0; i<k; i++){
        string a; int b;
        cin>>a>>b;
        poderes[a] = b;
    }
    for(int i=0; i<n; i++){
        string a;
        cin>>a;
        if (a=="inimigo"){
            if(contPod > 0){
                contPod--;
                contVid++;
                if(contVid>=j){
                    vidas++;
                    contVid = 0;
                }
            }
            else break;
        }
        else{
            contPod += poderes[a];
        }
    }
    cout<<vidas;
    return 0;
}