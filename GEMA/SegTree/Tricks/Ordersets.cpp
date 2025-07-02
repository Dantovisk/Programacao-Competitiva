#include <bits/stdc++.h>    //exemplo para encontrar a soma dos elementos no intervalo
#define MAXN 200010
#define int long long
using namespace std;

int tree[MAXN*4];
int v[MAXN];

// adiciona 1 no indice indi
void update(int no, int l, int r, int indx, int a){
    if(l==r){
        tree[no] = a;
        v[l] = a;
        return;
    }

    int mid = (l+r)/2;

    if(l <= indx && indx <= mid) update(2*no, l, mid, indx, a);
    else update(2*no + 1, mid+1, r, indx, a);

    tree[no] = tree[(no*2)] + tree[(no*2)+1];
}

// soma termos no intervalo
int query(int no, int i, int j, int l, int r){
    //esté fora do intervalo desejado
    if(l > j || r < i) return 0;
    //está dentro do intervalo, não precisamos entrar em uma recursão ainda mais profunda
    if(l <= i && r>=j) return tree[no];

    int meio = (i+j)/2;
    return query(2*no, i, meio, l, r) + query(2*no+1, meio +1, j, l, r);
}

int kth(int no, int i, int j, int sum){
    if(i==j) return i;

    int mid = (i+j)/2;
    if(sum >= tree[2*no])
        return kth(2*no+1, mid+1, j, sum-tree[2*no]);
    return kth(2*no, i, mid, sum);
    

}


int32_t main(){
    int n;
    cin>>n;

    vector<pair<char, int>> qr;
    vector<int> coord;
    vector<int> freq;

    for(int i =0; i<n; i++){
        char a; int b;
        cin>>a>>b;
        qr.push_back({a,b});
        coord.push_back(b);
    }

    sort(coord.begin(), coord.end());
    coord.erase(unique(coord.begin(), coord.end()), coord.end());

    int m = coord.size();
    // [captura](parâmetros) -> tipo_de_retorno
    // 1-indexado
    auto id = [&](int c) -> int {
        return lower_bound(coord.begin(), coord.end(), c) - coord.begin();
    };

    freq.assign(m, 0);

    for(auto [op,val]: qr){
        int idx = id(val);
        if(op == 'I'){
            if (freq[idx] == 0) {
                freq[idx] = 1;
                update(1, 0, m - 1, idx, 1);
            }
        }       
        else if(op == 'C'){
            cout << query(1, 0, m - 1, 0, idx - 1) << "\n";
        }   
        else if(op == 'K'){
            int total = tree[1];
            if (val > total) {
                cout << "invalid\n";
            } else {
                int pos = kth(1, 0, m - 1, val - 1);
                cout << coord[pos] << "\n";
            }
        }   
        else{ //D
            if (freq[idx] == 1) {
                freq[idx] = 0;
                update(1, 0, m - 1, idx, 0);
            }
        } 

    }

    return 0;
}