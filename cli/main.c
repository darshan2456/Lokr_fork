#include <stdio.h>

#include "auth.h"
#include "vault.h"
#include "misc.h"

char password_buffer[60];
char username_buffer[60];
user_t user;

int main(int argc, char *argv[]) {

  // if no user file exists prompt to create a user
  if (F_exist("user.bin") != 0) {

    // Takes user credential
    printf("please create a user.\n");
    printf("Username : ");
    f_gets(username_buffer);

    printf("Password : ");
    f_gets(password_buffer);
    create_user(username_buffer, password_buffer);
  }

  // if no argument are specififed
  if (argc < 2) {
    // check credentials
    do {

      printf("Enter your username : ");
      f_gets(username_buffer);

      printf("Enter your password : ");
      f_gets(password_buffer);

    } while (authenticate(password_buffer, username_buffer) != 0);

    // save credential to a struct
    str_cpy(user.username, username_buffer);
    str_cpy(user.passwd, password_buffer);
  }

  // if arguments are specified
  else {
  printf("Runnig with argument : %s\n", argv[2]);
  }
  return 0;
}
