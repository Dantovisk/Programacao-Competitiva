#include <bits/stdc++.h>
const int MAXN = 250010 *30;

using namespace std;

int trie[MAXN][27];
vector<int> minProx(MAXN, 30);
int atual = 1;

void insert(string a){
    int node = 0;

    for(auto c: a){
        int code = c-'a';
        minProx[node] = min(minProx[node], code);
        if(!trie[node][code]) trie[node][code] = atual++;
        node = trie[node][code];
    }
    trie[node][26] = -1;
    minProx[node] = -1;
}

string search(string a){
    //cout<<"a = "<<a<<"\n";
    string resp = "";
    int node = 0;

    //achando digitos iguais;
    for(auto c: a){
        int code = c-'a';
        if(!trie[node][code]){
            break;
        }
        node = trie[node][code];
        resp += c;
        //cout<<resp<<"\n";
    }

    //achando lexicograficamente menor
    while(1){
        int k = minProx[node];
        if(k==-1) return resp;

        resp += ('a' + k);
        node = trie[node][k];
        //cout<<resp<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;

    getline(cin, line);
    while(!line.empty()){
        string a = line;
        reverse(a.begin(), a.end());
        insert(a);

        getline(cin, line);
    }


    getline(cin, line);
    while(!line.empty()){
        string a = line;
        reverse(a.begin(), a.end());

        a = search(a);
        reverse(a.begin(), a.end());
        cout<<a<<"\n";
        getline(cin, line);
    }



    return 0;
}