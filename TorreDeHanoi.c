// É possível mover 1 disco de cada vez
// Um disco maior não pode ser colocado sobre um menor
// Os discos precisam ser movidos da haste de início para a de destino final

#include <stdio.h>

// Função recursiva responsável por resolver o problema
void TorreDeHanoi(int nD, char Hi, char Hf, char Intermediador) {
if (nD == 1) {
printf("Mover disco 1 da haste %c para %c\n", Hi, Hf);
return;
}

// Para mais de um disco utilizamos a função recursiva que move o (nD - 1) para a haste intermediária, o disco seguinte para o destino e posteriormente o (nD - 1) para o destino
TorreDeHanoi(nD - 1, Hi, Intermediador, Hf);
printf("Mover disco %d da haste %c para %c\n", nD, Hi, Hf);
TorreDeHanoi(nD - 1, Intermediador, Hf, Hi);
}

int main() {

    int nD;

    printf("Informe quantos discos serão utilizados: \n");
    scanf("%i", &nD);

    TorreDeHanoi(nD, 'I', 'F', 'M');

    return 0;
}