#include <stdio.h>
#include <string.h>
// #include "./start/operations/admin/adminOperationFunction.c"

int addMovie()
{
  char movieName[200] = "";
  char movieCode[5] = "";
  int price;
  int seats;
  char description[1000] = "";

  // MOVIE NAME
  printf("Enter the movie name : ");
  scanf(" %[^\n]%*c", movieName);

  // MOVIE CODE
  do
  {
    if (strlen(movieCode))
      printf("Enter valid movie code !\n");
    printf("Enter the movie code (4 char ) : ");
    scanf(" %s", movieCode);

    // Checking if the movie code already exists or not
    if (checkMoviesExist() == 0 && movieCodeExist(movieCode))
    {
      strcpy(movieCode, "");
      printf("The movie code already exists!\n");
    }
  } while (strlen(movieCode) != 4);

  // Ticket price
  printf("Enter the price : ");
  scanf(" %d", &price);

  // No of seats available
  printf("Enter the no of seats available : ");
  scanf(" %d", &seats);

  // Description about the movie
  printf("Enter the description about the movie : ");
  scanf(" %[^\n]%*c", description);

  FILE *fp, *ptr;
  char movieAddress[140] = "";
  createMovieFileAddress(movieCode, movieAddress);
  ptr = fopen(movieAddress, "a");

  if (ptr == NULL)
  {
    printf("There is error while adding the movie\n");
    return 0;
  }
  else
  {
    fp = fopen("./data/movies/movies.txt", "a");
    if (fp == NULL)
    {
      printf("Internal Error!\n");
      return 0;
    }
    fprintf(fp, "\n%s|%s|%d|%d|%s", movieCode, movieName, price, seats, description);
    fclose(fp);
    fprintf(ptr, "%s|%s|%d|%d|%s\n", movieCode, movieName, price, seats, description);
    fprintf(ptr, "%d\n", seats);
  }
  fclose(ptr);
  return 0;
}
