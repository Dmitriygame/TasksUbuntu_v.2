#include "functions_sort.h"

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
    for (int j = i + 1; buffer[j] !='\0'; j++) {
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
