#include <stdio.h>
#include <cs50.h>
#include <string.h>

//function to convert long long int to string
const char* lli_to_string(long long n, char* s);
//function to print which credit card company the card is from
void printCompany(char* s);
//function to peel off every other didgit.

int main(void){

    //get cardnumber from user
    long long int cardnumber = get_long_long("Number: ");

    //string variable for card number
    char card_string[20];

    //covert lli to string
    lli_to_string(cardnumber, card_string);

    //variable to hold sum of "even" digits
    int sum = 0;

    char c_dig; // hold a single digit as char
    int i2_dig; // hold a single digit as int after being x2-ed

    int i_dig; // hold a single digit as int

    //print if position is odd, counting from the back.
    //reverse iterate on a string in C: https://stackoverflow.com/questions/20394387/string-reverse-with-loop-and-array-in-c

    for (int i =  strlen(card_string); i > 0 ; i--){
        if (i%2==0){
            // extract current character
            c_dig = card_string[strlen(card_string)-i];
            //char to int and multiply by 2
            i2_dig =  (c_dig - '0')*2;
            // debug: printf("i:%i, c:%c, int: %i, i2: %i \n",i,c_dig,c_dig-'0',i2_dig);

            // get digits, clean solution: https://stackoverflow.com/questions/3118490/getting-each-individual-digit-from-a-whole-integer
            int single_dig = 0;
            while (i2_dig){
                single_dig =  i2_dig % 10;
                // debug: printf("%i\n",single_dig);
                sum += single_dig;
                i2_dig /= 10;
            }
        }else{
            i_dig = (card_string[strlen(card_string)-i]) - '0';
            //debug: printf("digit:%i\n",i_dig);
            sum +=i_dig;
        }
    }
    //debug: printf("sum: %i\n", sum);
     if (sum % 10 != 0){
         printf("INVALID\n");
     }else{
        //print company
        printCompany(card_string);
     }

     return 0;
}

//covert lli to string
const char* lli_to_string(long long n, char* s){
    sprintf(s,"%lli",n);
    //printf("%s",s);
    return s;
}

//ugly code to find the card company.
void printCompany(char* s){

    //variables for first and second characters
    char first = s[0];
    char second = s[1];
    int i_second = second - '0';

    //length of credit card string
    int length = strlen(s);
    //debug: printf("length: %i\n", length);

    switch (first){

        //Visa, easy.
        case '4':
            if (length == 13 || length == 16){
                printf("VISA\n");
            }else{
                printf("INVALID\n");
            }
        break;

        //AmEx
        case '3':
            if (( second=='4' || second == '7') && length == 15){
                printf("AMEX\n");
            }else{
                printf("INVALID\n");
            }
            break;

        //MasterCard
        case '5':
            if (length == 16 && i_second > 0 && i_second < 6){
                printf("MASTERCARD\n");
            }else{
                printf("INVALID\n");
            }

            break;

        default:
         printf("INVALID\n");
        }


    return;
}
