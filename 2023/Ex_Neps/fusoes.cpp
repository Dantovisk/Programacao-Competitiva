#include <bits/stdc++.h>

using namespace std;

const int MAXN =100010;
int parent[MAXN], size[MAXN];


int find(int a){
    if(parent[a]==a)
        return a;
    return parent[a] = find(parent[a]);
}

void merge(int b, int c){
    b = find(b);
    c = find(c);

    if(b==c)
        return;

    if(size[b]>= size[c]){
        parent[c]=b;
        size[b]+=size[c];
    }
    else{
        parent[b]=c;
        size[c]+=size[b];
    }
}

int main(){

    int N, K, b1, b2;
    char op;
    cin >> N >> K; // numero de elementos e numero de operações
    queue <char> resposta;
    for (int i = 1; i<=N; i++){
        parent[i]=i;
        size[i]=1;
    }

    for (int i = 0; i<K; i++){
        cin>>op>>b1>>b2;
        if (op == 'F'){
            merge(b1,b2);
        } else if(op =='C'){
            if(find(b1)==find(b2)){
                resposta.push('S');
            }
            else{
                resposta.push('N');
            }
        }
    }

    while(!resposta.empty()){
        cout<<resposta.front()<<endl;
        resposta.pop();
    }

    return 0;
}