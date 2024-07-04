#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, c;

    int atrasados = 0;

    cin>> c >> n;

    priority_queue <int, vector<int>, greater<int>> tfilas;

    queue <pair<int,int>> q;

    int tCheg, tAtend;

    for (int i = 0; i < n; i++)
    {
        cin>>tCheg>>tAtend;
        pair<int,int> a = make_pair(tCheg,tAtend);
        q.push(a);
    }
    for (int i = 0; i < c; i++) tfilas.push(0);

    int tnovo;
    while (!q.empty())
    {
        if(q.front().first>=tfilas.top()){
            tnovo= q.front().first + q.front().second;
        }
        else 
        {
            if(tfilas.top()-q.front().first>20)
                atrasados++;
            tnovo= tfilas.top() + q.front().second;
        }
        tfilas.pop();
        tfilas.push(tnovo);
        q.pop();
    }
    
    cout<<atrasados;
    

}