#include <stdio.h>
#include <string.h>
int main()
{
  FILE *fp;
  fp = fopen("./test.txt", "r+");
  if (fp == NULL)
    printf("Error");
  while (!feof(fp))
  {
    char ch = fgetc(fp);
    if (ch == 'a')
    {
      fseek(fp, -1, SEEK_CUR);
      fputc('@', fp);
    }
  }
  printf("Done");
  fclose(fp);
}