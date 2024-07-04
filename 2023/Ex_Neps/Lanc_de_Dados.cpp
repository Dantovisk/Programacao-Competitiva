#include <bits/stdc++.h>

using namespace std;

int main(){
    int dice[12];
    int n, index, greater = 0;
    vector <int> answer;


    cin>>n;

    for(int i = 0 ; i<12; i++) dice[i] = 0;

    for(int i = 0 ; i<n; i++){
        cin>>index;
        dice[index-1] ++;
        if(dice[index-1]>greater) greater = dice[index-1];
    }

    for(int i = 11 ; i>=0; i--){
        if (dice[i]==greater) answer.push_back(i+1);
    }

    while(!answer.empty()){
        cout<<answer.back()<<" ";
        answer.pop_back();
    }


    return 0;
}

