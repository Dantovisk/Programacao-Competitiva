#include<bits/stdc++.h>
using namespace std ;
#define pii pair<ll, ll> 
#define ff first 
#define ll long long 
#define ss second 
#define esq (2*no)
#define dir ((2*no)+1)
#define meio ((i+j)>>1)
#define ld long double 
#define vi vector<int> 
#define ii int 
#define endd "\n"
#define pb push_back
#define pf pop_front

const int maxn = 1e5 + 5 ; 
const int maxl = 22 ; 
const int prime = 911382323 ; 
const int prime2 = 31 ;

/* 
Trie
*/

int n ; 
map<pii, int> trie ; 
int ct ; 
set<int> who[maxn*28], fim[maxn*28] ; 

void add(string s, int i){
    int root = 0 ; 
    for(auto a : s){
        if(trie.find({root, a-'a'}) == trie.end()){
            trie[{root, a-'a'}] = ++ct ; 
        }
        root = trie[{root, a-'a'}] ; 
        who[root].insert(i) ; 
    }
    fim[root].insert(i) ; 
    //who[root].insert(i);
}

void remove(string s, int i){
    int root = 0 ; 
    for(auto a : s){
        if(trie.find({root, a-'a'}) == trie.end()) break ; 
        root = trie[{root, a-'a'}] ; 
        who[root].erase(who[root].find(i)) ;
    }
    fim[root].erase(fim[root].find(i)) ; 
    //who[root].erase(who[root].find(i)) ; 
}

string st[maxn] ; 

bool has_fim(int node, int l, int r){
    auto it = fim[node].lower_bound(l) ; 
    if(it == fim[node].end()) return 0 ; 
    if((*it) <= r) return 1 ; 
    return 0 ; 
}

void query_ter(int l, int r, string s){
    //vou percorrendo s 
    //se n der pra descer eu retorno 0 
    //se eu to num terminal que eh de 
    // l a r retorna 1
    int root = 0 ; 
    for(auto a : s){
        if(trie.find({root, a-'a'}) == trie.end()){
            cout << "N\n" ; return ; 
        }
        root = trie[{root, a-'a'}] ; 
        if(!fim[root].size()) continue ; 
        if(has_fim(root, l, r)){
            cout << "Y\n" ; return ; 
        }
    } 
    
    cout << "N\n" ; 

}

bool has(int node, int l, int r){
    auto it = who[node].lower_bound(l) ; 
    if(it == who[node].end()) return 0 ; 
    if((*it) <= r) return 1 ; 
    return 0 ; 
}

void query_meio(int l, int r, string s){

    int root = 0 ; 

    for(auto a : s){
        if(trie.find({root, a-'a'}) == trie.end()){
            cout << "N\n" ; return ; 
        }
        root = trie[{root, a-'a'}] ; 
        if(has(root, l, r)){
            cout << "Y\n" ; return  ;
        }
    }
    
    cout << "N\n" ; 

}

int main(){

    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

    cin >> n ; 

    for(int i = 1 ; i <= n ; i++){
        cin >> st[i] ; 
        add(st[i], i) ; 
    }

    int q ; cin >> q ; 

    while(q--){
        int t ; cin >> t ; 
        if(t == 1){
            string k ; 
            int j ; cin >> j >> k ; 
            remove(st[j], j) ; 
            add(k, j) ; 
            st[j] = k ; 
        }
        else if(t == 2){
            int l, r ; string s ; 
            cin >> l >> r >> s ;
            query_ter(l, r, s) ; 
        }
        else{
            int l, r ; string s ; 
            cin >> l >> r >> s ; 
            query_meio(l, r, s) ; 
        }
    }

}