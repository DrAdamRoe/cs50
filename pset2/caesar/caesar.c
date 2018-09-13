//an implementation of the caesar cypher

#include <stdio.h>
#include <cs50.h>
#include <string.h>

//Forward declare our advanced cypher
int alg(char _plaintext, int key);

int main(int argc, char *argv[])
{

    // check for inputs as per specs
    if (argc != 2)
    {
        printf("expected 1 argument, you passed %i. Exiting \n", argc);
        return 1;
    }

    // convert input to key. expects positive int. Not checking, as per specs.
    int key = atoi(argv[1]);

    // get message from user
    string plaintext = get_string("plaintext: ");

    // get message length for loop
    int plaintextLength = (int) strlen(plaintext);

    // begin printing cyphertext. Call the cypher letter by letter.
    printf("ciphertext: ");
    for (int c = 0; c < plaintextLength; c++)
    {
        printf("%c", alg(plaintext[c], key));
    }
    printf("\n");

    return 0;
}

//the cypher itself
int alg(char _plaintext, int key)
{

    //needed for wrap-arounds.
    int length_alphabet = 26;

    //stay within the alphabet
    int transform = (key % length_alphabet);

    //Initialize output variable.
    int cipher_char = -1;

    //identify captial letters (to be transformed)
    if (('A' <= _plaintext) && ('Z' >= _plaintext))
    {
        //perform transformation
        cipher_char = _plaintext + transform;

        //Find capital letters which spilled over, and correct
        if (cipher_char > 'Z')
        {
            cipher_char -= length_alphabet;
        }
    }

    //identify lower-case letters (to be transformed), and correct.
    else if (('a' <= _plaintext) && ('z' >= _plaintext))
    {
        cipher_char = _plaintext + transform;

        if (cipher_char > 'z')
        {
            cipher_char -= length_alphabet;
        }
    }
    //Handle non alphabetical characters
    else
    {
        cipher_char = _plaintext;
    }

    return cipher_char;
}