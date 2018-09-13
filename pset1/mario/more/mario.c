#include <stdio.h>
#include <cs50.h>
#include <string.h>

int getHeight(); //forward declaration of input function

int main(void)
{

    //initialize number of hashtags on either side of the pyramid
    //doubles as the number of lines total. Defaults to 0.
    int n_hashtags = 0;

    //fixed value of blank spaces
    const int n_blanks_middle = 2;

    // get desired pyramid height from CLI
    n_hashtags = getHeight();

    //DEBUG
    //printf("Height: %i \n", getHeight());


    //main print loop.
    //
    //loop over lines
    for (int line = 1; line < n_hashtags+1; line++){

        //init printing variable on each line.
        char printme[49] = ""; // 23*2 (#) + 2 (blank) + 1 EOL

        //calculate number of leading blanks in front of first hastag.
        int leading_blanks = n_hashtags - line;

        //add a blank for each leading blank.
        for (int b = 0; b < leading_blanks; b++){
            strcat(printme," ");
        }

        //add a # for each line
        for (int h = 0; h < line; h++){
            strcat(printme,"#");
        }

        //add middle blanks
        for (int b = 0; b < n_blanks_middle; b++){
            strcat(printme," ");
        }

        //add a # for each line after the break.
        for (int h = 0; h < line; h++){
            strcat(printme,"#");
        }

        //whew, done concatenating.
        printf("%s\n", printme);
    }


}

int getHeight()
{

    //initilaize local variable to be out of desired range, forcing loop
    int pyr_h = -1;

    do
    {
        //get input from CLI
        pyr_h = get_int("Height: ");

         //DEBUG
        //printf("Height: %i \n", pyr_h);
    }
    while(pyr_h < 0 || pyr_h > 23);

    return pyr_h;
}
