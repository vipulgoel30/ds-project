void userLogin()
{
  char phoneNo[11] = "";
  char password[21] = "";
  phoneNoInput(phoneNo, 1, 1);
  passwordInput(password);

  if (userValidator(phoneNo, password, 1) == 1)
  {
    printf("Successfully signed in!\n");
    if (checkMoviesExist() == 1)
    {
      printf("No movies exist right now!!!!\n");
      return;
    }
    int userChoice;
    do
    {
      printf("1.List of available Movies\n2.Information about the movie and to check availability\n3.Book a movie ticket\n4.Logout....\n");
      printf("Enter the choice : ");
      scanf("%d", &userChoice);
      switch (userChoice)
      {
      case (1):
      {
        showAvaMovies();
        break;
      }
      case (2):
      {
        showAvaMovies();
        int movieNo;
        printf("Enter the movie for which you want to check avaialability : ");
        scanf("%d", &movieNo);
        char movieCode[5] = "";
        getMovieCode(movieNo, movieCode);
        printMovieDetails(movieCode);
        break;
      }
      case (3):
      {
        showAvaMovies();
        char movieCode[5] = "";
        do
        {
          if (strlen(movieCode) != 0)
            printf("Please enter the movie code carefully! \n");
          printf("Enter the movie code for which you want to book ticket : ");
          scanf("%s", movieCode);
        } while (movieCodeExist(movieCode) != 1);
        bookTicket(movieCode, phoneNo);
        break;
      }
      default:
        start();
        printf("Logout");
      }
    } while (userChoice != 4);
  }
  else
  {
    printf("Either the PHONE NO or PASSWORD is incorrect!\n");
  }
}