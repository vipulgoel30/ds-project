#include <stdio.h>
void signUp()
{
  FILE *fp;
  fp = fopen("./data/user.txt", "a");
  char phoneNo[11];
  char password[20] = "";
  char name[51] = "";

  printf("Enter the following details to signUp \n");

  //  entering PHONE NO
  int phoneInputResult = phoneNoInput(phoneNo, 0, 1);

  // entering the USERNAME
  printf("Enter the USERNAME  : ");
  scanf(" %[^\n]%*c", name);

  //  entering PASSWORD
  int passInputReasult = passwordInput(password);

  // Checking whether to proceed entering data in a file or not
  if (passInputReasult && passInputReasult)
  {
    int temp = fprintf(fp, "%s|%s|%s\n", phoneNo, password, name);
    if (temp < 0)
    {
      printf("Unable to signUp \n");
    }
    else
      printf(" Welcome to PVG family \n");
    printf("Please login to continue\n");
  }
  else
    printf("Unable to signUp \n");
  fclose(fp);
}