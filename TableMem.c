#include <stdio.h>
#define N 5

int main() {
    int table[N] = {12, 7, 25, 3, 15};
    int somme = 0, max = table[0], min = table[0];

    // Parcours et traitement
    for (int i = 0; i < N; i++) {
        somme += table[i];
        if (table[i] > max) max = table[i];
        if (table[i] < min) min = table[i];
    }

    printf("Somme = %d\n", somme);
    printf("Moyenne = %.2f\n", (float)somme / N);
    printf("Max = %d\n", max);
    printf("Min = %d\n", min);

    return 0;
}
