#include <stdio.h>
#include <string.h>
#include <stdlib.h> //for atoi function
#include <math.h>

#include "./start/functions.c"
#include "./start/operations/admin/adminOperationFunctions.c"
#include "./start/operations/admin/addMovie.c"
#include "./start/operations/admin/deleteMovie.c"
#include "./start/operations/admin/showAvaMovies.c"
#include "./start/login/adminLogin.c" //ADMIN login
#include "./start/operations/user/userOperationFunctions.c"
#include "./start/operations/user/bookTicket.c"
#include "./start/login/userLogin.c" //USER login
#include "./start/login/login.c"     //LOGIN
#include "./start/signUp.c"          //SIGNUP
#include "./start/start.c"           //START

int main()
{
  start();
  return 0;
}
