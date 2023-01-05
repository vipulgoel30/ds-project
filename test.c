#include <stdio.h>
#include <string.h>
int main()
{
  FILE *fp;
  fp = fopen("./test.txt", "r");
  fputc('\n', fp);
  while (!feof(fp))
  {
    printf("%c", fgetc(fp));
  }
}