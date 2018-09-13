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

    //print company
    printCompany(card_string);


    //variable to hold sum of "even" digits
    int sum_even = 0;

    //TODO:
    // make loop over string return an array of ints.
    // double each value in the array
    // sum digits into a single number

    //print if position is odd, counting from the back.
    //reverse iterate on a string in C: https://stackoverflow.com/questions/20394387/string-reverse-with-loop-and-array-in-c
    for (int i =  strlen(card_string); i > 0 ; i--){
        if (i%2==0){
            printf("i:%i, c:%c \n",i,card_string[strlen(card_string)-i]);
        }
        // TODO: summing return ASCII values rn :/
    //    else{
    //        sum_even += card_string[strlen(card_string)-i];
    //    }
    }
    printf("sum even: %i", sum_even);
}

//covert lli to string
const char* lli_to_string(long long n, char* s){
    sprintf(s,"%lli",n);
    //printf("%s",s);
    return s;
}


//ugly code to find the card company.
void printCompany(char* s){

    char first = s[0];
    char second = s[1];
    int i_second = second - '0';


    switch (first){

        //Visa, easy.
        case '4':
        printf("Visa\n");
        break;

        //AmEx
        case '3':
            if ( second=='4' || second == '7'){
                printf("AMEX\n");
                break;
            }

        case '5':
            for (int i=1; i<6;i++){
                if ( i_second == i){
                    printf("MC\n");
                    break;
                }
            }
        }

    return;
}
