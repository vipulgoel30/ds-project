// #include "./start/signUp/signUp.c"
// #include "./start/login/login.c"
// #include "./start/functions.c"

void start()
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
    case (1): // LOGIN
    {
      login();
      break;
    }
    case (2): // SIGN UP
    {
      signUp();
      break;
    }
    default:
      printf("Exiting .....\n");
    }
  } while (choice == 1 || choice == 2);
}