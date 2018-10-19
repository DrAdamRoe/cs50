//crack an inputed password, assuming it is DES hashed.
#define _XOPEN_SOURCE

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <unistd.h>

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

    // generated password
    string password = "hello";
    printf("generated password: %s\n", password);

    string candidate; // hashed, generated passwored

    //encrypt
    candidate = crypt(password,salt);
    printf("candidate: %s\n", candidate);

    //check
    if (!strcmp(candidate,hash)){
        printf("winner! %s \n", candidate);
        return password;
    }

    return "uh oh.";
}
