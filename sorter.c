//
#include <stdio.h>
#include <cstdlib>
#include <unistd.h>
#include <string.h>
/////////////////////////////////////
char buffer[1024], t, leftSection[1024],/*rightSection[]*/
     minNum[1];
int num_of_chars = 0, sorte;
bool correctInput = false;
/////////////////////////////////////
void bubble_sorte(),
     select_sorte(),
     insert_sorte();
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
/////////////////////////////////////
void bubble_sorte() {
  for(int i = 0; buffer[i] != '\0'; i++)
  {
      for(int j=i+1; buffer[j] != '\0'; j++)
      {
          if (buffer[i] > buffer[j])
          {
              t = buffer[i];
              buffer[i] = buffer[j];
              buffer[j] = t;
          }
      }
  }
}
void select_sorte() {
  for (int i = 0; buffer[i] !='\0'; i++) {
    for (int j = i + 1; buffer[i] !='\0'; j++) {
      if (buffer[i] < buffer[j]) {
        minNum[1] = buffer[i];
      }
    }
    strcat(leftSection, minNum);
    buffer[i] = '\0';
  }
  strcpy(buffer, leftSection);
}
void insert_sorte() {

}
