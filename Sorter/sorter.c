//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#include "functions_sort.h"
/////////////////////////////////////
int num_of_chars = 0, sorte;
bool correctInput = false;
/////////////////////////////////////
int main (int argc, char *argv[])
{
  if ( argc != 2 ) {
    printf("Incorrect path!\n");
    return 0;
  }
  while (correctInput == false) {
    system ("clear");
    printf("What sort to use?\n");
    printf("1. Bubble\n2. Select\n3. Insert\n");
    scanf("%d", &sorte);
    if (sorte >= 1 || sorte <= 3) {
      correctInput = true;
    }
    else {
      printf("Input error!\n");
      sleep(2);
    }
  }
  FILE *Input, *Output;
  Input = fopen(argv[1], "r");
  fread(&buffer, sizeof(char), 1024, Input);
  fclose(Input);
  switch (sorte) {
    case 1:
      bubble_sorte ();
      break;
    case 2:
      select_sorte();
      break;
    case 3:
      insert_sorte();
      break;
  }
  Output = fopen("Output.txt", "w");
  fprintf(Output, "%s", buffer);
  fclose(Output);
  return 0;
}
