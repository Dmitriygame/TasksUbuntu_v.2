#pragma once
#include <string.h>

char buffer[1024], t, leftSection[1024],/*rightSection[]*/
     minNum[1];
void swap(char array[], unsigned int lIndex, unsigned int rIndex);
void bubble_sorte(char *buffer, unsigned int size);
void select_sorte(char *buffer, unsigned int size);
void insert_sorte(char *buffer, unsigned int size);
