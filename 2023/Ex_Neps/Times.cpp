#include <bits/stdc++.h>

using namespace std;

int main(){

    int N, T, intLida; //n de jogadores, n de times
    string strLida;
    pair<int,string> a;
    priority_queue < pair<int,string>, vector <pair<int,string>> > pq;

    cin>> N>> T;

    priority_queue<string, vector<string>,greater<string>> equipes[T];

    for(int i=0; i<N; i++){
        cin>>strLida>>intLida;
        a = make_pair(intLida,strLida);
        pq.push(a);
    }

    while (!pq.empty())
    {   
        for (int i = 0; i < T; i++)
        {
            if(!pq.empty()){
                equipes[i].push(pq.top().second);
                pq.pop();
            }
        }
                
    }

    int ordem;

    for(int i = 0; i < T; i++){
        cout<<"Time "<<i+1<<endl;
        ordem = equipes[i].size();
        for(int j=0; j < ordem; j++){
            cout<<equipes[i].top()<<endl;
            equipes[i].pop();
        }
        cout<<endl;
    }
    

}