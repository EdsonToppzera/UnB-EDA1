#include <stdio.h>
#include <string.h>

struct Livro {
    char titulo[100];
    char autor[50];
    int publicacao;
    int paginas;
};

int main() {
  struct Livro mushoku;
  struct Livro marvel;

  strcpy(mushoku.titulo, "Mushoku");
  strcpy(mushoku.autor, "Rifujin no Magonote");
  mushoku.publicacao = 2013;
  mushoku.paginas = 6000;

  strcpy(marvel.titulo, "marvel");
  strcpy(marvel.autor, "Brothers");
  marvel.publicacao = 1915;
  marvel.paginas = 600000;

  printf("Marvel paginas: %d\n", marvel.paginas);
  printf("Autor mushoku: %s\n", mushoku.autor);

  return 0;
}