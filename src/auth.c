#include <stdio.h>

#include "auth.h"
#include "crypto.h"
#include "vault.h"

int authentificate(char *password_buffer) { return 0; }

int create_user(char* username, char* password) {
  char encoded[ENCODED_LEN];

  // hash the password : encoded
  if (hash_password(password, encoded) != 0){
    printf("Error hashing the password\n");
  }
 
  // save user
  F_write("user.bin", username);
  F_write("user.bin", encoded);
  printf("User created and saved.\n");
  return 0;
}
