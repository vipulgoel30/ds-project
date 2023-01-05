#include <stdio.h>
#include <string.h>

void showAvaMovies()
{
  FILE *fp;
  fp = fopen("./data/movies/movies.txt", "r");
  int i = 1;
  while (!feof(fp))
  {
    char data[1400] = "";
    fgets(data, 1400, fp);
    if (data[0] == '@')
      continue;
    printf("%d. ", i);
    for (int i = 5; data[i] != '|'; i++)
      printf("%c", data[i]);

    printf("\n");
    i++;
  }
  fclose(fp);
}