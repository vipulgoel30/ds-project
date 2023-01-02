#include "./functions.c"
void signUp()
{
  FILE *fp;
  fp = fopen("./data/user.txt", "a");
  char phoneNo[11];
  char password[20] = "";
  char name[51] = "";
  phoneNoInput(phoneNo, 0, 1);
  // printf("%s", phoneNo);
  // TODO entering PHONE NO
  // do
  // {
  //   if (strlen(phoneNo) != 0)
  //     printf("Please enter the valid phone no.\n");
  //   printf("Enter the phone no : ");
  //   scanf("%s", phoneNo);
  //   if (checkUserExist(phoneNo, NULL))
  //   {
  //     printf("User already exists!!!!!\n");
  //     strcpy(phoneNo, "");
  //   }
  // } while (strlen(phoneNo) != 10);

  // entering USERNAME
  printf("Enter the USERNAME  : ");
  scanf("%s", name);

  // TODO entering PASSWORD
  passwordInput(password);
  fprintf(fp, "%s|%s|%s\n", phoneNo, password, name);

  fclose(fp);
}