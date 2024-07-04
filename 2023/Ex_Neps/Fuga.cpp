#include <iostream>

using namespace std;

int main() {
    int h, p, f, d;

    char fator = 'S'; // Definindo a variável de impressão como positiva

    // Lendo os valores de entrada
    cin >> h >> p >> f >> d;

    // É criado um ciclo infinito, mas as condições de encerramento estão presentes
    while (true) {
        // Caso saia do limite da roda, acerte o valor ao correspondente
        if(f == 16 && d == 1) f = 0;
        if(f == -1 && d == -1) f = 15;

        // Se a posição do fugitivo é igual ao do helicóptero, encerra-se o ciclo
        if(f == h) break;

        // Se a posição do fugitivo é igual ao do policial, muda-se a variável e encerra-se o ciclo
        if(f == p) {
            fator = 'N';
            break;
        }

        // Acrescenta ou diminui 1 a posição dependendo do sentido do fugitivo.
        if(d == 1) f++;
        if(d == -1) f--;
    }

    cout << fator << endl; // Imprimindo o resultado
}