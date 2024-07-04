//A busca binaria é um algoritmo que realiza buscas em arrays ordenados
//Possui complexidade O(log(n)), menor do que se fosse buscado em todos os elementos O(n)
//Se trata de dar grandes passos em busca do termo e ir diminuindo cada vez mais
//Até encontrar o termo ou ver que não existe.

/*
    EXEMPLO:

    int k = 0;
    for (int b = n/2; b >= 1; b /= 2) {
    while (k+b < n && array[k+b] <= x) k += b;
    }
    if (array[k] == x) {
        // x found at index k
    }
*/

//O C++ possui as funções upper_bound (a<b), lower_bound (a<=b) e equal_range (retorna os 2 ponteiros)
//baseadas no Binary Search

/* 
    Procura se o termo existe no array:

    auto k = lower_bound(array,array+n,x)-array;
    if (k < n && array[k] == x) {
        // x found at index k
    }

    Retorna o numero de elementos iguais ao procurado:

    auto a = lower_bound(array, array+n, x);
    auto b = upper_bound(array, array+n, x);
    cout << b-a << "\n";

    Maneira simplificada:
    
    auto r = equal_range(array, array+n, x);
    cout << r.second-r.first << "\n";
*/