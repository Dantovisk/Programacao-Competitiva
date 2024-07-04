#include <iostream>

#define MAX 1010

// Declarando as variáveis com o valor máximo da restrição
int m[MAX][MAX];
int l[MAX], c[MAX];

using namespace std;

int main() {
  int N, maxi = -101010;

  cin >> N;

  // Lendo os valores da matriz
  for(int i = 1; i <= N; i++)
    for(int j = 1; j <= N; j++) {
      cin >> m[i][j];
      l[i] += m[i][j]; // Somando o elemento em sua respectiva linha
      c[j] += m[i][j]; // Somando o elemento em sua respectiva coluna
    }

  // Percorrendo toda a matriz, calculando o peso de todos os elementos
  for(int i = 1; i <= N; i++)
    for(int j = 1; j <= N; j++)
      // Caso o peso do elemento for maior que o da variável, tal peso é atribuído a el
      maxi = max(maxi, l[i] + c[j] - 2*m[i][j]);
  
  cout << maxi << endl;
}