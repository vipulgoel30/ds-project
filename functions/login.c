#include <stdio.h>
#include "./admin/adminOperations/adminOperationFunction.c"
#include "./admin/adminOperations/addMovie.c"
#include "./admin/adminOperations/deleteMovie.c"

void login()
{
  printf("1.User Login\n2.Admin Login\n3.Previous Menu...\n");
  int loginChoice;
  printf("Enter the type of user you are : ");
  scanf("%d", &loginChoice);
  switch (loginChoice)
  {
  case (1): // USER LOGIN
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
  case (2): // ADMIN LOGIN
  {
    char phoneNo[11] = "";
    char password[21] = "";
    phoneNoInput(phoneNo, 1, 2);
    passwordInput(password);

    if (userValidator(phoneNo, password, 2) == 1)
    {
      printf("Successfully signed in!\n");
      int adminChoice;
      do
      {
        printf("1.Add a movie\n2.Delete a Movie\n3.Update movie\n4.Available Movies\n5.Logout....\n");
        printf("Enter the choice : ");
        scanf("%d", &adminChoice);
        switch (adminChoice)
        {
        case (1):
        {
          addMovie();
          break;
        }
        case (2):
        {
          deleteMovie();
          break;
        }
        case (3):
        {
          break;
        }
        case (4):
        {

          break;
        }
        default:
          printf("Enter the valid choice\n");
        }
      } while (adminChoice == 1 || adminChoice == 2 || adminChoice == 3 || adminChoice == 4);
    }
    else
    {
      printf("Either the PHONE NO or PASSWORD is incorrect!\n");
    }
    break;
  }
  default:
    printf("Enter the valid choice\n");
  }
}