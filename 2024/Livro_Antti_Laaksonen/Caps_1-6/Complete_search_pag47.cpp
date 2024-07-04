#include <bits/stdc++.h>
using namespace std;

vector <int> subset;
int n;

void search(int k) {
    if (k == n) {
    // process subset
    } else {
        search(k+1);
        subset.push_back(k);
        search(k+1);
        subset.pop_back();
    }
}

int main(){
    cin>>n;
    if(n>20) n=20;
    search(0);
}