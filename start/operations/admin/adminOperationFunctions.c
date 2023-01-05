#include <stdio.h>
#include <string.h>

void createMovieFileAddress(char movieCode[5], char movieAddress[140])
{
  strcpy(movieAddress, "./data/movies/movie/");
  char endData[] = ".txt";
  strcat(movieAddress, movieCode);
  strcat(movieAddress, endData);
}

int movieCodeExist(char movieCode[5])
{
  FILE *fp;
  fp = fopen("./data/movies/movies.txt", "r");
  if (fp == NULL)
  {
    printf("Internal error!\n");
    return 501;
  }
  while (!feof(fp))
  {
    char data[1300] = "";
    char tempCode[5] = "";
    fgets(data, 1300, fp);
    for (int i = 0; i < 4; i++)
      tempCode[i] = data[i];
    if (strcmp(movieCode, tempCode) == 0)
    {
      return 1;
      fclose(fp);
    }
  }
  fclose(fp);
  return 0;
}
