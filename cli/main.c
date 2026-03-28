#include <stdio.h>
#include <string.h>

#include "auth.h"
#include "vault.h"

char password_buffer[60];
char username_buffer[60];
user_t user;

int main(int argc, char *argv[]) {

  // if no user file exists prompt to create a user
  if (F_exist("user.bin") != 0) {

    // Takes user credential
    printf("please create a user.\n");
    printf("Username : ");
    fgets(username_buffer, sizeof(username_buffer), stdin);
    username_buffer[strcspn(username_buffer, "\n")] = '\0';

    printf("Password : ");
    fgets(password_buffer, sizeof(password_buffer), stdin);
    password_buffer[strcspn(password_buffer, "\n")] = '\0';
    create_user(username_buffer, password_buffer);
  }

  // if no argument are specififed
  if (argc < 2) {
    // check credentials
    do {

      printf("Enter your username : ");
      fgets(username_buffer, sizeof(username_buffer), stdin);
      username_buffer[strcspn(username_buffer, "\n")] = '\0';

      printf("Enter your password : ");
      fgets(password_buffer, sizeof(password_buffer), stdin);
      password_buffer[strcspn(password_buffer, "\n")] = '\0';

    } while (authenticate(password_buffer, username_buffer) != 0);

    // save credential to a struct
    strncpy(user.username, username_buffer, sizeof(user.username) - 1);
    user.username[sizeof(user.username) - 1] = '\0';

    strncpy(user.passwd, password_buffer, sizeof(user.passwd) - 1);
    user.passwd[sizeof(user.passwd) - 1] = '\0';
  }

  // if arguments are specified
  else {
  printf("Runnig with argument : %s\n", argv[2]);
  }
  return 0;
}
