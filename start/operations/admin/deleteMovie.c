#include <stdio.h>
#include <string.h>
// #include "./start/operations/admin/adminOperationFunction.c"

void deleteMovie()
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
      printf("Unable to delete movie!\n");
      return;
    }
    else
    {
      // Adding the movies in deleted movies list
      FILE *del;
      del = fopen("./data/movies/delete.txt", "a");
      fprintf(del, "%s\n", movieCode);
      fclose(del);
      FILE *ptr;
      ptr = fopen("./data/movies/movies.txt", "r+");
      while (!feof(fp))
      {
        char data[1300] = "";
        char tempCode[5] = "";
        fgets(data, 1300, ptr);
        for (int i = 0; i < 4; i++)
          tempCode[i] = data[i];
        if (strcmp(movieCode, tempCode) == 0)
        {

          fseek(ptr, -3, SEEK_CUR);
          while (fgetc(ptr) != '\n')
          {
            fseek(ptr, -1, SEEK_CUR);
            fputc('@', ptr);
            fseek(ptr, -2, SEEK_CUR);
          }
          break;
        }
      }
      fclose(ptr);
      fclose(fp);
    }
  }
}