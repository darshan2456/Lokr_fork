#include <stdio.h>
#include <string.h>

#include "auth.h"
#include "vault.h"
#include "crypto.h"

char password_buffer[50];

int main(int argc, char *argv[]) {
  if (F_exist("user.bin") != 0) {
    user_t user;

    // Takes user credential
    printf("please create a user.\n");
    printf("Username : ");
    fgets(user.username, sizeof(user.username), stdin);
    user.username[strcspn(user.username, "\n")] = '\0';

    printf("Password : ");
    fgets(user.passwd, sizeof(user.passwd), stdin);
    user.passwd[strcspn(user.passwd, "\n")] = '\0';
    create_user(user.username, user.passwd);
  }

  if (argc < 2) {
    printf("\n\nNo argument specififed running the CLI envirenment.\n");
    printf("Enter your password : ");
    fgets(password_buffer, sizeof(password_buffer), stdin);
    authentificate(password_buffer);
  } else {
    printf("Runnig with argument : %s\n", argv[2]);
  }

  return 0;
}
