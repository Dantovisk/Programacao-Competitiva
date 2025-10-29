#include <bits/stdc++.h>

using namespace std;

vector <vector<int>> nums(10);
int respostas[10];

int main(){
    int n, m;
    cin>>n>> m;
    int a, primeiro;
    cin>>primeiro;
    nums[primeiro].push_back(0);
    respostas[primeiro] = 1;
    for(int i =1; i<n; i++){
        cin>>a;
        nums[a].push_back(i);
    }

    int ant= 0, lido, add; 
    auto ptr1 = nums[0].begin();
    auto ptr2 = nums[0].begin();
    
    for(int i =0; i<m; i++){
        cin>>lido;
        for(int i =0; i<10; i++){
            if(ant<lido){
                ptr1 = upper_bound(nums[i].begin(),nums[i].end(),ant);
                ptr2 = upper_bound(nums[i].begin(),nums[i].end(),lido-1);
            } else{
                ptr1 = lower_bound(nums[i].begin(),nums[i].end(),lido-1);
                ptr2 = lower_bound(nums[i].begin(),nums[i].end(),ant);
            }
            
            add = abs(ptr2-ptr1);
            respostas[i]+= add;
        }
        ant = lido-1;
    }
    for(int i =0; i< 10; i++){
        cout<<respostas[i]<<" ";
    }
    return 0;
}