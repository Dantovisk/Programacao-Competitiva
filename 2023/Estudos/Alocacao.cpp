#include <stdio.h>
#include <stdlib.h> //alocação
#include <iostream>

int main(){
    int *p;  //criando um ponteiro pra p
    p = (int*) malloc(sizeof(int)*2);   // alocando tamanho de duas ints na memória
    //  (int*) define que o tipo de dado do ponteiro é int
    
    p[0]=4;  //equivalente a *(p) = 4;
    *(p+1)=5;  //equivalente a  p[1] = 5;

    std::cout << p[0]<< " " << *(p+1); //printa as duas ints no ponteiro p

    free(p); //libera a memória que foi alocada em p


}