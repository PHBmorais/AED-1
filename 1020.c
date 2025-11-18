#include <stdio.h>
 
// Pedir a idade de uma pessoa em dias, e a partir dessa informação, informar ela em anos, meses e dias
int main() {
    
    int idade, anos, meses,dias;
    
    scanf("%d", &idade);
       
    // Descobrir os anos
    anos = idade / 365;
    // Pegar o resto da divisão por ano
    idade = idade % 365;
    // Descobrir os meses
    meses = idade / 30;
    // Pegar o resto da divisão por mês e descobrir dias
    dias = idade % 30;
       
    printf("%d ano(s)\n", anos);
    printf("%d mes(es)\n", meses);
    printf("%d dia(s)\n", dias);
    
    return 0;
   }
