//crack an inputed password, assuming it is DES hashed.
#define _XOPEN_SOURCE

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

string crack(string hash);

int main(int argc, char *argv[])
{

    // check for inputs as per specs
    if (argc != 2)
    {
        printf("expected 1 argument, you passed %i. Exiting \n", argc);
        return 1;
    }

    //the complete hash
    string hash = argv[1];

    string password = crack(hash);

    printf("%s\n", password);

    return 0;
}

string crack(string hash){

    printf("hash: %s\n", hash);

    //extract salt from hash
    char salt[3];
    strncpy(salt,hash,2);
    salt[2] = '\0';

    printf("salt: %s\n", salt);

    // -- hack --
    // create a random password (alphabetical, max 5 digits). Total of about 400k possibilities.

    //fill an array with all chars which are useable for the password
    const int n_chars = 53;

    char legit_chars[n_chars];
    //index for legit chars
    int placeholder = 0;
    for (int i = 0; i < 128; ++i){
        //if the character is alpahbetical, assign and count up.
        if (isalpha(i)){
            legit_chars[placeholder] = i;
            placeholder++;
        }
    }
    //add a null terminator as the last possible character


    legit_chars[n_chars-1] = '\0';

    printf("array: %s ", legit_chars);

    string candidate; // hashed, generated password. will be overwritten constantly
    char password[6] = {'\0'};


    //password = "hello";

    for (int i = 0; i < n_chars; ++i){
        password[0] = i;

        for (int j = 0; j < n_chars; ++j){
            password[1] = j;

            for (int k = 0; k < n_chars; ++k){
                password[2] = k;

                for (int l = 0; l < n_chars; ++l){
                    password[3] = l;

                    for (int m = 0; m < n_chars; ++m){
                        password[4] = m;

                        //encrypt
                        candidate = crypt(password,salt);

                        printf("generated password: %s\n", password);
                        printf("candidate: %s\n", candidate);

                        //check
                        if (!strcmp(candidate,hash)){
                            printf("winner! %s \n", candidate);
                            string ret = password;
                            return ret;
                        }


                    }
                }
            }
        }
    }




    return "uh oh.";
}
