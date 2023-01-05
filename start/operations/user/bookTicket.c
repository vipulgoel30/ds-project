#include <stdio.h>
#include <stdlib.h>
void bookTicket(char movieCode[5], char phoneNo[11])
{
  char movieAddress[140] = "";
  createMovieFileAddress(movieCode, movieAddress);
  int avalSeats = noAvalSeatsFind(movieAddress);
  if (avalSeats == 0)
    printf("No seats available!\n");

  else
  {
    printMovieDetails(movieCode);
    int continueBook;
    printf("Press 1 to confirm : ");
    scanf("%d", &continueBook);
    FILE *fp;
    fp = fopen(movieAddress, "a");

    char name[50] = "";
    int age;
    printf("Enter the name of the viewer : ");
    scanf(" %[^\n]%*c", name);

    printf("Enter the age of the viewer : ");
    scanf("%d", &age);
    fprintf(fp, "%s%d|%s|%s|%d\n", movieCode, avalSeats, phoneNo, name, age);
    printf("*****Thanks for trusting us******\n");
    printf("Your movie ticked code is : %s%d\n", movieCode, avalSeats);
    fclose(fp);
  }
  return;
}