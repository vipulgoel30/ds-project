#include "./functions.c"
void signUp()
{
  FILE *fp;
  fp = fopen("./data/user.txt", "a");
  char phoneNo[11];
  char password[20] = "";
  char name[51] = "";
  //  entering PHONE NO
  phoneNoInput(phoneNo, 0, 1);

  printf("Enter the USERNAME  : ");
  scanf("%s", name);

  //  entering PASSWORD
  passwordInput(password);
  fprintf(fp, "\n%s|%s|%s", phoneNo, password, name);

  fclose(fp);
}