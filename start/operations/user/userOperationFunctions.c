

int noAvalSeatsFind(char movieAddress[140])
{
  FILE *fp;
  fp = fopen(movieAddress, "r");

  char data[1400] = "";
  fgets(data, 1400, fp);
  char totalSeats[4] = "";
  fgets(totalSeats, 4, fp);
  int totalSeatsInt = atoi(totalSeats);
  int count = 0;
  while (!feof(fp))
  {
    fgets(data, 500, fp);
    count++;
  }
  return totalSeatsInt - count + 2;
}

void getMovieCode(int movieNo, char movieCode[])
{
  FILE *fp;
  fp = fopen("./data/movies/movies.txt", "r");
  char data[1400] = "";
  for (int i = 0; i < movieNo; i++)
  {
    fgets(data, 1400, fp);
    if (data[0] == '@')
      i--;
  }
  fclose(fp);
  for (int i = 0; i < 4; i++)
    movieCode[i] = data[i];
}

void printMovieDetails(char movieCode[])
{
  char movieAddress[140] = "";
  char data[1400] = "";
  createMovieFileAddress(movieCode, movieAddress);
  FILE *fp;
  fp = fopen(movieAddress, "r");

  fgets(data, 1400, fp);
  int i = 0;

  // getting MOVIE CODE
  printf("Movie code : ");
  for (; data[i] != '|'; i++)
    printf("%c", data[i]);
  printf("\n");
  i++;

  // getting MOVIE NAME
  printf("Movie Name : ");
  for (; data[i] != '|'; i++)
    printf("%c", data[i]);
  printf("\n");
  i++;

  // getting MOVIE FARE
  printf("Movie ticket price : ");
  for (; data[i] != '|'; i++)
    printf("%c", data[i]);
  printf("\n");
  i++;

  // getting NO OF SEATS
  printf("No of seats are there : ");
  for (; data[i] != '|'; i++)
    printf("%c", data[i]);
  printf("\n");
  i++;

  // getting DESCRIPTION
  printf("Description about the movie : ");
  for (; data[i] != '\0'; i++)
    printf("%c", data[i]);
  i++;

  printf("No of seats avaialable : ");

  printf("%d", noAvalSeatsFind(movieAddress));
  printf("\n");
}
