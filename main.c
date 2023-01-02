#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./functions/signup.c"
// struct user
// {
//   char phoneNo[11];
//   char password[21];
//   char name[51];
//   struct user *link;
// };
int main()
{
  printf("*************************\n");
  printf("Welcome to 'PVG' Bookings\n");
  printf("*************************\n");
  int choice;
  do
  {
    printf("1.Login\n2.SignUp\n3.Exit.....\n");
    printf("Enter the choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case (1):
    {
      printf("1.User Login\n2.Admin Login\n3.Previous Menu...\n");
      int loginChoice;
      printf("Enter the type of user you are : ");
      scanf("%d", &loginChoice);
      switch (loginChoice)
      {
      case (1):
      {
        char phoneNo[11] = "";
        char password[21] = "";
        phoneNoInput(phoneNo, 1, 1);
        passwordInput(password);

        if (userValidator(phoneNo, password, 1) == 1)
          printf("Successfully signed in!\n");
        else
        {
          printf("Either the PHONE NO or PASSWORD is incorrect!\n");
        }
        break;
      }
      case (2):
      {
        char phoneNo[11] = "";
        char password[21] = "";
        phoneNoInput(phoneNo, 1, 2);
        passwordInput(password);

        if (userValidator(phoneNo, password, 2) == 1)
          printf("Successfully signed in!\n");
        else
        {
          printf("Either the PHONE NO or PASSWORD is incorrect!\n");
        }
        break;
      }
      default:
        printf("Enter the valid choice\n");
      }
      break;
    }
    case (2):
    {
      signUp();
      break;
    }
    default:
      printf("Exiting .....\n");
    }
  } while (choice == 1 || choice == 2);
}