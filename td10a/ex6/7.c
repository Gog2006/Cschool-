#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* entreeUtilisateur(int taille) {
  char* buffer = malloc(taille * sizeof *buffer);
  if (buffer == NULL) {
    fprintf(stderr, "Vous avez depasse la taille maximale definie par vous \n");
    exit(1);
  }

  printf("Entrez une chaîne de caractères (max %d caracteres) : ", taille);
  if (fgets(buffer, taille, stdin) == NULL) {
    fprintf(stderr, "Erreur lecture entrée utilisateur\n");
    free(buffer);
    exit(1);
  }
  return buffer;
}

int main() {
  int taille;
  printf("Entrez la taille maximale de la chaine  : ");
  if (scanf("%d", &taille) != 1 ) {
    fprintf(stderr, "Erreur: taille invalide\n");
    exit(1);
  }
  
  scanf("%*c");
  
  char* buffer = entreeUtilisateur(taille);
  char* copie = strdup(buffer);

  printf("Vous avez entré %d caractères : \n%s\n", taille, buffer);
  
  free(copie);
  free(buffer);
  
  return 0;
}