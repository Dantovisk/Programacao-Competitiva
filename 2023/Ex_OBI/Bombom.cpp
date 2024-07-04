#include <bits/stdc++.h>
using namespace std;

string manilha;
string luana ;
string edu ;
int ptsEdu =0;
int ptsLuana = 0;

void teste(string nilbs, int &x){
    if(nilbs[0] == 'A'){
        x+=10;
    }
    else if(nilbs[0] == 'J'){
        x+=11;
    }
    else if(nilbs[0] == 'Q'){
        x+=12;
    }
    else if(nilbs[0] == 'K'){
        x+=13;
    }
}

int main(){
    cin >> manilha;

    for(int i=0; i<3 ;i++){
        cin >> luana;
        if (luana[1]==manilha[1]){
            ptsLuana+=4;
        }
        teste(luana,ptsLuana);

    }
    for(int j=0; j<3 ;j++){
        cin >> edu;
        if (edu[1]==manilha[1]){
            ptsEdu+=4;
        }
        teste(edu,ptsEdu);
        
    }


    if(ptsEdu>ptsLuana){
        cout<<"Edu";
    }
    else if(ptsEdu<ptsLuana){
        cout<<"Luana";
    } else  cout<<"empate";

}