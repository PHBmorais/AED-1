#include <stdio.h>

// Calcular a área de uma circuferência (pi = 3.14159)
int main() {
 
    double n;
    double area;
    double raio;
    
    n = 3.14159;
    
    scanf("%lf", &raio);
    
    area = (raio*raio) * n;
    
    printf("A=%.5f\n", area);
 
    return 0;
}