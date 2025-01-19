#include <bits/stdc++.h>
#define MAXN 1000010

using namespace std;

int n, m, d;
int mx [MAXN], my[MAXN];

int main(){
    cin>>n>>m>>d;

    //vector <vector<int>> v(n+1, vector<int>(m+1));
    /*
    for(int i=0; i < n; i++){
        int cont = 1;
        for(int j=0; j < m; j++){
            v[i][j] = cont;
            cont++;
        }
    }*/

    for(int i=0; i < n; i++){
        my[i] = i*m;
    }

    for(int i=0; i < m; i++){
        mx[i] = i;
    }

    for(int j=0; j < d; j++){
        char c; int a, b;
        cin>>c>>a>>b;
        if(c=='C'){
            swap(mx[a-1], mx[b-1]);
        } else if(c=='L'){
            swap(my[a-1], my[b-1]);
        }   
    }

    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            cout<< 1+ my[i] + mx[j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}