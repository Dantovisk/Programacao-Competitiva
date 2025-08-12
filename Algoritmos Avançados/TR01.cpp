#include <bits/stdc++.h> //Dante Brito Lourenço - 15447326

using namespace std;

// Implementação de uma trie estática 
// (Considerando que o tamanho e número das palavras é pequeno)
struct Trie
{
    int quantNodes;
    // Os nós da trie são numerados 0, 1, 2... e a raiz é 0
    // trie[s][c] retorna o próximo nó a partir do nó s dado o caractere c
    // c: 0 = 'A', 1 = 'B', ... , 25 = 'Z' (Assumindo que há só maiúsculas)

    // Como só precisamos verificar se as palavras do dicionário 
    // estão contidas no caça palavras, não estamos marcando onde as palavras terminam
    vector<array<int,26>> trie;

    Trie(int maxNodes) {
        trie.resize(maxNodes);
        for (auto &node : trie) node.fill(-1);
        quantNodes = 1;
    }

    //Insere uma string str na trie
    void insertString(string str){

        int currNode = 0;
        for (auto c : str){
            if(c < 'A' || c > 'Z') return; // Verifica se o caractere é válido
            if(trie[currNode][c-'A'] == -1){
                // O caractere atual ainda não existe, então o insere
                // e atualiza a quantidade de nós
                trie[currNode][c-'A'] = quantNodes++;
            }
            currNode = trie[currNode][c-'A']; //Atualiza o nó atual
        }
    }


    // Retorna true se a string foi encontrada na trie, false caso contrário
    bool prefixExists(string str){
        int currNode = 0;
        for (auto c : str){
            if(trie[currNode][c-'A'] == -1){
                // O caractere atual não está na trie
                return false;
            }
            currNode = trie[currNode][c-'A']; //Atualiza o nó atual
        }

        // Encontrou todos os caracteres de str
        return true;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;

    /*
    Contagem de nós máximos:
    Pontos de partida = 50*50 = 2500
    Para cada ponto de partida temos 2 linhas diagonais, 1 horizontal e 1 vertical,
    que somam no máximo 200 caracteres => 2500 * 200 = 500000 
    (Na prática é bem menos, mas por seguraça foi alocado essa quantidade)
    */
    Trie trie(500000);

    vector<string> grid(n);
    for(int i =0; i<n; i++){
        cin>>grid[i];
    }

    int currNode = 0;

    //Direções possíveis para encontrar palavras no caça-palavras
    int dir[8][2] = {{0,1}, {0,-1}, {1, 0}, {-1,0},
        {1, 1}, {1, -1}, {-1, 1}, {-1,-1}};

    //Estamos iterando pelo ponto de partida no grid.
    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            // Pegaremos as 8 strings que começam no ponto de partida
            // E vão até a borda do grid, nas 8 direções
            
            for(auto [dx, dy]: dir){
                string substr = ""; 
                int x = i, y = j;
                
                // Verifica se ainda não saímos do grid
                while(x >=0 && y >= 0 && x <n && y <m){
                    substr += grid[x][y]; //adiciona o caractere da posição atual           

                    //Calcula a próxima posição
                    x += dx;
                    y += dy;
                }
                trie.insertString(substr);
            }
        }
    }

    int dictSz;
    cin>>dictSz;

    // Buscando as palavras do dicionário
    // A resposta deve ser dada em ordem alfabética
    // Aparentemente não pode ter duplicatas
    set<string> foundWords;
    while(dictSz--){
        string str;
        cin>>str;

        if(trie.prefixExists(str)){
            foundWords.insert(str);
        }
    }

    cout<<foundWords.size()<<"\n";
    for(auto word: foundWords) cout<<word<<"\n";

    return 0;
}