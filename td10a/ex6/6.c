#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* entreeUtilisateur(int taille) {
  char* buffer = malloc(taille * sizeof *buffer);
  if (buffer == NULL) {
    fprintf(stderr, "Erreur allocation mémoire échouée\n");
    exit(1);
  }
  printf("%s", "Entrez une chaîne de caractères : ");
  if (fgets(buffer, taille, stdin) == NULL) {
    fprintf(stderr, "Erreur lecture entrée utilisateur\n");
    free(buffer);
    exit(1);
  }
  return buffer;
}

int main() {
  int taille = 127;
  char* buffer = entreeUtilisateur(taille);
  char* copie = strdup(buffer);

  printf("Vous avez entré %d caractères : \n%s\n", taille, buffer);
  
  free(copie);
  free(buffer);
  
  return 0;
}