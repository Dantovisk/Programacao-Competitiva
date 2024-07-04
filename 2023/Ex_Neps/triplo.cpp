#include <iostream>

using namespace std;

long totalNumeros;
long vetorNumeros[200002];

long long maior1;
long long maior2;

int main(){

  cin >> totalNumeros;

  for(int i = 0; i < totalNumeros; i++)
    cin >> vetorNumeros[i];

  maior1 = vetorNumeros[totalNumeros - 1] * vetorNumeros[totalNumeros - 2] * vetorNumeros[totalNumeros - 3];

  maior2 = vetorNumeros[0] * vetorNumeros[1] * vetorNumeros[totalNumeros - 1];

  cout << max(maior1, maior2) << '\n';

  return 0;
}