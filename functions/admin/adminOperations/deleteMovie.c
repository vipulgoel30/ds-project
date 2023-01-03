#include <stdio.h>
#include <string.h>

int deleteMovie()
{
  char movieCode[5];
  printf("Enter the movie code you want to delete : ");
  scanf("%s", movieCode);

  if (movieCodeExist(movieCode) == 0)
    printf("Movie code do not exist!!!!\n");
  else
  {
    char movieAddress[140] = "";
    createMovieFileAddress(movieCode, movieAddress);
    FILE *fp;
    fp = fopen(movieAddress, "w");
    if (fp == NULL)
    {
      printf("Unable to delate movie!\n");
      fclose(fp);
      return 0;
    }
    else
    {
      printf("Successfully deleted the movie!");
      while (!feof(fp))
      {
        printf("%c", fgetc(fp));
      }
    }
    fclose(fp);
  }
}