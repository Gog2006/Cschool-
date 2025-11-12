#include <stdio.h>
#include <stdlib.h>


int *tableauScanfTaille(int taille) {
  int *tableau = malloc(taille * sizeof *tableau);
  if (tableau == NULL) {
    fprintf(stderr, "Erreur allocation mémoire échouée\n");
    exit(1);
  }
  for (int i = 1; i < taille+1; i++) {
    printf("Entrez la valeur pour l'élément %d: \n", i);
    if (scanf("%d", &tableau[i]) != 1) {
      fprintf(stderr, "Erreur valeur invalide\n");
      free(tableau);
      exit(1);
    }
  }
  return tableau;
}
void afficherTab(int* tab, int taille) {
    printf("{");
  for (int i = 0; i < taille; i++) {
    printf("%d", tab[i]);
    if (i < taille - 1) {
      printf(", ");
    }
  }
  printf("}\n");
}


int main() {
  int taille = 5;
  printf("Entrez les elements: \n");
  int* tableau = tableauScanfTaille(taille);
  afficherTab(tableau, taille);

  free(tableau);

  return 0;
}