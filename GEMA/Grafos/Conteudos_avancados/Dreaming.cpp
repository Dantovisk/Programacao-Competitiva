#include <bits/stdc++.h>    //Dreaming - IOI 2013
#define pii pair<int,int>

using namespace std;

/*eu acho q a solução é encontrar os centros dos grafos ponderados, e somar as 2 maiores distancias
do centro pra ponta, e se for necessario, somar L

Passos para a solução:
1 -> para todos os subsets encontrar o centro da árvore, que minimize as duas maiores distâncias entre cada nó e o centro
2 -> Salvar para todos

*/
int travelTime(int N,int M,int L,int A[],int B[],int T[]){
    vector<pii> adj[N+1];
    int vis[N+1] = {};
    int fstMax, sndMax, fstMaxSon;

    for(int i=0; i<M; i++){
        adj[A[i]].push_back({T[i], B[i]});
        adj[B[i]].push_back({T[i], A[i]});
    }

    for(int i=1; i<=N; i++){
        if(vis[i]) continue;
        // agora precisamos encontrar o centro de cada subarvore
        

    }


    return max(fstMax + fstMaxSon, fstMax +sndMax + L);
}

int main() {
    

    return 0;
}

