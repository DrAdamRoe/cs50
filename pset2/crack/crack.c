//crack an inputed password, assuming it is DES hashed.

#include <stdio.h>

int main(int argc, char *argv[])
{

    // check for inputs as per specs
    if (argc != 2)
    {
        printf("expected 1 argument, you passed %i. Exiting \n", argc);
        return 1;
    }

    return 0;
}