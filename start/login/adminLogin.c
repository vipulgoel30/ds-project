
void adminLogin()
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
      printf("1.Add a movie\n2.Delete a Movie\n3.Available Movies\n4.Logout....\n");
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
        if (checkMoviesExist() == 1)
        {
          printf("Please enter the movie records first!\n");
          continue;
        }
        deleteMovie();
        break;
      }
      case (3):
      {
        if (checkMoviesExist() == 1)
        {
          printf("Please enter the movie records first!\n");
          continue;
        }
        showAvaMovies();
        break;
      }
      case (4):
      {
        start();
        break;
      }
      default:
        printf("Enter the valid choice\n");
      }
    } while (adminChoice != 4);
  }
  else
  {
    printf("Either the PHONE NO or PASSWORD is incorrect!\n");
  }
}