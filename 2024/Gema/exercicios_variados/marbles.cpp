#include <bits/stdc++.h> 

using namespace std;    //complexidade n log n

priority_queue <pair<unsigned int, int>> pq; //o valor de cada songo mongos
unsigned int a[200010], b[200010];

int main(){
    int n;
    cin>>n;
    int c;
    for(int i =0; i<n; i++){
        cin>>c;
        for(int j =0; j<c; j++) cin>>a[j];
        for(int j =0; j<c; j++) cin>>b[j];
        
        for(int j =0; j<c; j++){
            pq.push(make_pair((a[j]+b[j]),j));
        }
        long long int pontos = 0;
        bool alice =true;
        for(int j =0; j<c; j++){
            if(alice){
                pontos += (a[pq.top().second]-1);
                alice =false;
            }else{
                pontos -= (b[pq.top().second]-1);
                alice =true;
            }
            pq.pop();
        }
        cout<<pontos<<"\n";
    }

    return 0;
}