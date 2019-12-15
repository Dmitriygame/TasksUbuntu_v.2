#include <stdio.h>
int main (int argc, char *argv[])
{
  char buffer[1024], t;
  int num_of_chars = 0;
  FILE *Input, *Output;
  Input = fopen(argv[1], "r");
  fscanf(Input, "%s", &buffer);
  fclose(Input);
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
  Output = fopen("Output.txt", "w");
  fprintf(Output, "%s", buffer);
  fclose(Output);
  return 0;
}
