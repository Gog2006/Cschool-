#include <stdio.h>
#include <stdlib.h>

int main() {
  int taille = 20;
  int *tableau = malloc(taille * sizeof *tableau);

  if (tableau == NULL) {
    fprintf(stderr, "Erreur: allocation mémoire échouée\n");
    return 1;
  }

  for (int i = 0; i < taille; i++) {
    tableau[i] = i * i;
  }

  for (int i = 0; i < taille; i++) {
    printf("tableau[%d] = %d\n", i, tableau[i]);
  }
  /* libération de la mémoire allouée */
  free(tableau);

  return 0;
}