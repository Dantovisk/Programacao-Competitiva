#include <bits/stdc++.h>
using namespace std;

string a,b;
int pd[26][26];

// Função para calcular a distância de edição
int ed(int i, int j){  //programação dinâmica, método recursivo
  if(i == 0) return j;
  if(j == 0) return i; //se forem 0 já retorna o valor do outro
  if(pd[i][j] != -1) return pd[i][j];
  // Recursão e atualização da tabela dp
  return pd[i][j] = min(
    ed(i-1,j-1) + (a[i-1] == b[j-1] ? 0 : 1), //a[i-1] é igual a b[j-1]? Se sim, vale 0, se não, vale 1
    min( ed(i-1,j)+1, ed(i,j-1)+1 )
  );
}

int main() {

  char s[30];
  vector<string> v;
  int n,m; 
  cin>>n>>m;
  // Ler palavras do dicionário
  for(int i=0; i<n; i++){
    cin>>s; 
    v.push_back(string(s));
  }
  // Ler palavras do usuário e calcular a distância de edição
  while(m--){
    cin>>s; 
    a = string(s);
    int f = 0;
    for(int i=0; i<n; i++){
      b = v[i];
      memset(pd,-1,sizeof pd); //todos os valores de pd virarão -1
      // Se a distância de edição for <= 2, imprima a palavra do dicionário
      if(ed(a.size(), b.size()) <= 2)
        cout<<(f++ ? " " : "")<< b.c_str(); //f é maior q 0? se sim, coloca um espacinho
    }
    cout<<endl;
  }  
}
