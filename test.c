#include <stdio.h>
#include <string.h>
int main()
{
  char test[20];
  strcpy(test, "");
  printf("%d", strlen(test));
  return 0;
}