#include "functions_sort.h"
void swap(char array[], unsigned int lIndex, unsigned int rIndex) {
   char tmp = array[lIndex];
   array[lIndex] =  array[rIndex];
   array[rIndex] =  tmp;
}
void bubble_sorte(char *buffer, unsigned int size) {
  for(int i = 0; buffer[i] != '\0'; i++) {
      for(int j=i+1; buffer[j] != '\0'; j++) {
          if (buffer[i] > buffer[j]) {
              swap(buffer, i, j);
          }
      }
  }
}
void select_sorte(char *buffer, unsigned int size) {
  unsigned int jIndex = 0;
  char min;
  for (int i = 0; buffer[i] !='\0'; i++) {
    min = buffer[i];
    jIndex = i;
    for (int j = i + 1; buffer[j] !='\0'; j++) {
      if (min > buffer[j]) {
        jIndex = j;
        min = buffer[j];
      }
    }
    swap(buffer,i,jIndex);
  }
}
// будет "стенка", сортировать до неё
// strcat '|'
void insert_sorte(char *buffer, unsigned int size) {

    unsigned int cursor = 2;
    for(int i = 0; i < cursor; i++) {
        for(int j=i+1; j < '\0'; j++) {
            if (buffer[i] < buffer[j]) {
                swap(buffer, i, j);
            }
            printf("%s\n", buffer);
        }
//        if (cursor < 1024) {
          ++cursor;
//        }
    }

  printf("\n%s\n", buffer);
}
