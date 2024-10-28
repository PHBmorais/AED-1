// Resolver o jogo do Sudoku
// Utiliza-se números de 0 a 9
// Uma linha não pode ter números repetidos
// Uma coluna não pode ter números repetidos
// Um bloco 3x3 não pode ter números repetidos (temos 9 blocos)

#include <stdio.h>

// Função para verificar se a linha é válida
int VerificarLinha(int matriz[9][9], int linha) {
    int n, j;
    int listaN[10] = {0};
    
    // Percorre o slot da coluna de acordo com a linha em questão
    for(j = 0; j < 9; j++) {
        n = matriz[linha][j];
        
        // Verifica se o número está no intervalo permitido pelo jogo
        if(n < 1 || n > 9 ) {
            
            return 0;
        }
        
        // Verifica se esse número já existe na linha
        if(listaN[n - 1] == 1) {
            
            return 0;
        }
        
        listaN[n - 1] = 1;
    }

    return 1;
}

// Função para verificar se a coluna é válida
int VerificarColuna(int matriz[9][9], int coluna) {
    int n, i;
    int listaN[10] = {0};

    // Percorre o slot da linha de acordo com a coluna em questão
    for(i = 0; i < 9; i++) {
        n = matriz[i][coluna];

        // Verifica se o número está no intervalo permitido pelo jogo
        if(n < 1 || n > 9 ) {
            
            return 0;
        }

        // Verifica se esse número já existe na coluna
        if(listaN[n - 1] == 1) {
            
            return 0;
        }

        listaN[n - 1] = 1;
    }

    return 1;
}

// Função para verificar se a matriz 3x3 é válida
int VerificarMatriz3x3(int matriz[9][9], int Ilinha, int Icoluna) {
    int i, j, n;
    int listaN[10] = {0};

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            n = matriz[Ilinha + i][Icoluna + j];
            if(n != 0) {
                if(listaN[n] == 1) {
                    
                    return 0;
                }
            
            listaN[n] = 1;
            }
        }
    }

    return 1;
}

// Função para verificar se a matriz 9x9 do Sudoku é válida
int VerificarSudoku(int matriz[9][9]) {
    int a, i, j;

    for(a = 0; a < 9; a++) {
        if(!VerificarLinha(matriz, a) || !VerificarColuna(matriz, a)) {

            return 0;
        }
    }

    for (i = 0; i < 9; i += 3) {
        for (j = 0; j < 9; j += 3) {
            if (!VerificarMatriz3x3(matriz, i, j)) {

                return 0;
            }
        }
    }

    return 1;
}

int main() {
    int nMatrizes;
    int b, i, j;
    
    scanf("%d", &nMatrizes);

    for (b = 1; b <= nMatrizes; b++) {
        int matriz[9][9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }

        printf("Instancia %d\n", b);

        if (VerificarSudoku(matriz)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }

        printf("\n");
    }

    return 0;
}