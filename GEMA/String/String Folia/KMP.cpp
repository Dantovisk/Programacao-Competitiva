//dada uma string e um padrao p, o kmp encontra
//as ocorrencias desse agoritmo

//kmp cria o vetor pi
//pi[i] = maior prefixo de p que termina em i (que não seja o próprio p)

//seja p = "abacabab"
//pi = {0,0,1,0,1,2,3,2}

//basicamente estamos vendo se dá pra incrementar o maior sufixo
//ou se precisa buscar anteriores
//pi[i] = p[i-1]
//while(pi[i] > 0 and s[i] != pi[i])
//  pi[i] = pi[pi[i]-1]
//if(s[i] ==  s[pi[i]]) pi[i]++
//suffix link = proximo maior prefico de p que termina em i

//temos o kmp automata
//é uma ferramenta para comparar com um stream
//de caracteres online
//next(u, c) -> proximo estado