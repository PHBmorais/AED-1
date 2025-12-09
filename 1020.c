#include <stdio.h>

int main() {
    int dias;
    
    // Lê a idade em dias
    scanf("%d", &dias);
    
    // Calcula anos
    int anos = dias / 365;
    dias = dias % 365;
    
    // Calcula meses
    int meses = dias / 30;
    dias = dias % 30;
    
    // Os dias restantes
    int dias_restantes = dias;
    
    // Imprime o resultado
    printf("%d ano(s)\n", anos);
    printf("%d mes(es)\n", meses);
    printf("%d dia(s)\n", dias_restantes);
    
    return 0;
}