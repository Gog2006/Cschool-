#include <stdio.h>
#include <stdlib.h>

void afficherTableau(int *tableau, int taille, const char *message) {
  printf("%s", message);
  printf("{");
  for (int i = 0; i < taille; i++) {
    printf("%d", tableau[i]);
    if (i < taille - 1) {
      printf(", ");
    }
  }
  printf("}\n");
}

int main() {
  /* Allocation dynamique d'un tableau de 10 entiers */
  int taille_initiale = 10;
  int *tableau = malloc(taille_initiale * sizeof *tableau);
  
  if (tableau == NULL) {
    fprintf(stderr, "Erreur: allocation mémoire échouée\n");
    return 1;
  }

  /* Remplir le tableau avec des valeurs de 0 à 9 */
  for (int i = 0; i < taille_initiale; i++) {
    tableau[i] = i;
  }

  /* Afficher le tableau avant redimensionnement */
  afficherTableau(tableau, taille_initiale, "Tableau avant redimensionnement (10 éléments) :\n");

  /* Redimensionner le tableau pour contenir 20 entiers */
  int nouvelle_taille = 20;
  int *nouveau_tableau = realloc(tableau, nouvelle_taille * sizeof *nouveau_tableau);
  
  if (nouveau_tableau == NULL) {
    fprintf(stderr, "Erreur: redimensionnement échoué\n");
    free(tableau);
    return 1;
  }
  
  tableau = nouveau_tableau;

  /* Remplir les 10 nouveaux emplacements avec -1 */
  for (int i = taille_initiale; i < nouvelle_taille; i++) {
    tableau[i] = -1;
  }

  /* Afficher le tableau après redimensionnement */
  afficherTableau(tableau, nouvelle_taille, "\nTableau après redimensionnement (20 éléments) :\n");

  /* Libération de la mémoire */
  free(tableau);

  return 0;
}
