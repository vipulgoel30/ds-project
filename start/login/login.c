// #include <stdio.h>

// #include "./start/login/user/login.c"
// #include "./start/login/admin/login.c"

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
    userLogin();
    break;
  }
  case (2): // ADMIN LOGIN
  {
    adminLogin();
    break;
  }
  default:
    printf("Enter the valid choice\n");
  }
}