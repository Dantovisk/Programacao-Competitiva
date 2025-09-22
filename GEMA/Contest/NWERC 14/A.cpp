#include <bits/stdc++.h>

using namespace std;

bool cap(char a){
    if (a >= 'A'  && a <= 'Z') return true;
    return false;
}


int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);

    int n;
    scanf("%d ^[\n]", &n);

    vector<string> a;

    vector<pair<string, int>> ord;


    for(int k =0; k<n; k++){
        string b;
        getline(cin, b);

        a.push_back(b);

        for(int i =0; i<b.size(); i++){
            if(cap(b[i])){
                ord.push_back({b.substr(i), k});
                break;
            }

        }
    }

    sort(ord.begin(), ord.end());

    for(auto [fds, id]: ord){
        cout<<a[id]<<endl;
    }

}