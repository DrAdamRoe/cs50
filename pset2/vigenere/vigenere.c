//an implementation of the caesar cypher

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>


//Forward declare our very advanced cypher
int verify_key(string key);

string cipher(string plaintext, string key);
int get_offset(char k);

int main(int argc, char *argv[])
{

    // check for inputs as per specs
    if (argc != 2)
    {
        printf("expected 1 argument, you passed %i. Exiting \n", argc);
        return 1;
    }

    string key = argv[1];

    //make sure we are dealing in UTF-8, neccesarry for using ctype library.
    setlocale(LC_ALL, "");

    //check if input is purely aplhapbetical. If not, exit with error code 1.
    if ( verify_key(key) == 1) {
        printf("key should only contain alphabetical characters. Key used: %s . Exiting \n", key);
        return 1;
    }

    // get message from user
    string plaintext = get_string("plaintext: ");

    //function to encrypt plaintext
    printf("ciphertext: %s\n", cipher(plaintext,key));

    return 0;
}

//verify input key. Returns 1 if there are any non-alphabetical charatecters, otherwise returns 0.
int verify_key(string key){
    int k = 0;

    while(key[k]){
        if (!isalpha(key[k])){
            return 1;
        }

        k++;
    }

    return 0;
}

string cipher(string plaintext, string key){
    //define ciphertext to be returned. initialize to 0.
    char *ciphertext = plaintext;
    //memset(ciphertext, '\0',sizeof(ciphertext));
    //strcpy(ciphertext, plaintext);
    printf("plain: %s, cipher: %s \n", plaintext, ciphertext);
    //index of key character to be used for encryption.
    int k = 0;
    //store length of key
    int keylength = strlen(key);

    //loop over letters in the text
    int plaintext_length = strlen(plaintext);

    for (int c=0; c < plaintext_length; c++){

        //if plain character is non-alphabetical, continue.
        if (!isalpha(plaintext[c])){
            //ciphertext[c] = plaintext[c];
            continue;
        }

        //if the character is alphabetical, transform it.

        //get transformation based on key
        int offset = get_offset(key[k]);
        //increment key
        k++;
        //reset index to 0 if we are otherwise going over.
        if (k == keylength){
            k=0;
        }
        //transform, preserving case.
        if isupper(plaintext[c]){
            if isupper(ciphertext[c]+offset){
                ciphertext[c] = plaintext[c] + offset;
            }else{
                ciphertext[c] = plaintext[c] + offset - 26;
            }
        }else{
            if islower(ciphertext[c]+offset){
                    ciphertext[c] = plaintext[c] + offset;
            }else{
                ciphertext[c] = plaintext[c] + offset - 26;
            }
        }

    }

    return ciphertext;
}

int get_offset(char k){
    //first make all characters capital, then subtract out to 0 according to spec
    k = toupper(k);
    return k-65;
}